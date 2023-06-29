
#include <stdint.h>
#include <inttypes.h>
#include <rte_eal.h>
#include <rte_ethdev.h>
#include <rte_cycles.h>
#include <rte_lcore.h>
#include <rte_mbuf.h>
#include <rte_config.h>


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define RX_RING_SIZE 1024
#define TX_RING_SIZE 1024

#define NUM_MBUFS 8191
#define MBUF_CACHE_SIZE 250
#define BURST_SIZE 32




static struct rte_eth_stats prev_app_stats[64];
static const struct rte_eth_conf port_conf_default = {
        .rxmode = {
                .max_rx_pkt_len = RTE_ETHER_MAX_LEN,
        }
};


struct cell_port_info {
    uint16_t port_id;
    uint16_t nb_send;
    uint16_t dst_port_id[RTE_MAX_ETHPORTS];
};
struct port_info {
    uint16_t nb_ports;
    struct cell_port_info port[RTE_MAX_ETHPORTS];
};


struct lcore_info {
    uint16_t nb_lcores;
    uint16_t lcore_id[RTE_MAX_LCORE];
};
static port_info s_port_info;
static lcore_info s_lcore_info;


#define PORT(i) (s_port_info.port[i])
#define PORT_NUM (s_port_info.nb_ports)
struct lcore_params {
    uint16_t port_id;
    uint16_t lcore_id;
    struct rte_mempool *rte_mempool;
};

static uint16_t app_port_num = 1;
static uint16_t app_lcore_num_per_port = 1;


static inline int
port_init( uint16_t port_id, struct rte_mempool *mbuf_pool)
{
    // set ether config
    struct rte_eth_conf port_conf = port_conf_default;
    const uint16_t rx_rings = app_lcore_num_per_port;
    const uint16_t tx_rings = app_lcore_num_per_port;
    uint16_t nb_rxd = RX_RING_SIZE;
    uint16_t nb_txd = TX_RING_SIZE;

    int rv;
    int q;

    struct rte_eth_dev_info dev_info;
    struct rte_eth_txconf txconf;

    if ( !rte_eth_dev_is_valid_port(port_id))
        return -1;

    rv = rte_eth_dev_info_get(port_id, &dev_info);
    if ( 0 != rv ) {
        printf("Error during getting device (port %u) info: %s\n",
               port_id,
               strerror(-rv) );
        return rv;
    }

    if ( dev_info.tx_offload_capa & DEV_TX_OFFLOAD_MBUF_FAST_FREE) {
        port_conf.txmode.offloads |=
                DEV_TX_OFFLOAD_MBUF_FAST_FREE;
    }

    /* Configure the Ethernet device */
    rv = rte_eth_dev_configure( port_id, rx_rings, tx_rings, &port_conf);
    if ( 0 != rv ) {
        return rv;
    }

    rv = rte_eth_dev_adjust_nb_rx_tx_desc( port_id, &nb_rxd, &nb_txd);
    if ( 0 != rv) {
        return rv;
    }

    /* Allocate and set up 1 Rx queue per Ethernet port */
    for ( q = 0; q < rx_rings; ++q) {
        rv = rte_eth_rx_queue_setup(port_id, q, nb_rxd,
                                    rte_eth_dev_socket_id(port_id),
                                    NULL,
                                    mbuf_pool);
        if ( rv < 0) {
            return rv;
        }
    }

    txconf = dev_info.default_txconf;
    txconf.offloads = port_conf.txmode.offloads;

    /* Allocate and set up 1 TX queue per Ethernet port. */
    for ( q = 0; q < tx_rings; ++q) {
        rv = rte_eth_tx_queue_setup( port_id, q, nb_txd,
                                     rte_eth_dev_socket_id(port_id),
                                     &txconf);
        if ( rv < 0 ) {
            return rv;
        }
    }

    /* Start the Ethernet port */
    rv = rte_eth_dev_start(port_id);
    if ( rv < 0) {
        return rv;
    }

    /* Display the port MAC address*/
    struct rte_ether_addr addr;
    rv = rte_eth_macaddr_get(port_id, &addr);
    if ( rv != 0 ) {
        return rv;
    }

    printf("Port %u: MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           port_id,
           addr.addr_bytes[0], addr.addr_bytes[1],
           addr.addr_bytes[2], addr.addr_bytes[3],
           addr.addr_bytes[4], addr.addr_bytes[5]);

    /* Enable RX in promiscuous mode for the Ethernet device */
    rv = rte_eth_promiscuous_enable(port_id);
    if ( rv < 0 ){
        return rv;
    }
    return 0;
}

static void lcore_launch_one_core(void *dummy)
{

}

static inline
int lcore_worker(struct lcore_params *lcore_params)
{

    // struct lcore_params *lcore_params = (struct lcore_params *) args;
    struct rte_mbuf * rx_buf[BURST_SIZE];
    struct rte_mbuf * tx_buf[BURST_SIZE];

    uint16_t port_id = lcore_params->port_id;
    uint16_t lcore_id = lcore_params->lcore_id;

    uint16_t dev_port_id = PORT(port_id).port_id;
    uint16_t dev_to_port_id = PORT(port_id).dst_port_id[0];

    uint16_t rx_tx_queue_id =  lcore_id % app_lcore_num_per_port;

    printf("logical port %u, dev port: %u, to_dev_port: %u\n", port_id, dev_port_id, dev_to_port_id);
    printf("tx_queue_id: %u\n", rx_tx_queue_id);

    uint16_t nb_rx;
    uint16_t nb_tx;

    for ( ; ; )
    {
        nb_rx = rte_eth_rx_burst(dev_port_id, rx_tx_queue_id, rx_buf, BURST_SIZE);

        if ( unlikely( 0 == nb_rx) ) {
            continue;
        }

        nb_tx = rte_eth_tx_burst(dev_to_port_id, rx_tx_queue_id, rx_buf, nb_rx);

        if ( unlikely( nb_tx < nb_rx) ) {
            for (uint16_t i = nb_tx;  i < nb_rx ; ++i)
                rte_pktmbuf_free(rx_buf[i]);
        }
    }

    return 0;
}






void port_info() {
    // available ports
    uint16_t  avail_nb_ports = rte_eth_dev_count_avail();
    // total ports
    uint16_t  total_nb_ports = rte_eth_dev_count_total();

    printf("total ports: %u, available ports: %u", total_nb_ports, avail_nb_ports);

}

void even_port_check()
{
    uint16_t nb_avail_ports = rte_eth_dev_count_avail();
    if ( nb_avail_ports & 1) {
        printf("WARNING: Odd Number Ports\n");
    }
}

void print_ports()
{
    uint16_t port_id;
    struct rte_eth_stats eth_stats[64];

    for ( int i = 0; i < app_port_num; ++i) {
        port_id = s_port_info.port[i].port_id;
        rte_eth_stats_get(port_id, &eth_stats[port_id]);

        printf("port %d\t", i);

        printf("Rx Total: %ld,", eth_stats[port_id].ipackets - prev_app_stats[port_id].ipackets);
        printf("Rx Dropped: %ld,", eth_stats[port_id].imissed - prev_app_stats[port_id].imissed);
        printf("Rx error: %ld,", eth_stats[port_id].ierrors - prev_app_stats[port_id].ierrors);
        printf("Rx Byte Rate: %ld Mps,\t",
               (eth_stats[port_id].ibytes - prev_app_stats[port_id].ibytes)/1000000 /30);
        printf("Rx Packet Rate: %ld Kpps\n\n",
               (eth_stats[port_id].ipackets - prev_app_stats[port_id].ipackets) / 1000 / 30 );


        printf("Tx Total: %ld,", eth_stats[port_id].opackets - prev_app_stats[port_id].opackets);
        printf("Tx error: %ld,", eth_stats[port_id].oerrors - prev_app_stats[port_id].oerrors);
        printf("Tx Byte Rate: %ld Mps\t",
               (eth_stats[port_id].obytes - prev_app_stats[port_id].obytes)/1000000/30);
        printf("Tx Packet Rate: %ld Kpps\n\n",
               (eth_stats[port_id].opackets - prev_app_stats[port_id].opackets) / 1000/30);


        rte_memcpy(&prev_app_stats[port_id], &eth_stats[port_id], sizeof(eth_stats[port_id]));

    }

}
static void
port_set(void)
{

    uint16_t nb_ports = s_port_info.nb_ports;
    for ( int i = 0; i < nb_ports; ++i) {
        if ( i % 2) {
            PORT(i).dst_port_id[0] = PORT(i - 1).port_id;
            PORT(i).nb_send = 1;
        }
        else {
            int idx = i;
            if ( i + 1 != nb_ports)
                ++idx;
            PORT(i).dst_port_id[0] = PORT(idx).port_id;
            PORT(i).nb_send = 1;
        }
    }
}

void parse_arg(int argc, char *argv[]) {

    if ( argc != 3) {

        for ( int i = 0; i < argc; ++i) {
            printf("%s\t", argv[i]);
        }

        printf("\nusage: ./<prog-name>:  <port_num> <lcore_num_per_port>");
        exit(EXIT_FAILURE);
    }
    char *end;

    app_port_num = (uint16_t) strtol(argv[1], &end, 10);
    end = NULL;

    app_lcore_num_per_port = (uint16_t) strtol(argv[2], &end, 10);
}

void test_parse_arg()
{
    if ( app_lcore_num_per_port == 0 || app_port_num == 0) {
        fprintf(stderr, "parse failed!!!\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("request_port_num: %u, lcores_per_port: %u", app_port_num, app_lcore_num_per_port);
    }

}



int main( int argc, char *argv[])
{

    int rv = 0;
    struct rte_mempool *mbuf_pool;

    uint16_t enabled_port_mask;
    uint16_t portid;
    uint16_t nb_ports;
    uint16_t nb_lcores;

    int ret = rte_eal_init( argc, argv);
    if ( ret < 0 ) {
        rte_exit(EXIT_FAILURE, "Error with EAL initialization\n");
    }
    argc -= ret;
    argv += ret;



    port_info();
    nb_ports = rte_eth_dev_count_avail();
    nb_lcores = rte_lcore_count();
    printf("total lcores: %u\n", nb_lcores);

    uint16_t lcoreid;
    uint16_t lcore_it = 0;
    RTE_LCORE_FOREACH_SLAVE(lcoreid)
    {
        if ( !rte_lcore_is_enabled(lcoreid))
            continue;
        s_lcore_info.lcore_id[s_lcore_info.nb_lcores++] = lcoreid;

        ++lcore_it;
    }

    parse_arg(argc, argv);
    test_parse_arg();
    port_set();

    uint16_t nb_request_lcores = app_port_num * app_lcore_num_per_port;
    if ( app_port_num > nb_ports) {
        fprintf(stderr, "no enough ports\n");
        exit(EXIT_FAILURE);
    }
    if ( app_lcore_num_per_port * app_port_num > s_lcore_info.nb_lcores) {
        fprintf(stderr, "no enough lcores\n");
        exit(EXIT_FAILURE);
    }


    mbuf_pool = rte_pktmbuf_pool_create("MBUF_POOL", NUM_MBUFS * nb_ports,
                                        MBUF_CACHE_SIZE, 0, RTE_MBUF_DEFAULT_BUF_SIZE, rte_socket_id());
    if ( NULL == mbuf_pool ) {
        rte_exit(EXIT_FAILURE, "Cannot create mbuf pool\n");
    }



    s_port_info.nb_ports = 0;
    uint16_t port_cnt = 0;

    RTE_ETH_FOREACH_DEV(portid)
    {
        if (PORT_NUM >= app_port_num)
            break;

        PORT(port_cnt).port_id = portid;



        if ( port_init(portid, mbuf_pool) != 0) {
            rte_exit(EXIT_FAILURE, "Cannot init port %u", portid);
        }

        PORT_NUM++;

        printf("port_init: %u success\n", portid);
    }


    struct lcore_params lcore_params;
    lcore_params.rte_mempool = mbuf_pool;

    uint16_t port_it = 0;
    for (int i = 0; i < nb_request_lcores; ++i) {
        lcore_params.port_id = port_it;
        lcore_params.lcore_id = i;

        rv = rte_eal_remote_launch((lcore_function_t *) lcore_worker, (void *) &lcore_params, s_lcore_info.lcore_id[i]);
        if ( 0 != rv ) {
            rte_exit(EXIT_FAILURE, "cannot launch lcore %u\n", s_lcore_info.lcore_id[i]);
        }

        if ( (i + 1) % app_lcore_num_per_port == 0)
            port_it++;
    }


    printf("\nhere\n");




    for ( ; ; ) {
        sleep(30);
        print_ports();
    }

    for (int i = 0; i < nb_request_lcores; ++i ) {
        ret |= rte_eal_wait_lcore( s_lcore_info.lcore_id[i]);
    }

    rte_eal_cleanup();

    return ret;
}

//
// Created by xOx on 2023/7/4.
//

#include "pktHandler.h"





const uint8_t  * shift_to_ip(const uint8_t *data_ptr, uint16_t *eth_len)
{
    const struct lt_ethhdr *eth_hdr = (const struct lt_ethhdr *) data_ptr;

    const uint8_t *cur = data_ptr + 12;

    *eth_len += 12;
    while (1)
    {
        uint16_t eth_type = ntohs( *(uint16_t *) cur) ;
        switch (eth_type)
        {
            case ETH_P_8021Q:
            case ETH_P_QINQ1:
            case ETH_P_QINQ2:
            case ETH_P_QINQ3:
                cur += 4;
                *eth_len += 14;
                break;
            case ETH_P_IP:
                cur += 2;
                *eth_len += 2;
                return cur;
            default:
                *eth_len += 2;
                return NULL;
        }
    }

}






void pkt_handler(u_char *args, const struct pcap_pkthdr *pcap_pkt_hdr, const u_char *packet)
{
    uint16_t data_len = 0;
    const u_char *pkt_hdr = packet;


    uint16_t eth_layer_len = 0;

    packet = shift_to_ip(packet, &eth_layer_len);

    if (!packet)
        return ;

    const struct lt_iphdr *ip_hdr = ( const struct lt_iphdr *) packet;
    uint16_t ip_hdr_len = ip_hdr->ihl << 2;
    uint8_t ip_type = ip_hdr->protocol;
    data_len = ip_hdr->total_length + 14;

    print_ip_addr(ip_hdr);

    if ( ip_type != IPPROTO_TCP && ip_type != IPPROTO_UDP)
        return;
    packet += ip_hdr_len;

    uint16_t dport;
    uint16_t sport;

    uint16_t tran_layer_len = 0;
    if ( ip_type == IPPROTO_UDP) {
        const struct lt_udphdr * udp_hdr = (const struct lt_udphdr *) packet;
        uint16_t udp_hdr_len = 8;
        uint16_t udp_tot_len = udp_hdr->length;
        tran_layer_len = udp_hdr_len;

        dport = ntohs(udp_hdr->u_dport);
        print_port(udp_hdr, IPPROTO_UDP);
    }
    else {
        const struct lt_tcphdr *tcp_hdr = (const struct  lt_tcphdr *) packet;
        uint16_t tcp_hdr_len = tcp_hdr->data_offset << 2;
        tran_layer_len  = tcp_hdr_len;

        dport = ntohs(tcp_hdr->t_dport);
        print_port(tcp_hdr, IPPROTO_TCP);
    }
    packet += tran_layer_len;

    const u_char *payload_ptr = packet ;
    uint16_t payload_len = data_len - eth_layer_len - ip_hdr_len - tran_layer_len;


}



void print_ip_addr( const struct lt_iphdr *ip_hdr)
{
    struct in_addr  s_addr;
    struct in_addr  d_addr;
    s_addr.s_addr = ip_hdr->src_ip;
    d_addr.s_addr = ip_hdr->dst_ip;

    printf("destination ip: %s, ", inet_ntoa(d_addr));
    printf(" source ip: %s\n"   ,  inet_ntoa(s_addr) );

    // printf("destination ip: %s, source ip: %s\n", inet_ntoa(d_addr), inet_ntoa(s_addr) );
}


void print_port(const void *toru_hdr, uint8_t proto)
{
    if ( proto != IPPROTO_UDP && proto != IPPROTO_TCP)
        return ;

    uint16_t dport;
    uint16_t sport;
    if (proto == IPPROTO_TCP) {

        const struct lt_tcphdr *tcp_hdr = (const struct lt_tcphdr *) toru_hdr;
        dport = ntohs(tcp_hdr->t_dport);
        sport = ntohs(tcp_hdr->t_sport);
    }
    else {
        const struct lt_udphdr *udp_hdr = (const struct lt_udphdr *) toru_hdr;
        dport = ntohs(udp_hdr->u_dport);
        sport = ntohs(udp_hdr->u_sport);
    }

    printf("dst port: %u, src port: %u\n", dport, sport);
}





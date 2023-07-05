#include <iostream>
#include <pcap.h>


#include <stdlib.h>

#include <ctype.h>

#include "ProtoHeader.h"
#include "pktHandler.h"

#include "lt_debug.h"



uint32_t pkt_cnt = 0;

int main( int argc, char *argv[])
{

#if __BYTE_ORDER == __LITTLE_ENDIAN

#endif


    if ( argc != 2)
    {
        print_cmd_arg(argc, argv);
        printf("usage:./%s <pcap_file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char err_buf[256];

    pcap_t *p_handle;
    p_handle = pcap_open_offline( argv[1], err_buf);
    if ( NULL == p_handle) {
        fprintf( stderr, "can not open file %s: %s", argv[1], err_buf);
        exit(EXIT_FAILURE);
    }


    pcap_loop( p_handle, -1, pkt_handler, NULL);
    pcap_close(p_handle);

    return 0;
}

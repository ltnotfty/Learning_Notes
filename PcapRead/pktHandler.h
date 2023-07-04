//
// Created by xOx on 2023/7/4.
//

#ifndef PCAPREAD_PKTHANDLER_H
#define PCAPREAD_PKTHANDLER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ether.h>

#include "ProtoHeader.h"




void pkt_handler(u_char *args, const struct pcap_pkthdr *pcap_pkt_hdr, const u_char *packet);
void print_ip_addr( const struct lt_iphdr *);
void print_port(const void *toru_hdr, uint8_t proto);

const uint8_t  * shift_to_ip(const uint8_t *data_ptr, uint16_t *eth_layer_len);
#endif //PCAPREAD_PKTHANDLER_H

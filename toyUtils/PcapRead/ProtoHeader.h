//
// Created by xOx on 2023/7/4.
//

#ifndef PCAPREAD_PROTOHEADER_H
#define PCAPREAD_PROTOHEADER_H

#include <stdint.h>

#define ETH_ADDR_LEN 6

struct lt_ethhdr
{
    uint8_t dst_mac[ETH_ADDR_LEN];
    uint8_t src_mac[ETH_ADDR_LEN];
    uint16_t eth_type;
}__attribute__((packed));

struct lt_iphdr
{
#if __BYTE_ORDER == __BIG_ENDIAN
uint8_t ip_v:4;
uint8_t ihl:4;
#else
uint8_t ihl:4;
uint8_t ip_v:4;
#endif
uint8_t tos; // type of service

uint16_t total_length;

uint16_t identifier;

#if __BYTE_ORDER == __BIG_ENDIAN
uint16_t rsvd: 1;
uint16_t DF:1; // 0 = May Fragment, 1 = Don't Fragment.
uint16_t MF:1; // 0 = Last Fragment, 1 = More Fragment
uint16_t frag_offset:13;
#else
uint16_t frag_offset:13;
uint16_t MF:1;
uint16_t DF:1;
uint16_t rsvd:1;
#endif

uint8_t ttl;
uint8_t protocol;
uint16_t header_checksum;

uint32_t src_ip;
uint32_t dst_ip;
uint32_t padding[0];
};

struct lt_tcphdr
{
    uint16_t t_sport;
    uint16_t t_dport;
    uint32_t seq;
    uint32_t ack;

#if __BYTE_ORDER == __BIG_ENDIAN
    uint16_t data_offset:4;
    uint16_t rsrvd:4;
    uint16_t CWR:1;
    uint16_t ECE:1;
    uint16_t URG:1;
    uint16_t ACK:1;
    uint16_t PSH:1;
    uint16_t PST:1;
    uint16_t SYN:1;
    uint16_t FIN:1;
#else
uint16_t FIN:1;
uint16_t SYN:1;
uint16_t RST:1;
uint16_t PSH:1;
uint16_t ACK:1;
uint16_t URG:1;
uint16_t ECE:1;
uint16_t CWR:1;
uint16_t rsrvd:4;
uint16_t data_offset:4;
#endif
    uint16_t window;
    uint16_t check_sum;
    uint16_t urg_ptr;
    uint32_t padding[0];
} __attribute__((packed));

struct lt_udphdr {
    uint16_t u_sport;
    uint16_t u_dport;
    uint16_t length;
    uint16_t check_sum;
}__attribute__((packed));


struct lt_vlan {
    uint16_t proto_type;
#if  __BYTE_ORDER == __BIG_ENDIAN
    uint16_t pri:3;
    uint16_t cfi:1;
    uint16_t vlan_id:12;
#else
    uint16_t vlan_id:12;
    uint16_t cfi:1;
    uint16_t pri:3;
#endif
}__attribute__((packed));


#endif //PCAPREAD_PROTOHEADER_H

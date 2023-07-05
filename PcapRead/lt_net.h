//
// Created by xOx on 2023/7/5.
//

#ifndef PCAPREAD_LT_NET_H
#define PCAPREAD_LT_NET_H
#include <stdio.h>
#include <stdint.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


static uint32_t ipv4_str_to_net_addr(const char *ip_str);

static const char *net_addr_to_ipv4_str(uint32_t in_addr);

static const char *uint32_to_hex_byte_str(uint32_t val);

char to_hex_char(int c);



#endif //PCAPREAD_LT_NET_H

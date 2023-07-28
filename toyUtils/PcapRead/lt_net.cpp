//
// Created by xOx on 2023/7/5.
//

#include "lt_net.h"


uint32_t ipv4_str_to_net_addr(const char *ip_str)
{
    return inet_addr(ip_str);
}


const char *net_addr_to_ipv4_str(uint32_t in_addr)
{
    static char s_ip_str[16];
    s_ip_str[0] = '\0';
    uint8_t offset = 0;

    uint8_t byte_val[4];
    *(uint32_t *) byte_val = in_addr;

    for ( int i = 0; i < 4; ++i ) {

        char byte_str[3];
        uint8_t byte_str_offset = 0;

        if (byte_val[i] == 0)
            byte_str[byte_str_offset++] = '0';
        while ( byte_val[i] ) {
            byte_str[byte_str_offset++] = '0' + byte_val[i] % 10;
            byte_val[i] /= 10;
        }

        for (int j = byte_str_offset - 1; j > -1;--j)
            s_ip_str[offset++] = byte_str[j];

        if ( i + 1 != 4)
            s_ip_str[offset++] = '.';
        else
            s_ip_str[offset++] = '\0';
    }

    return s_ip_str;
}



static const char *uint32_to_hex_byte_str(uint32_t val)
{
    static char hex_byte_str[9];
    uint8_t offset = 0;

    uint8_t byte_val[4];
    *(uint32_t *) byte_val = val;

    for ( int i = 0; i < 4; ++i ) {

        hex_byte_str[offset++] = to_hex_char(byte_val[i] / 16);
        hex_byte_str[offset++] = to_hex_char(byte_val[i] % 16);
    }
    hex_byte_str[8] = '\0';

    return hex_byte_str;
}

char to_hex_char(int c)
{
    if ( c  < 10)
        return c + '0';
    if ( c < 16 )
        return c - 10 + 'a';

    return 0;
}


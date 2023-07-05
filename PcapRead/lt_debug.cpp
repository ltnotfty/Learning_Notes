//
// Created by xOx on 2023/7/4.
//

#include "lt_debug.h"


void print_cmd_arg(int argc, char *const *argv)
{
    LT_DEBUG_HEAD;

    for ( int i = 0; i < argc; ++i) {
        if ( i )
            printf("\t");
        printf("%s", argv[i]);
    }
    printf("\n");

    LT_DEBUG_TAIL;
}


void dump_data_hex(const uint8_t* data_ptr, uint16_t data_len )
{

    for ( int i = 0; i < data_len; ++i) {

        printf("%02x", data_ptr[i]);

        if ( i % 16 == 0 && i) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }
}


//
// Created by xOx on 2023/7/4.
//

#ifndef PCAPREAD_LT_DEBUG_H
#define PCAPREAD_LT_DEBUG_H

#include <stdint.h>
#define LT_DEBUG_HEAD do \
                       { printf("LT_DEBUG-----------\n"); } \
                       while(0)
#define LT_DEBUG_TAIL do { \
printf("----------------END\n"); \
} while (0)

#include <stdio.h>

void print_cmd_arg(int argc, char *const *argv);

void dump_data_hex(const uint8_t* data_ptr, uint16_t data_len );
#endif //PCAPREAD_LT_DEBUG_H

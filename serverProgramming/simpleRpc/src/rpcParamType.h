//
// Created by xOx on 2023/6/13.
//

#ifndef SIMPLERPC_RPCVALTYPE_H
#define SIMPLERPC_RPCVALTYPE_H
#include <stdint.h>


#define MAGIC_NUMBER_TAIL 0x59

enum rpcParamType
{
    rpc_void_type = 0,
    rpc_char_type,
    rpc_uchar_type,
    rpc_short_type,
    rpc_ushort_type,
    rpc_int_type,
    rpc_uint_type,
    rpc_long_type,
    rpc_ulong_type,
    rpc_float_type,
    rpc_double_type,
    rpc_invalid_type = 15,
};


uint8_t getRpcTypeLen(enum rpcParamType a);

bool IsIntegerType(enum rpcParamType a);

bool IsFloatType(enum rpcParamType a);

#endif //SIMPLERPC_RPCVALTYPE_H

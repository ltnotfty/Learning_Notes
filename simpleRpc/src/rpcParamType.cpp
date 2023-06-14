//
// Created by xOx on 2023/6/13.
//

#include "rpcParamType.h"


uint8_t getRpcTypeLen(enum rpcParamType a)
{
    switch (a)
    {
        case rpc_char_type:
        case rpc_uchar_type:
            return sizeof(char);

        case rpc_short_type:
        case rpc_ushort_type:
            return sizeof(short);

        case rpc_int_type:
        case rpc_uint_type:
            return sizeof(int);

        case rpc_float_type:
            return sizeof(float );

        case rpc_double_type:
            return sizeof(double);

        default:
            return 0;
    }

}


bool IsIntegerType(enum rpcParamType a)
{
    switch ( a )
    {
        case rpc_char_type:
        case rpc_uchar_type:
        case rpc_short_type:
        case rpc_ushort_type:
        case rpc_int_type:
        case rpc_uint_type:
            return true;
        default:
            return false;
    }
}


bool IsFloatType(enum rpcParamType a)
{
    switch ( a )
    {
        case rpc_float_type:
        case rpc_double_type:
            return true;
        default:
            return false;
    }
}

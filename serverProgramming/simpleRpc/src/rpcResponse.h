//
// Created by xOx on 2023/6/13.
//

#ifndef SIMPLERPC_RPCRESPONSE_H
#define SIMPLERPC_RPCRESPONSE_H

#include <stdint.h>
#include "rpcParam.h"


enum rpcResponseCode
{
    rpc_msg_ok = 0,
    rpc_func_not_exist,
    rpc_packet_error,
    rpc_invalid = 7
};
struct rpcResponse
{
    enum rpcResponseCode code;
    rpcParam param;
}__attribute((__packed__));




bool getResult(const struct rpcResponse *response, void *val);

bool unpack(const char *data, struct rpcResponse *response);

void pack(char *data, const struct rpcResponse *response);


#endif //SIMPLERPC_RPCRESPONSE_H

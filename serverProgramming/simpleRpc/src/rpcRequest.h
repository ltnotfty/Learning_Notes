//
// Created by xOx on 2023/6/13.
//

#ifndef SIMPLERPC_RPCREQUEST_H
#define SIMPLERPC_RPCREQUEST_H

#include <stdint.h>
#include "rpcParam.h"

struct rpcRequest
{
    uint8_t len;
    char rqsFunName[50];
    uint8_t paramLen;
    rpcParam *param;
}__attribute__( (packed));


void pack(const struct rpcRequest *request, char *data);

bool unpack(const char *data, struct rpcRequest *request);

bool getParam(const struct rpcRequest *request, uint8_t idx, void *val);


#endif //SIMPLERPC_RPCREQUEST_H

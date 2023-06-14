//
// Created by xOx on 2023/6/13.
//

#ifndef SIMPLERPC_RPCREQUEST_H
#define SIMPLERPC_RPCREQUEST_H

#include <stdint.h>
#include "rpcParam.h"

struct rpcRequest
{
    uint16_t requestMsgLen;
    uint8_t len;
    char rqsFunName[0];
    uint8_t paramLen;
    rpcParam param[0];
    uint8_t magicNum;
};



#endif //SIMPLERPC_RPCREQUEST_H

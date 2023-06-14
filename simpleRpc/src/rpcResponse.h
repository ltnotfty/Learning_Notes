//
// Created by xOx on 2023/6/13.
//

#ifndef SIMPLERPC_RPCRESPONSE_H
#define SIMPLERPC_RPCRESPONSE_H

#include <stdint.h>



struct rpcResponse
{
    uint16_t msgLen;

}__attribute((__packed__));


#endif //SIMPLERPC_RPCRESPONSE_H

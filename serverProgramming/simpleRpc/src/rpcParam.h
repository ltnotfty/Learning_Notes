//
// Created by xOx on 2023/6/13.
//

#ifndef SIMPLERPC_RPCTYPEVALUE_H
#define SIMPLERPC_RPCTYPEVALUE_H

#include "rpcParamType.h"

struct rpcParam
{
    enum rpcParamType paramType;
    union rpcParamVal
    {
        char  _1B;
        short _2B;
        int   _4B;
        long  _8B;
    };

}__attribute((__packed__));

/** @brief: get val from rpcaParam ptr, and return if success get
 */
bool getValOf(struct rpcParam *param,enum rpcParamType type,void *val);


#endif //SIMPLERPC_RPCTYPEVALUE_H

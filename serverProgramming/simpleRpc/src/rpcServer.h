//
// Created by xOx on 2023/6/13.
//

#ifndef SIMPLERPC_RPCSERVER_H
#define SIMPLERPC_RPCSERVER_H

#include <netinet/in.h>
#include <sys/socket.h>
#include <stdint.h>

#define SERVER_RECV_BUFLEN 1024
#define SERVER_SEND_BUFLEN 1024

const static char * callName[4] = {
        "add",
        "printTest"
        "isPrime",
        "noisyFun"
};

struct rpcServer
{

    int srvFd;
    int cliFd;
    struct sockaddr_in srvAddr;
    struct sockaddr_in cliAddr;
    char sSendBuf[SERVER_SEND_BUFLEN];
    char sRecvBuf[SERVER_RECV_BUFLEN];

};

void openSocket(struct rpcServer *rpcSrv);

int bindAddr(struct rpcServer *rpcSrv,const char *ipStr, uint16_t bindPort);

void acceptConnection(struct  rpcServer *rpcSrv);

void closeConnection(struct  rpcServer *rpcSrv);

bool haveCallOf(const char *funName,uint8_t funNameLen);


void handleRequest(struct rpcServer *rpcServer);

void sendResponse(struct rpcServer *rpcServer);

void recvInfo(struct rpcServer *rpcSrv);

void sendInfo(struct rpcServer *rpcSrv, const char *s, uint16_t len);

void closeSocket(struct rpcServer *rpcSrv);


#endif //SIMPLERPC_RPCSERVER_H

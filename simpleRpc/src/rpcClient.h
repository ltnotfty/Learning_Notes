//
// Created by xOx on 2023/6/13.
//

#ifndef SIMPLERPC_RPCCLIENT_H
#define SIMPLERPC_RPCCLIENT_H

#include <netinet/in.h>
#include <sys/socket.h>


#define CLI_SENDBUF_LEN 1024
#define CLI_RECVBUF_LEN 1024
struct rpcClient
{

    int cliFd;
    struct sockaddr_in inAddr;
    char sendBuf[CLI_RECVBUF_LEN];
    char recvBuf[CLI_SENDBUF_LEN];
    uint16_t sBufLen;
    uint16_t rBufLen;

};

void openSocket(struct rpcClient *);

int connectTo(struct rpcClient,char *str, uint16_t srvPort);


void packRequest();

int sendInfo(struct rpcClient *, char *str, uint16_t sendLen);

int recvInfo(struct rpcClient *);

void unpackResponse();

void closeConnection(struct rpcClient *);


#endif //SIMPLERPC_RPCCLIENT_H

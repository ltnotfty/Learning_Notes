//
// Created by xOx on 2023/7/4.
//

#ifndef PCAPREAD_RADIUSINFO_H
#define PCAPREAD_RADIUSINFO_H
#include <stdint.h>
#include <arpa/inet.h>

#define AUTHENTICATOR_LENGTH 16


enum radius_code_type
{
    ACCESS_REQUEST = 1,
    ACCESS_ACCEPT,
    ACCESS_REJECT,
    ACCOUNTING_REQUEST,
    ACCOUNTING_RESPONSE,
    ACCESS_CHALLENGE=11,
    STATUS_SERVER,
    STATUS_CLIENT,
    RESERVED=255
};

enum radius_attr_type
{
    USER_NAME,
    USER_PASSWORD,
    CHAP_PASSWORD,
    NAS_IP_ADDRESS,
    NAS_PORT,
    SERVICE_TYPE,
    FRAMED_PROTOCOL,
    FRAMED_IP_ADDRESS,
    FRAMED_IP_NETMASK,
    FRAMED_ROUTING,
    FILTER_ID,
    FRAMED_MTU,
    FRAME_COMPRESSION,
    LOGIN_IP_HOST,
    LOGIN_SERVICE,
    LOGIN_TCP_PORT,
    REPLY_MESSAGE=18,
    CALLBACK_NUMBER,
    CALLBACK_ID,
    FRAMED_ROUTE = 22,
    FRAMED_IPX_NETWORK,
    STATE,
    CLASS,
    VENDOR_SPECIFIC,
    SESSION_TIMEOUT,
    IDLE_TIMEOUT,
    TERMINATION_ACTION,
    CALLED_STATION_ID,
    CALLING_STATION_ID,
    NAS_IDENTIFIER,
    PROXY_STATE,
    LOGIN_LAT_SERVICE,
    LOGIN_LAT_NODE,
    LOGIN_LAT_GROUP,
    FRAMED_APPLETALK_LINK,
    FRAMED_APPLETALK_NETWORK,
    FRAMED_APPLETALK_ZONE,
    CHAP_CHALLENGE = 60,
    NAS_PORT_TYPE,
    PORT_LIMIT,
    LOGIN_LAT_PORT = 63
};

struct radius_attr
{
    uint8_t type;
    uint8_t length;
    uint8_t value[0];
}__attribute__((packed));

struct radius_hdr
{
    uint8_t code;
    uint8_t identifier;
    uint16_t length;
    uint8_t auth[AUTHENTICATOR_LENGTH];
    struct radius_attr attr[0];
}__attribute__((packed));

struct radius_info
{

    uint16_t port_start;
    uint16_t port_end  ;
#define HAVE_PUBLIC_IP (public_ip[0] != '\0')
    char framed_ip[16];
    char public_ip[16];
    char user_name[64];
};


void parse_radius_hdr(const uint8_t *data, uint16_t data_len);
void parse_radius_attr(const struct radius_attr *, uint16_t length);


void init_radius_info(struct radius_info *radius_info);


#endif //PCAPREAD_RADIUSINFO_H

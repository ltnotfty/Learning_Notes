//
// Created by xOx on 2023/7/4.
//

#ifndef PCAPREAD_RADIUSINFO_H
#define PCAPREAD_RADIUSINFO_H
#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>


#include "lt_debug.h"
#include "lt_net.h"
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


enum radius_vendor_type
{
    VENDOR_HUAWEI = 0x07db,
    VENDOR_H3C = 0x63a2,
    VENDOR_CHINA_TELECOM = 0x51ce
};

enum radius_huawei_vendor_type
{

    HUAWEI_PUBLIC_IP = 161,
    HUAWEI_PORT_START ,
    HUAWEI_PORT_END
};
enum radius_h3c_vendor_type
{
    H3C_PUBLIC_IP = 32,
    H3C_PORT_START,
    H3C_PORT_END,
    H3C_INFO_PARSE = 121,
};
enum radius_telecom_vendor_type
{
    TELECOM_PUBLIC_IP,
    TELECOM_PORT_START,
    TELECOM_PORT_END,
    TELECOM_INFO_PARSE = 121,
};


enum radius_attr_type
{
    USER_NAME = 1,
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

struct packet_tlv
{
    uint8_t type;
    uint8_t length;
    uint8_t value[0];
} __attribute__((packed));


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
#define HAVE_PUBLIC_IP public_ip[0] != '\0'
#define HAVE_FRAMED_IP framed_ip[0] != '\0'
#define HAVE_USER_NAME user_name[0] != '\0'
    char framed_ip[16];
    char public_ip[16];
    char user_name[64];
};


void parse_radius_hdr(const uint8_t *data, uint16_t data_len);
void parse_radius_attr(struct radius_info *,const uint8_t *data, uint16_t length);


void init_radius_info(struct radius_info *radius_info);

bool parse_huawei_vsa(struct radius_info *, const uint8_t *data_ptr, uint16_t data_length);

bool parse_h3c_vsa(const uint8_t *data_ptr, uint16_t data_length );

bool parse_telecom_vsa(const uint8_t *data_ptr, uint16_t data_length );

void radius_get_public_ip_str(struct radius_info *radius_info, const uint8_t *data);

void radius_get_framed_ip_str(struct radius_info *radius_info, const uint8_t *data);
void radius_get_port_start(struct radius_info *radius_info, const uint8_t *data);

void radius_get_port_end(struct radius_info *radius_info, const uint8_t *data);

void radius_get_user_name(struct radius_info *radius_info, const uint8_t *data, uint16_t data_len);



void radius_get_ip_str_from_byte(char *ip_str, const uint8_t *data);
#endif //PCAPREAD_RADIUSINFO_H

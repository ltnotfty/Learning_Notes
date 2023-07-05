//
// Created by xOx on 2023/7/4.
//
#include "RadiusInfo.h"

void   parse_radius_hdr(const uint8_t *data, uint16_t data_len)
{
    const struct radius_hdr *radius_hdr = (const struct radius_hdr *) data;

    if ( radius_hdr->code != ACCOUNTING_REQUEST)
        return;

    uint16_t radius_length = radius_hdr->length;
   //  printf("radius length: %u, radius hdr length: %lu\n", ntohs(radius_length), sizeof(struct radius_hdr) );



    radius_info tmp_radius_info;
    init_radius_info(&tmp_radius_info);
    parse_radius_attr( &tmp_radius_info, data + sizeof(struct radius_hdr), data_len - sizeof(struct radius_hdr) );
    if (tmp_radius_info.HAVE_PUBLIC_IP)
        printf("public ip: %s\t", tmp_radius_info.public_ip);
    if ( tmp_radius_info.HAVE_USER_NAME)
        printf("user name: %s\t", tmp_radius_info.user_name);
    if ( tmp_radius_info.HAVE_FRAMED_IP)
        printf("framed ip: %s\t", tmp_radius_info.framed_ip);
    if ( tmp_radius_info.port_start != 0xffff)
        printf("port range is: %u-%u", tmp_radius_info.port_start, tmp_radius_info.port_end);

    printf("\n");

}



void parse_radius_attr(struct radius_info * radius_info, const uint8_t *data, uint16_t length)
{

    uint16_t offset = 0;
    const struct radius_attr *cur;
    const uint8_t *data_end  = data + length;


    // dump_data_hex(data, length);

    while ( data  < data_end)
    {
       cur = (const struct radius_attr *) data;
       uint16_t cur_attr_len =  cur->length;
       if ( cur_attr_len == 0)
            break;


        switch ( cur->type)
        {
            case USER_NAME:
                if (false== radius_info->HAVE_USER_NAME) {
                    radius_get_user_name(radius_info, cur->value, cur->length - 2);
                }
                break;
            case VENDOR_SPECIFIC:
                uint32_t vendor_type;
                vendor_type = ntohl(*(uint32_t *)(cur->value) );
                uint16_t vendor_length;
                vendor_length = cur->length - 6;

                switch ( vendor_type )
                {
                    case VENDOR_HUAWEI:
                        parse_huawei_vsa( radius_info,cur->value + 4, vendor_length);
                        break;
                    case VENDOR_H3C:
                        parse_h3c_vsa(cur->value + 4, vendor_length);
                        break;
                    case VENDOR_CHINA_TELECOM:
                        parse_telecom_vsa(cur->value + 4, vendor_length);
                        break;
                }

                break;
            case FRAMED_IP_ADDRESS:
                if (false == radius_info->HAVE_FRAMED_IP) {
                    radius_get_framed_ip_str(radius_info, cur->value);
                }
                break;
            default:
                break;
        }

        data += cur_attr_len;
    }

}



void init_radius_info(struct radius_info *radius_info)
{
    radius_info->framed_ip[0] = '\0';
    radius_info->public_ip[0] = '\0';
    radius_info->port_end = 0;
    radius_info->port_start = 0xffff;
    radius_info->user_name[0] = '\0';
}




bool parse_huawei_vsa(struct radius_info *radius_info, const uint8_t *data, uint16_t data_length)
{
    const uint8_t *data_end;
    data_end = data + data_length;


    const struct packet_tlv *ptr_tlv;
    while (data < data_end) {
        ptr_tlv = (const struct packet_tlv *)data;

        switch (ptr_tlv->type){
            case HUAWEI_PUBLIC_IP:
                // vsa->getIpString(mPublicIP);
                if (false == radius_info->HAVE_PUBLIC_IP) {
                    //get_public_ip(radius_info, ptr_tlv->value);
                    radius_get_public_ip_str( radius_info, ptr_tlv->value);
                }
                break;

            case HUAWEI_PORT_START:
                // mPortStart = vsa->getUint32BE();
                radius_get_port_start( radius_info, ptr_tlv->value);
                break;

            case HUAWEI_PORT_END:
                radius_get_port_end( radius_info, ptr_tlv->value);
                break;
            default:
                break;
        }
        if (ptr_tlv->length == 0) {
            break;
        }
        data += ptr_tlv->length;
    }

    return data == data_end;
}

bool parse_h3c_vsa(const uint8_t *data, uint16_t dataLen)
{
    const auto * data_end = data + dataLen;

    const struct packet_tlv *ptr_tlv;
    while (data < data_end) {
        ptr_tlv = ( const struct packet_tlv * ) data;

        switch ( ptr_tlv->type ){
            case H3C_PUBLIC_IP:
                // vsa->getIpString(mPublicIP);
                break;

            case H3C_PORT_START:
                // mPortStart = vsa->getUint32BE();
                break;

            case H3C_PORT_END:
                // mPortEnd = vsa->getUint32BE();
                break;

            case H3C_INFO_PARSE:
            {
            // find pos of split char ':', and record them
            // split char need to be 4
            // between the split char: public_ip, port_start, port_end
            }
                break;

            default:
                break;
        }
        if ( ptr_tlv->length == 0) {
            break;
        }
        data += ptr_tlv->length;
    }
    return data == data_end;
}

bool parse_telecom_vsa(const uint8_t *data, uint16_t dataLen)
{
    const auto * data_end = data + dataLen;

    const struct packet_tlv *ptr_tlv;
    bool found = false;
    while (data < data_end) {
        ptr_tlv = (const struct packet_tlv *)data;

        if (ptr_tlv->type == TELECOM_INFO_PARSE) {
            found = true;
            break;
        }

        if (ptr_tlv->length == 0) {
            break;
        }
        data += ptr_tlv->length;
    }

    if (found) {

        // find pos of split char ';', and record them
        // split char need to be 4
        // between the split char: public_ip, port_start, port_end
    }

    return data == data_end;
}

void radius_get_port_start(struct radius_info *radius_info, const uint8_t *data)
{
    radius_info->port_start = ntohl(*(uint32_t *) data);
}
void radius_get_port_end(struct radius_info *radius_info, const uint8_t *data)
{
    radius_info->port_end = ntohl(*(uint32_t *) data);
}


void radius_get_ip_str_from_byte(char *ip_str, const uint8_t *data)
{
    char ip_byte_str[4];

    *(uint32_t *) ip_byte_str = *(uint32_t *) data;

    uint16_t  offset = 0;

    for (int i = 0; i < 4; ++i) {

        char byte_str_off = 0;
        char byte_str[3];

        uint8_t byte_val = ip_byte_str[i];

        if (byte_val == 0)
            byte_str[byte_str_off++] = '0';
        while( byte_val ) {
            byte_str[byte_str_off++] = '0' + byte_val % 10;
            byte_val /= 10;
        }


        while ( byte_str_off-- )
            ip_str[offset++] = byte_str[byte_str_off];
        if (i + 1 != 4)
            ip_str[offset++] = '.';
        else
            ip_str[offset++] = '\0';
    }
}
void radius_get_public_ip_str(struct radius_info *radius_info, const uint8_t *data)
{
    return radius_get_ip_str_from_byte(radius_info->public_ip, data);
}

void radius_get_framed_ip_str(struct radius_info *radius_info, const uint8_t *data)
{
    return radius_get_ip_str_from_byte(radius_info->framed_ip, data);
}
void radius_get_user_name(struct radius_info *radius_info, const uint8_t *data, uint16_t data_len)
{
    if (data_len < 64) {
        memcpy(radius_info->user_name, data, data_len);
        radius_info->user_name[data_len] = '\0';

    }
}








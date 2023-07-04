//
// Created by xOx on 2023/7/4.
//
#include "RadiusInfo.h"

void parse_radius_hdr(const uint8_t *data, uint16_t data_len)
{
    const struct radius_hdr *radius_hdr = (const struct radius_hdr *) data;

    if ( radius_hdr->code != ACCOUNTING_REQUEST)
        return;

    parse_radius_attr(radius_hdr->attr, data_len - sizeof(struct radius_hdr) );
}



void parse_radius_attr(const struct radius_attr *radius_attr, uint16_t length)
{

    uint16_t offset = 0;
    const struct radius_attr *cur= radius_attr;

    while ( offset < length)
    {
        uint16_t cur_attr_len = 2 + cur->length;
        switch ( cur->type)
        {
            case USER_NAME:
                break;
            case VENDOR_SPECIFIC:
                break;
            case FRAMED_IP_ADDRESS:
                break;
        }
        offset += cur_attr_len;
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




bool RadiusInfo::parseHuaweiVSA(uint8_t *data, int dataLen)
{
    const auto * dataEnd = data + dataLen;

    ValuePair* vsa;
    while (data < dataEnd) {
        vsa = (ValuePair *)data;

        switch (vsa->type){
            case 161:
                vsa->getIpString(mPublicIP);
                break;

            case 162:
                mPortStart = vsa->getUint32BE();
                break;

            case 163:
                mPortEnd = vsa->getUint32BE();
                break;

            default:
                break;
        }
        if (vsa->len == 0) {
            break;
        }
        data += vsa->len;
    }

    return data == dataEnd;
}


bool RadiusInfo::parseH3CVSA(uint8_t *data, int dataLen)
{
    const auto * dataEnd = data + dataLen;

    ValuePair* vsa;
    while (data < dataEnd) {
        vsa = (ValuePair *)data;

        switch (vsa->type){
            case 32:
                vsa->getIpString(mPublicIP);
                break;

            case 33:
                mPortStart = vsa->getUint32BE();
                break;

            case 34:
                mPortEnd = vsa->getUint32BE();
                break;

            case 121:
            {
                char* pos[4];
                char * ptr = (char*) vsa->data ;
                auto l = vsa->getDataLength();
                if (l == 0) {
                    break;
                }
                char * end = ptr + l;
                int i;
                for (i = 0; i < 4; ++i) {
                    ptr = (char*) memchr(ptr, ':', end - ptr);
                    if (ptr == nullptr) {
                        break;
                    }
                    pos[i] = ++ptr;
                }

                if (i == 4) {
                    if (mPublicIP.empty()) {
                        mPublicIP = string(pos[0], pos[1] - pos[0] - 1);
                    }
                    if (mPortStart == 0) {
                        mPortStart = stoi(string(pos[1], pos[2] - pos[1] - 1));
                    }
                    if (mPortEnd == 0xffff) {
                        mPortEnd   = stoi(string(pos[2], pos[3] - pos[2] - 1));
                    }
                }
            }
                break;

            default:
                break;
        }
        if (vsa->len == 0) {
            break;
        }
        data += vsa->len;
    }

    return data == dataEnd;
}

bool RadiusInfo::parseXxxxVSA(uint8_t *data, int dataLen)
{
    const auto * dataEnd = data + dataLen;

    ValuePair* vsa;
    bool found = false;
    while (data < dataEnd) {
        vsa = (ValuePair *)data;

        if (vsa->type == 121) {
            found = true;
            break;
        }

        if (vsa->len == 0) {
            break;
        }
        data += vsa->len;
    }

    if (found) {
        string value = vsa->getString();
        size_t pos[4] = {0};
        size_t lastPos = 0;
        int i;
        for (i = 0; i < 4; ++i) {
            lastPos = value.find(';', lastPos);
            if (lastPos == string::npos) {
                break;
            }
            pos[i] = ++lastPos;
        }

        if (i == 4) {
            mPublicIP = value.substr(pos[0], pos[1] - pos[0] - 1);

            mPortStart = stoi(value.substr(pos[1], pos[2] - pos[1] - 1));
            mPortEnd   = stoi(value.substr(pos[2], pos[3] - pos[2] - 1));
        }

    }

    return data == dataEnd;
}




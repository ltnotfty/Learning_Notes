#ifndef SELF_IPUTIL_H

#define SELF_IPUTIL_H

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#if __STDC_VERSION__  <= 199901L
#warning "stdbool.h not support"
#define bool int
#define true 1
#define false 0
#else
#include <stdbool.h>
#endif



bool isIPv4Str(const char *str);



#endif


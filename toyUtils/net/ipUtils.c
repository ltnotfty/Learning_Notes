#include "ipUtils.h"

const char * isIPSec(const char *str)
{
        int len = strlen(str);
        

	int checkLen = len > 3 ? 3 : len;
        int totNum = 0;

	for ( int i = 0;i < checkLen; ++i)
	{
            if ( i == 0 && str[i] == '0') {
	        checkLen = 1;
	    }
            if ( i != 0 && str[i] == '.') {
                checkLen = i ;
		break;
	    }

	    if (!isdigit(str[i]))
		    return NULL;
	    totNum = totNum * 10 + str[i] - '0';
	}

	if (totNum < 256 && totNum > 0)
		return str + checkLen;
	return NULL;
}



bool isIPv4Str(const char *str)
{
    if (!str)
	    return false;
    int len = strlen(str);
    const char  *end = str + len;
    if ( len > 15)
	    return false;

    const char *prev = NULL;
    const char *curr = str; 
    int i = 0;

    for (  i = 0; i < 4; ++i)
    {
         curr = isIPSec(curr);
         if ( curr == NULL)
		 return false;

	 if ( curr < end) {
	 	if ( curr[0] != '.' )
		    return false;
	 	if ( (curr + 1) < end)
			 ++curr;
	 }
    }


    return i == 4 && curr == end ;

}




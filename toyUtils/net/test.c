#include <stdio.h>


#include <string.h>

#include "IPUtils.h"

int main(int argc, char *argv[])
{
   if ( argc != 2)
   {
	   fprintf(stderr, "usage: %s <IPString>\n");
           exit(EXIT_FAILURE);
   }

   printf("%s %s a leagal IPv4 string", argv[1], isIPv4Str(argv[1]) ? "is" : "is not");

    return 0;
}

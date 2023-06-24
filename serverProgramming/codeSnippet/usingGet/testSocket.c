#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>


#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main( int argc, char *argv[])
{
   int status;
   struct addrinfo hints, *res, *p;

   memset(&hints, 0, sizeof(hints));
   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = AF_STREAM;

   if ( (status = getadddrinfo(NULL, NULL, &hints, &res)) != 0) {
       fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
       return 2;
   }

   for ( p = res; p != NULL; p = p->ai_next ) {
       // check

   }


   s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

   




    return 0;
}

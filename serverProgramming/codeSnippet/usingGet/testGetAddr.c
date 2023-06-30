#include <sys/type.h>
#include <sys/socket.h>


//getIP.c



int main( int argc, char *argv[])
{
    
    int status ;
    struct addrinfo hints;
    struct addrinfo *servinfo;

    memset(&hints, 0, sizeof hints);
    hints.ai_famaly = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ( (status = getaddrinf(NULL, "3490", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status) );
        exit(1);
    }

    freeaddrinfo(servinfo);


    return 0;
}

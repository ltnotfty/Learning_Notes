#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>


#define BUF_SIZE 500


int main( int argc, char *argv[])
{

	struct addrinfo hints;
	struct addrinfo *result, *rp;
	int sfd, s;
	size_t len;
	ssize_t nread;
	char buf[BUF_SIZE];

	if ( argc < 3) {
            fprintf(stderr, "Usage: %s host  port msg...\n", argv[0]);
	    exit(EXIT_FAILURE);
	}

	/* Obtain address mathing host/port */

	memset( &hints, 0, sizeof(hints) );
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = 0;
	hints.ai_protocol = 0;

	s = getaddrinfo(argv[1], argv[2], &hints, &result);
	if ( 0 != s) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
	    exit(EXIT_FAILURE);
	}

	for ( rp = result; rp != NULL; rp = rp->ai_next ) {
            sfd = socket(rp->ai_family, rp->ai_socktype, 
			 rp->ai_protocol);
	    if (-1 == sfd)
		    continue;
	    if ( connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
		    break;
            close(sfd);
	}

	freeaddrinfo(result);

	if ( NULL == rp) {
            fprintf(stderr, "Could not connect\n");
	    exit(EXIT_FAILURE);
	}

	/* Send remaining command-line arguments as separte datagrams, 
	 * and read responses from server */
        
	for ( int j = 3; j < argc; j++) {
            len = strlen(argv[j]) + 1;

	    if ( len > BUF_SIZE ) {
	    	fprintf(stderr, "Ignoring long message in argument %d\n", j);
		continue;
	    }

	    if ( len != write(sfd, argv[j], len)) {
                fprintf(stderr, "patial/failed write\n");
		exit(EXIT_FAILURE);
	    }

	    nread = read(sfd, buf, BUF_SIZE);
	    if ( -1 == nread) {
                perror("read");
		exit(EXIT_FAILURE);
	    }

	    printf("Received %zd bytes: %s\n", nread, buf);
	}

	exit(EXIT_SUCCESS);


}

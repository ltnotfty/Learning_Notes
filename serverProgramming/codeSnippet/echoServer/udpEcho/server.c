#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 500


int main(int argc, char *argv[])
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s;
    struct sockaddr_storage peer_addr;
    socklen_t peer_addr_len;
    ssize_t nread;
    char buf[BUF_SIZE];

    if ( 2 != argc) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset( &hints, 0, sizeof(hints) );
    hints.ai_family = AF_UNSPEC; // ALLOW IPv4 or IPv6
    hints.ai_socktype = SOCK_DGRAM; // Datagram sock 
    hints.ai_flags = AI_PASSIVE;  // For wildcard 
    hints.ai_protocol = 0;
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    s = getaddrinfo( NULL, argv[1], &hints, &result);
    if (0 != s) {
	fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s) );
        exit(EXIT_FAILURE);
    }	

    for ( rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
	if ( -1 == sfd)
		continue;

	if ( bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
		break;
	close(sfd);

    }

    freeaddrinfo(result);

    if (rp == NULL) {
        fprintf(stderr, "Could not bind\n");
	exit(EXIT_FAILURE);
    }
    
    /* Read datagrams and echo them back to sender. */

    for (;;) {
        peer_addr_len = sizeof(peer_addr);
	nread = recvfrom(sfd,  buf, BUF_SIZE, 0, (struct sockaddr *) &peer_addr, &peer_addr_len );
	if ( -1 == nread)
		continue;

	char host[NI_MAXHOST], service[NI_MAXSERV];

	s = getnameinfo( (struct sockaddr *) &peer_addr,
			  peer_addr_len, host, NI_MAXHOST,
			  service, NI_MAXSERV, NI_NUMERICSERV);

	if ( 0 == s)
		printf("Received %zd bytes from %s:%s\n", nread, host, service);
	else
		fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s) );

	if ( sendto(sfd, buf, nread, 0,
		    (struct sockaddr *) &peer_addr,
		    peer_addr_len) != nread)
		fprintf(stderr, "Error sending response\n1");


    }

}

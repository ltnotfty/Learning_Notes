#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


#define PORT "9034"


void *get_in_addr( struct sockaddr *sa)
{
    if ( sa->sa_family == AF_INET) {
	return &(( (struct sockaddr_in *)sa)->sin_addr);
    }

    return &( ((struct sockaddr_in6 *)sa)->sin6_addr);
}


int main(int argc, char *argv[])
{
    fd_set master;
    fd_set read_fds;
    int fdmax;
    
    int listener;
    int newfd;
    struct sockaddr_storage remoteaddr;
    socklen_t addrlen;

    char buf[256]; // buffer
    int nbytes;

    char remoteIP[INET6_ADDRSTRLEN];

    int yes = 1;
    int i, j , rv;

    struct addrinfo hints, *ai, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if ( (rv = getaddrinfo(NULL, PORT, &hints, &ai)) != 0) {
        fprintf(stderr, "selectserver: %s\n", gai_strerror(rv) );
	exit(1);
    }

    for ( p = ai; p != NULL; p = p->ai_next ) {
        listener = socket( p->ai_family, p->ai_socktype, p->ai_protocol );
	if ( 0 > listener ) {
	    continue;
	}
        
	// set address already in use
	setsockopt( listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int) );
        
	if ( bind(listener, p->ai_addr, p->ai_addrlen) < 0) {
            close(listener);
	    continue;
	}
        
	break;
    }

    if ( p == NULL ) {
        fprintf(stderr, "selectserver: failed to bind\n");
	exit(2);
    }

    freeaddrinfo(ai);

    if ( listen(listener, 10) == -1) {
        perror("listen");
        exit(3);
    }

    // add the listener to the mater set
    FD_SET(listener, &master);
    fdmax = listener;

    // main loop

    for ( ; ; ) {
        read_fds = master;
	if ( select(fdmax + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
	    exit(4);
	}

	for ( i = 0; i <= fdmax; ++i ) {
            if ( FD_ISSET(i, &read_fds)) {
                if ( i == listener) {
                   // handle new connections
                   addrlen = sizeof remoteaddr;
		   newfd = accept(listener,
				   (struct sockaddr *) &remoteaddr,
				   &addrlen);

		   if (newfd == -1) {
                       perror("accept");
		   }
		   else {
                       FD_SET(newfd, &master);
		       if ( newfd > fdmax) {
		           fdmax = newfd;
		       }
		       printf("selectserver: new connection from %s on"
		           "socket %d\n",
			   inet_ntop(remoteaddr.ss_family, 
		           get_in_addr((struct sockaddr *)&remoteaddr),
			   remoteIP, INET6_ADDRSTRLEN),
			   newfd);
		   }

		}


		else {
                    // handle data from a client
		    if ( (nbytes = recv(i, buf, sizeof buf, 0)) <= 0) {
                        
		        if (0 == nbytes) {
                            printf("selectserver: socket %d hung up\n", i);
			}
			else {
                            perror("recv");
			}
			close(i);
			FD_CLR(i, &master);
                        
		    }
		    else {
                        // we got some data from a client
                        for (int j = 0; j <= fdmax; ++j) {
			    if ( FD_ISSET(j, &master)) {
                                if (j != listener && j != i) {
                                    if ( send(j , buf, nbytes, 0) == -1 ) {
                                        perror("send");
				    }
				}
			    } // detect
		        }// fd loop
                    }//recv ok
		}// a old connection
	    }// loop through

	}

    }

    return 0;
}




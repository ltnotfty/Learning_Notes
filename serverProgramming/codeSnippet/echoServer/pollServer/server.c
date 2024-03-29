#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/poll.h>


#define PORT "9034"

void *get_in_addr(struct sockaddr *sa)
{
    if ( sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


// return a listening socket

int get_listenner_socket(void)
{
    int listener;
    int yes = 1;
    int rv;

    struct addrinfo hints, *ai, *p;

    // Get us a socket and bind it
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if ((rv = getaddrinfo(NULL, PORT, &hints, &ai)) != 0) {
        fprintf(stderr, "selectserver: %s\n", gai_strerror(rv) );
	exit(1);
    }

    for ( p = ai; p != NULL; p = p->ai_next ) {
        listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol );
	if (listener < 0) {
            continue;
	}

	// Lose the pesky "address already in use" error message.
	setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

	if ( bind(listener, p->ai_addr, p->ai_addrlen) < 0) {
            close( listener);
	    continue;
	}

	break;
    }

    freeaddrinfo(ai);

    if (NULL == p) {
        return -1;
    }

    if (-1 == listen(listener, 10)) {
        return -1;
    }

    return listener;

}

void add_to_pfds(struct pollfd *pfds[], int newfd, int *fd_count, int *fd_size)
{
    // If we don't have room , add more space in the pfds array
    if ( *fd_count == *fd_size ) {
        *fd_size *= 2;

	*pfds = realloc(*pfds, sizeof(**pfds) * (*fd_size) );
    }

    (*pfds)[*fd_count].fd = newfd;
    (*pfds)[*fd_count].events = POLLIN;

    (*fd_count)++;
}

void del_from_pfds(struct pollfd *pfds[], int i, int *fd_count)
{
    // copy the one from the end over this one
    pfds[i] = pfds[*fd_count - 1];

    (*fd_count)--;

}


int main(void)
{
    int listener;

    int newfd;
    struct sockaddr_storage remoteaddr;
    socklen_t addrlen;

    char buf[256];

    char remoteIP[INET_ADDRSTRLEN];


    int fd_count = 0;
    int fd_size = 5;
    struct pollfd *pfds = malloc(sizeof (*pfds) * fd_size);

    // Set up  and get a listening socket
    listener = get_listenner_socket();

    if ( -1 == listener) {
        fprintf(stderr, "error getting listening socket\n");
	exit(1);
    }

    // Add the listener to set
    pfds[0].fd = listener;
    pfds[0].events = POLLIN;

    fd_count = 1;


    for ( ; ; ) {
        int poll_count = poll(pfds, fd_count, -1);

	if ( -1 == poll_count) {
            perror("poll");
	    exit(1);
	}

	// run through the existing connection looking for data to read
	for ( int i = 0; i < fd_count; ++i ) {
          // check if someone's ready to read
	  if ( pfds[i].revents & POLLIN) {
          
	      addrlen = sizeof(remoteaddr);
	      newfd = accept(listener, 
			      (struct sockaddr *)&remoteaddr,
			      &addrlen);
	      if (newfd == -1) {
	          perror("accept");
	      }
	      else {
	          add_to_pfds(&pfds, newfd, &fd_count, &fd_size);

		  printf("pollserver: new connection from %s on socket %d\n",
		          inet_ntop(remoteaddr.ss_family,
		          get_in_addr((struct sockaddr*)&remoteaddr),remoteIP, INET6_ADDRSTRLEN),
			  newfd);
            

	      }
	  }
	  else {
              int nbytes = recv(pfds[i].fd, buf, sizeof buf, 0);

	      int sender_fd = pfds[i].fd;

	      if ( nbytes <= 0 ) {
                  // Got error or connection closed by client

		   if ( 0 == nbytes) {
		       printf("pollserver: socket %d hung up\n", sender_fd);
		   }
		   else {
		       perror("recv");
		   }

		   close(pfds[i].fd);// Bye
		   del_from_pfds(pfds, i, &fd_count);
	      }
	      else {
                  // We got some good data from a client

	          for ( int j = 0; j < fd_count; ++j) {
                      // Send to everyone!

			  int dest_fd = pfds[j].fd;

			  // Except the listener and ourselves
			  if ( dest_fd != listener && dest_fd != sender_fd ) {
                              if (send(dest_fd, buf, nbytes, 0) == -1) {
                                  perror("send");
			      }
			  }
		  }
	      }
	  }

	}

    }

    return 0;
}

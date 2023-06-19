#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/poll.h>


#define errExit(msg) do { perror(msg); exit(EXIT_FAILURE); \
	             } while(0)

int main( int argc, char *argv[])
{

	int nfds, num_open_fds;
	struct pollfd *pfds;

	if ( argc < 2 ) {
            fprintf(stderr, "Usage: %s file...\n", argv[0]);
            exit(EXIT_FAILURE);
	}

	num_open_fds = nfds = argc - 1;
	pfds = calloc(nfds, sizeof(struct pollfd) );
	if ( NULL == pfds) {
           errExit("calloc");
	}

	printf("calloc %d pollfd memory success...\n", nfds);
	/* open each file on command line, and add it 'pfds' array. */

	for ( int j = 0; j < nfds; ++j) {
	    printf("Opened fifo...\n");
            pfds[j].fd = open(argv[ j + 1 ], O_RDONLY );
	    if ( pfds[j].fd == -1) {
	        errExit("open");
	    }
	
	    printf("Opened \\ %s \\ on fd %d\n", argv[ j + 1], pfds[j].fd);

	    pfds[j].events = POLLIN;
	}

	/* Keep calling poll() as long as at least one file descriptor is
	 * open. */

	while ( num_open_fds > 0) {
            int ready;

	    printf("About to poll\n");

	    ready = poll(pfds, nfds, -1);

	    printf("Ready: %d\n", ready);

	    /* Deal with array returned by poll().
		    */

            for ( int j = 0; j < nfds; ++j) {
                char buf[10];

		if (pfds[j].revents != 0) {
                    printf(" fd = %d,  event: %s%s%s\n", pfds[j].fd,
		            (pfds[j].revents & POLLIN) ? "POLLIN" :"",
			    (pfds[j].revents & POLLHUP) ? "POLLHUP": "",
			    (pfds[j].revents & POLLERR) ? "POLLERR": "");

		    if (pfds[j].revents & POLLIN) {
                        ssize_t s = read(pfds[j].fd, buf, sizeof(buf) );
			if ( -1 == s){
			    errExit("read");
			}
			printf("    read %zd bytes: %.*s\n",
				s ,(int) s, buf);
		    }
		    else {
                        printf(" closing fd %d\n", pfds[j].fd);
			if ( close(pfds[j].fd) == -1) {
                            errExit("close");
			}
                        num_open_fds--;
		    }
		}
	    }
            sleep(1);
	}

    printf("All file descriptprs closed£»bye\n");
    exit(EXIT_SUCCESS);

} 

#include <stdio.h>
#include <sys/poll.h>

#include <unistd.h>

int main(int argc, char *argv[])
{
    struct pollfd pfds[1];

    pfds[0].fd = STDIN_FILENO;
    pfds[0].events = POLLIN;

    printf("Hit RETURN or wait 2.5 seconds for timeout\n");

    int num_events = poll(pfds, 1, 2500);

    if ( num_events == 0) {
        printf("Poll timed out\n");
    }
    else {
        int pollin_happened = pfds[0].revents & POLLIN;

	if ( pollin_happened ) {
	    printf("File decriptor %d is ready to read\n", pfds[0].fd);
	}
	else {
            printf("Unexpected event occurred: %d\n", pfds[0].revents);
	}
    }


    return 0;
}

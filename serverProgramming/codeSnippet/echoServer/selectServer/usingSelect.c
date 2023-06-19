#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

#include <unistd.h>

int  main (void)
{
    fd_set rdfs;
    struct timeval tv;
    int rv;

    int maxfd = STDIN_FILENO + 1;
    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    rv = select( maxfd, &rdfs, NULL, NULL, &tv);

    if ( -1 == rv ){
        perror("select()");
    }
    else if ( rv ) {
        printf("Data is available now\n");
    }
    else {
        printf("No data within five seconds.\n");
    }


    exit(EXIT_SUCCESS);

}

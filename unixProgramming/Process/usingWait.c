#include <sys/wait.h>

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main( int argc, char *argv[])
{
    pid_t cpid, w;
    int wstatus;

    cpid = fork();
    if ( cpid == -1 ) {
        perror("fork");
	exit(EXIT_FAILURE);
    }

    if ( 0 == cpid ) { /* Code executed by child */
        printf("Child PID is %jd\n", (intmax_t) getpid() );
	if ( 1 == argc){
            pause();
	}
	_exit(atoi(argv[1]) );
    }
    else {

        w = waitpid( cpid, &wstatus, WUNTRACED | WCONTINUED);
	if ( -1 == w) {
	    perror("waitpid");
	    exit(EXIT_FAILURE);
	}

	if ( WIFEXITED(wstatus) ){
            printf("exited, status=%d\n", WEXITSTATUS(wstatus));
	}
	else if (WIFSIGNALED(wstatus) ) {
	    printf("killed by signal %d\n", WTERMSIG(wstatus) );
	}
	else if (WIFSTOPPED(status))
    }



   

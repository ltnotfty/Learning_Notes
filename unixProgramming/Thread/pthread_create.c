#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>



#define handle_error_en(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE);} while(0)

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE);} while(0)


struct thread_info {
    pthread_t thread_id;
    int thread_num;
    char *argv_string;
};

/* Thread start function: display address near top of our stack,
 * and return upper-cased copy of argv_string. */


static void *
thread_start( void *arg)
{
    struct thread_info *tinfo = arg;
    char *uargv;

    printf("Thread %d: top of stack near %p; argv_string=%s\n",
		    tinfo->thread_num, (void *) &tinfo, tinfo->argv_string);

    uargv = strdup(tinfo->argv_string);
    if ( uargv == NULL)
	    handle_error("strdup");

    for ( char *p = uargv; *p != '\0'; ++p)
	    *p = toupper(*p);


    return uargv;
}


int main(int argc, char *argv[])
{
    int s, opt, num_threads;

    pthread_attr_t attr;
    ssize_t stack_size;
    void *res;

    /* The "-s" option specifies a stack size for our threads. */
    
    stack_size = -1;

    while ( (opt = getopt(argc, argv, "s:")) != -1) {
        switch( opt ){
		case 's':
			stack_size = strtoul(optarg, NULL, 0);
			break;
		
		default:
			fprintf(stderr, "Usage: %s [-s stack-size] arg...\n", argv[0]);
			exit(EXIT_FAILURE);

        }
    }


    num_threads = argc - optind;

    s = pthread_attr_init( &attr );
    if ( 0 != s) 
	    handle_error_en( s, "pthread_attr_init");

    if ( stack_size > 0) {
        s = pthread_attr_setstacksize(&attr, stack_size);
	if ( 0 != s)
		handle_error_en( s, "pthread_attr_setstatcksize");
    }

    // Allocate memory for pthread_create() arguments

    struct thread_info *tinfo = calloc( num_threads, sizeof(*tinfo));

    if ( NULL == tinfo)
	    handle_error("calloc");


    for ( int tnum = 0; tnum < num_threads; ++tnum) {
        tinfo[tnum].thread_num = tnum + 1;
	tinfo[tnum].argv_string = argv[optind + tnum];

	s = pthread_create( &tinfo[tnum].thread_id, &attr,
			    &thread_start, &tinfo[tnum]);
	if ( 0 != s)
		handle_error_en(s, "pthread_create");
    }

    s = pthread_attr_destroy(&attr);
    if (0 != s)
	    handle_error_en( s, "pthread_attr_destroy");

    for ( int tnum = 0; tnum < num_threads; ++tnum) {
        s = pthread_join(tinfo[tnum].thread_id, &res);
	if (0 != s)
		handle_error_en(s, "pthread_join");
        
	printf("Joined with thread %d; returned value was %s\n",
			tinfo[tnum].thread_num, (char *) res);
	free(res);
    }

    free(tinfo);
    exit(EXIT_FAILURE);
}



#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// int getopt( int argc, char * const argv[], const char *optstring);
// extern char *optarg;
// extern optind, opterr, optopt;
//
// int getopt_long( int argc, char *const argv[], const char *optstring, 
// const struct option *longopts, int *longindx);
//
// int getopt_long_only( int argc, char * const argv[],
// const char *optstring,
// const struct option *longopts, int *longindex);

// optind is the index of the next element to be processed in argv
// initializes this value to 1

// long opts
// struct option {
//    const char *name;
//    int has_arg;
//    int *flag;
//    int val;
// }
int main( int argc, char **argv)
{
    int flags, opt;
    int nsecs, tfnd;

    nsecs = 0;
    tfnd = 0;
    flags = 0;

    while ( -1 != (opt = getopt(argc, argv, "nt:")))
    {
        switch ( opt )
	{ 
            case 'n':
	        flags = 1;
		break;
	    case 't':
	        nsecs = atoi(optarg);
		tfnd = 1;
		break;
	    default:
	        fprintf( stderr, "Usage: %s [-t nsecs] [-n] name\n",
				argv[0]);
		exit(EXIT_FAILURE);
	}
    }

    printf( "flags = %d; tfnd = %d; optind = %d.\n", flags, tfnd, optind);

    if ( optind >= argc ) {
        fprintf(stderr, "Expected argument after options\n");
	// exit(EXIT_FAILURE);
	
    } 

    printf(" name argument = %s\n", argv[optind]);


    return 0;
}

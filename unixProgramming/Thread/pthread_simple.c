#include <stdio.h>
#include <pthread.h>



void sayHi()
{
    printf("Hello World\n");
}


/*pthread_create
 * pthread_t *thread
 * const pthread_attr_t *
 * void *(*start_routine)(void *)
 * void *restrict arg
 */

int main(int argc, char *argv[])
{

   pthread_t helloThread;

   pthread_create( &helloThread, NULL, sayHi, NULL);

   pthread_join(helloThread, NULL); 



    return 0;
}

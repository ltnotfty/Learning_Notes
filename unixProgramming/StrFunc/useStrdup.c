#include <string.h>
#include <stdio.h>
#include <stdlib.h>



/*
 * char *strdup(const char *s);
 */
int main( int argc, char *argv[])
{

   if ( argc != 2) {
       printf("Usage: %s <string>", argv[0] );
       exit(EXIT_FAILURE);
   }

   char *cpStr = strdup(argv[1]);
   if ( NULL == cpStr) {
       printf("No sufficient memory\n");
       exit(EXIT_FAILURE);
   }
   printf("%s", cpStr);

   free(cpStr);
       


    return 0;
} 

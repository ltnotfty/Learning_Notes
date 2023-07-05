#include <stdio.h>
#include <string.h>




// void* memchr(const void *str, int c, size_t n);
// find first occurrences of character c in first n characters of str
// return target character pos
int main( int argc, char *argv[])
{

     char kHello[] = "Hello_World";
     int target_char = 'W';

     char *ptr = (char *) memchr( kHello,  target_char, strlen(kHello) );
     
      
     if ( ptr != NULL) {
         printf( "offset: %u %c", ptr - kHello, target_char);
     }
     else {
         printf( "not find target characters %c", target_char);
     }
      





    return 0;
}

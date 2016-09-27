/* Some fun with prime numbers
   Author:     Vincent T. Mossman
   Compile by: gcc -o prime prime.c
   Run by:     ./prime
*/

#include "primality.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char * argv[]) {

  long int test = 1;
  while (test != 0) {
    printf("Enter a natural number to test. 0 to exit: ");
    scanf("%d", &test);
    if (isPrime(test)) {
      printf("%d is prime\n", test);
    }
    else {
      printf("%d is not prime\n", test);
    } // end if (is...
  }

}

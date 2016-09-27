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

  if (argc != 2) {
    printf("Usage: [NAT to test primality]\n");
    exit(-1);
  }

  long int test;
  sscanf(argv[1], "%d", &test);

  clock_t begin = clock();
   
  if (isPrime(test)) {
    printf("\n%d is prime\n", test);
  }
  else {
    printf("\n%d is not prime\n", test);
  }

  clock_t end = clock();
  double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

  printf("\nCPU execution time: %0.3fs\n\n", time_spent);

}

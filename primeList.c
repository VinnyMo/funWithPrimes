/* Some fun with prime numbers
   Author:     Vincent T. Mossman
   Compile by: gcc -o primeList primeList.c
   Run by:     ./prime
*/

#include "eratosthenes.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Usage: %s <followed by [NAT to list primes to]>\n", argv[0]);
    exit(-1);
  }

  long unsigned int max, *primes, numPrimes, i;
  sscanf(argv[1], "%ld", &max);

  clock_t begin = clock();

  // get prime array
  primes = eratosthenesPrime(max, &numPrimes);

  // display prime list
  for (i = 0; i < numPrimes; i++) {
    printf("%ld, ",primes[i]);
  }
  printf("\n");

  clock_t end = clock();
  double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

  printf("\nCPU execution time: %0.3fs\n\n", time_spent);

}

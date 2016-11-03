/* Some fun with prime numbers
   Author:     Vincent T. Mossman
   Compile by: gcc -o primeList primeList.c
   Run by:     ./prime
*/

#include "eratosthenes.c"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Usage: %s <followed by [NAT to list primes to]>\n", argv[0]);
    exit(-1);
  }

  double p_start, p_finish, p_elapsed;
  double start, finish, elapsed;
  long unsigned int max, *primes, numPrimes, i;
  sscanf(argv[1], "%ld", &max);

  GET_TIME(start);

  // get prime array
  primes = pth_eratosthenesPrime(max, &numPrimes);

  GET_TIME(finish);
  elapsed = finish-start;
  GET_TIME(p_start);

  // display prime list
  for (i = 0; i < numPrimes; i++) {
    printf("%ld, ",primes[i]);
  }
  printf("\n");

  GET_TIME(p_finish);
  p_elapsed = p_finish-p_start;

  printf("\nCPU execution time to run sieve: %0.6lf seconds\n", elapsed);
  printf("CPU execution time to print: %0.6lf seconds\n\n", p_elapsed);

}

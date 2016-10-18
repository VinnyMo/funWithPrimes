/*
  Some fun with prime numbers
  Author:     Vincent T. Mossman
  Compile by: gcc -o primeSieveDivisor primeSieveDivisor.c
  Run by:     ./primeSieveDivisor <[NAT] to find prime divisors to>
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[]) {

  long unsigned int test, i, j, lastPrime=1;
  long unsigned int * sieve;

  // get sieve size
  if (argc != 2) {
    printf("Usage: %s <followed by [NAT] to find primes divisors to>\n", argv[0]);
    exit(-1);
  }
  sscanf(argv[1], "%ld", &test);

  // allocate sieve memory and initialize
  sieve = (long unsigned int *) malloc(sizeof(long unsigned int)*test);
  for (i = 0; i < test; i++) {
    sieve[i] = 1;
  }

  // run sieve
  clock_t begin = clock();
  for (i = 0; i < test; i++) {
    for (j = i; j < test; j=j+i+1) {
      if (sieve[j] == 1) {
	sieve[j] = i+1;
      }
    }
  }

  // display prime divisor array (1st degree)
  printf("{");
  for (i = 0; i < test; i++) {
    if (sieve[i] >= lastPrime) {
      lastPrime = sieve[i];
      printf("%ld} {", sieve[i]);
    }
    else {
      printf("%ld ", sieve[i]);
    }
  }

  clock_t end = clock();
  double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

  printf("\nCPU execution time: %0.3fs\n\n", time_spent);

}

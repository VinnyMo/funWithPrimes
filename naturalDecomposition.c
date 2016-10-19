/*
  Some fun with prime numbers. Program lists all natural numbers to user
   defined maximum decomposed to the 1st degree.
  Author:     Vincent T. Mossman
  Compile by: gcc -o naturalDecomposition naturalDecomposition.c
  Run by:     ./naturalDecomposition <followed by [NAT maxumim]>
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "eratosthenes.c"

int main(int argc, char * argv[]) {

  long unsigned int max, *sieve, i, lastPrime=1;

  // get sieve size
  if (argc != 2) {
    printf("Usage: %s <followed by [NAT] maximum>\n", argv[0]);
    exit(-1);
  }
  sscanf(argv[1], "%ld", &max);

  //run sieve
  sieve = eratosthenes(max);

  // display natural decomposition
  printf("{");
  for (i = 0; i < max; i++) {
    if (sieve[i] >= lastPrime) {
      lastPrime = sieve[i];
      printf("%ld} {", sieve[i]);
    }
    else {
      printf("%ld ", sieve[i]);
    }
  }

  printf("\n");

}

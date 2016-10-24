/*
  Some fun with prime numbers. Program lists all natural numbers to user
   defined maximum decomposed to the 1st degree.
  Author:     Vincent T. Mossman
  Compile by: gcc -o naturalDecomposition naturalDecomposition.c
  Run by:     ./naturalDecomposition <followed by [NAT maxumim]>
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include <time.h>
#include "eratosthenes.c"
#include <time.h>



int main(int argc, char * argv[]) {

  long unsigned int max, *sieve, i, lastPrime=1, j, resize;
  timespec {tv_sec=0; tv_nsec=100;};

  // get sieve size
  if (argc != 3) {
    printf("Usage: %s <followed by [NAT] maximum followed by [INT] resize>\n", argv[0]);
    exit(-1);
  }
  sscanf(argv[1], "%ld", &max);
  sscanf(argv[2], "%ld", &resize);

  // run sieve
  sieve = eratosthenesFull(max);

  // display natural decomposition
  for (i = 0; i < max; i++) {
    if (sieve[i] >= lastPrime) {
      lastPrime = sieve[i];
      //printf("%ld} {", sieve[i]);
    } else {
      //printf("sieve[i]: %ld;",sieve[i]);
      for (j=0;j<sieve[i];j++) {
        printf("*");
      }
      nanosleep();
      printf("\n");
    }
  }

  printf("\n");

}

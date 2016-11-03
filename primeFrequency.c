/* Some fun with prime numbers
   Author:     Vincent T. Mossman
   Compile by: gcc -o primeFrequency primeFrequency.c
   Run by:     ./prime
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timer.h"
#include "eratosthenes.c"

int main(int argc, char * argv[]) {

  if (argc != 3) {
    printf("Usage: %s <followed by [NAT to count to] followed by [NAT to count by]>\n", argv[0]);
    exit(-1);
  }

  int COUNT_TO, COUNT_BY;
  long unsigned int *primes, numPrimes;
  sscanf(argv[1], "%d", &COUNT_TO);
  sscanf(argv[2], "%d", &COUNT_BY);
  int stats[3] = {COUNT_BY + 1, 0, 0}; //FREQ MIN, FREQ MAX, TOT
  int i, startCount = 1, primeCount = 0, lastPrime = 0;
  double start, finish, elapsed;

  GET_TIME(start);

  // run sieve
  primes = pth_eratosthenesPrime(COUNT_TO, &numPrimes);

  printf("\n");
  for (i = 1; i <= COUNT_TO; i++) {
    if (primes[lastPrime] <= COUNT_BY+startCount-1 && lastPrime < numPrimes) {
      primeCount++;
      lastPrime++;
    }
    if (i % COUNT_BY == 0) {
        printf("%d primes between %d and %d (inclusive)\n", primeCount, startCount, i);
        if (primeCount < stats[0]) {
          stats[0] = primeCount;
        }
        if (primeCount > stats[1]) {
          stats[1] = primeCount;
        }

        stats[2] = stats[2] + primeCount;
        primeCount = 0;
        startCount = i+1;
    }
  }

  GET_TIME(finish);
  elapsed=finish-start;

  printf("\nCPU execution time: %0.6lfs\n", elapsed);
  printf("Lowest frequency per %d: %d\n", COUNT_BY, stats[0]);
  printf("Highest frequency per %d: %d\n", COUNT_BY, stats[1]);
  printf("Total Primes under %d: %d\n", COUNT_TO, stats[2]);
  printf("Average frequency: %0.3lf%% (to %d)\n\n", 100 * ((double) stats[2] / (double) COUNT_TO), COUNT_TO);

}

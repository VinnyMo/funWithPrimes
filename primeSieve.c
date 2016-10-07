#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[]) {

  long unsigned int test, i, j, lastPrime=1;
  long unsigned int * sieve;

  if (argc != 2) {
    printf("Usage: %s <followed by [NAT] to find primes up to>\n", argv[0]);
    exit(-1);
  }

  sscanf(argv[1], "%d", &test);

  sieve = (long unsigned int *) malloc(sizeof(long unsigned int)*test);

  //initialize sieve
  for (i = 0; i < test; i++) {
    sieve[i] = 1;
  }

  //run sieve
  clock_t begin = clock();
  for (i = 0; i < test; i++) {
    for (j = i; j < test; j=j+i+1) {
      if (sieve[j] == 1) {
	sieve[j] = i+1;
      }
    }
  }

  //prime divisors
  printf("{");
  for (i = 0; i < test; i++) {
    if (sieve[i] >= lastPrime) {
      lastPrime = sieve[i];
      printf("%d} {", sieve[i]); 
    }
    else {
      printf("%d ", sieve[i]);
    }
  }

  //primality test
  /*
  if (sieve[test-1] == test) {
    printf("\n%d is prime\n", test);
  }
  else {
    printf("\n%d is not prime\n", test);
  }
  */

  clock_t end = clock();
  double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

  printf("\nCPU execution time: %0.3fs\n\n", time_spent);

}

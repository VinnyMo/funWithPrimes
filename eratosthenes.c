/*
  Author: Vincent T. Mossman
  Date:   October 18, 2016
*/

#include <stdlib.h>

/******************************************************************************
* Function eratosthenesFull returns array of decomposed naturals of size n.   *
*  this is not quite standard for a Sieve of Eratosthenes as it is typically  *
*  used to find prime numbers, not "natural decomposition".                   *
******************************************************************************/
long unsigned int *eratosthenesFull(long unsigned int n) {

  long unsigned int *sieve, i, j;

  // allocate sieve memory and initialize
  sieve = (long unsigned int *) malloc(sizeof(long unsigned int)*n);
  for (i = 0; i < n; i++) {
    sieve[i] = 1;
  } // end for

  // run sieve
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j+=(i+1)) {
      if (sieve[j] == 1) {
        sieve[j] = i+1;
      } // end if
    } // end for (j)
  } // end for (i)

  return sieve;

} // end eratosthenes


/******************************************************************************
* Function eratosthenesPrime returns array of prime numbers between 1 and n.  *
*  Also assigns number of primes in returned array to size.                   *
******************************************************************************/
long unsigned int *eratosthenesPrime(long unsigned int n,
                                     long unsigned int *size) {

  long unsigned int *sieve, *primes, primeCount, lastPrime, i;

  // run sieve
  sieve = eratosthenesFull(n);

  // get primeCount
  primeCount=0;
  lastPrime=1;
  for (i = 0; i < n; i++) {
    if (sieve[i] >= lastPrime) {
      lastPrime = sieve[i];
      primeCount++;
    } // end if
  } // end for
  *size=primeCount;

  // allocate primes memory
  primes = (long unsigned int *) malloc(sizeof(long unsigned int)*primeCount);

  // build primes
  primeCount=0;
  lastPrime=1;
  for (i = 0; i < n; i++) {
    if (sieve[i] >= lastPrime) {
      lastPrime = sieve[i];
      primes[primeCount] = sieve[i];
      primeCount++;
    } // end if
  } // end for

  return primes;

} // end eratosthenesPrime

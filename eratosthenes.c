/*
  Author: Vincent T. Mossman
  Date:   October 18, 2016
*/

#include <stdlib.h>
#include <pthread.h>

// definitions
#define TRUE 1
#define FALSE 0

// global variables
int *isPrimeArray;
int numberOfThreads = 4;

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

/******************************************************************************
* Function pth_eratosthenesFull is a parallelized - but reduced - sieve       *
******************************************************************************/
long unsigned int *pth_eratosthenesFull(long unsigned int n) {

  long unsigned int *sieve, i, j;

  // allocate sieve memory and initialize
  sieve = (long unsigned int *) malloc(sizeof(long unsigned int)*n);
  for (i = 0; i < n; i++) {
    sieve[i] = 1;
  } // end for
  
  // allocate global "isPrimeArray" memory and initialize to all "Prime"
  isPrimeArray = (int *) malloc(sizeof(int)*n);
  for (i = 0; i < n; i++) {
    isPrimeArray[i] = TRUE; 
  }
  
  for (i = 0; i <  numberOfThreads; i ++) {
    if (errorCode = pthread_create(&threadHandles[i], NULL, threadPartialSieve, (void *) i) != 0) {
      printf("pthread %d failed to be created with error code %d\n", i, errorCode);
    }
  }

  for (i = 0; i < numberOfThreads; i++) {
    if (errorCode = pthread_join(threadHandles[i], (void **) NULL) != 0) {
      printf("pthread %d failed to be joined with error code %d\n", i, errorCode);
    } 
  }
  
  // run sieve
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j+=(i+1)) {
      if (sieve[j] == 1) {
        sieve[j] = i+1;
      } // end if
    } // end for (j)
  } // end for (i)

  return sieve;

} // end pth_eratosthenes

void * threadPartialSieve(void * rank) {

  if (globalIsPrime == false) {
    pthread_exit(0);
  }

  long int n = globalN;
  long int i = 2;
 
  if (n > numberOfThreads * 2) {

    int checkRange = (n / numberOfThreads) / 2;

    if ((long int) rank < (long int) numberOfThreads - 1) {
      for (i = 2 + ((long int) rank * checkRange); i <= (((long int) rank + 1) * checkRange) + 1; i++) {
          if (n % i == 0) {
	  globalIsPrime = false;
	  break;
	}
      }
    }
    else {
      for (i = (numberOfThreads - 1) * checkRange; i <= (n / 2); i++) {
	if (n % i == 0) {
	  globalIsPrime = false;
	  break;
	}
      }
    }

  }

  else {

    while (n % i != 0) {
      if (i > (n / 2)) {
	i = n;
	break;
      }
      i++;
    }
    if (i < n) {
      globalIsPrime = false;
    }
 
  }

}

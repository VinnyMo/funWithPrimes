#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void * threadPartialTest(void * args);
bool globalIsPrime;
int numberOfThreads = 2;
long int globalN = true;
pthread_mutex_t updateIsPrimeLock;

/******************************************************************
* Function isPrime returns true if n is prime, else returns false *
******************************************************************/
bool isPrime(long int n) {

  globalN = n;

  int i, errorCode;
  pthread_t * threadHandles = (pthread_t *) malloc(numberOfThreads * sizeof(pthread_t));

  for (i = 0; i <  numberOfThreads; i ++) {
    if (errorCode = pthread_create(&threadHandles[i], NULL, threadPartialTest, (void *) i) != 0) {
     printf("pthread %d failed to be created with error code %d\n", i, errorCode);
    }
  }

  for (i = 0; i < numberOfThreads; i++) {
    if (errorCode = pthread_join(threadHandles[i], (void **) NULL) != 0) {
      printf("pthread %d failed to be joined with error code %d\n", i, errorCode);
    }
  }

  return globalN;

}

void * threadPartialTest(void * rank) {

  long int n = globalN;
  long int i = 2 + ((long) rank * (n / 2 / numberOfThreads));

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

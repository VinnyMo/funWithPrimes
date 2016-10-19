/*
  Author: Vincent T. Mossman
  Date:   October 18, 2016
*/

/******************************************************************************
* Function sieve returns 1st degree (1 dimensional) Sieve of Eratosthenes of  *
   size n                                                                     *
******************************************************************************/
long unsigned int * eratosthenes(long unsigned int n) {

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

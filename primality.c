#include <stdbool.h>

/******************************************************************
* Function isPrime returns true if n is prime, else returns false *
******************************************************************/
bool isPrime(long int n) {

  long int i = 2;

  while (n % i != 0) {
    if (i > (n / 2)) {
        i = n; 
        break;
    }
    i++;
  }
  if (i < n) {
    return false;
  }
  else {
    return true;
  }

}

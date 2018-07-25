/*
  Author: Vincent T. Mossman
  Date:   July 24, 2018
*/

function isPrime(n) {

  // initialize divisor
  var div = 2;

  // determine lowest divisor (if any)
  while (n % div != 0) {
    if (div > Math.sqrt(n)) {
      div = n;
      break;
    } //end if
    i++;
  } //end while

  // determine primality state
  if (div < n) {
    return false;
  } else {
    return true;
  } //end if

} //end isPrime

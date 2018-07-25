/*
  Author: Vincent T. Mossman
  Date:   July 24, 2018
*/

function isPrime(n) {

  // initialize divisor
  var div = 2;

  // find divisor (if any)
  while (n % div != 0) {
    if (i > (n / 2)) {
      div = n;
      break;
    } //end if
    i++;
  } //end while

  // determine primality
  if (div < n) {
    return false;
  } else {
    return true;
  } //end if

} //end isPrime

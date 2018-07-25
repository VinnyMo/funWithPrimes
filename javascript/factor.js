/*
  Author: Vincent T. Mossman
  Date:   July 24, 2018
*/

function factors(n) {

  // initialize divisor and factors
  let div = 2;
  let factors = [1];

  // determine factors
  while (div <= (n / 2)) {
    if (n % div == 0) {
      factors.push(div);
    } //end if
    div++;
  } //end while
  factors.push(parseInt(n));

  return factors;

} //end isPrime

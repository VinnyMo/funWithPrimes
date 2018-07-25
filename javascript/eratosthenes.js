/*
  Author:  Vincent T. Mossman
  Updated: July 25, 2018
*/

/*
eratosthenesFull returns an array of size n containing integers from 1 to n
 inclusive where all prime integers appear as themselves and all composite
 integers appear as 0.
*/
function eratosthenesFull(n) {
  let sieve = [1];

  for (i=sieve[0];i<n;i++) {
    sieve.push(i+1);
  }

  p=2;
  while (p<n) {
    for (i=(p-1);i<n;i+=p) {
      if (sieve[i] != p) {
        sieve[i]=0;
      }
    }
    p++;
  }

  return sieve;
}

/*
eratosthenesReduced returns an array of all prime numbers from 1 to n inclusive.
*/
function eratosthenesReduced(n) {
  let sieve = eratosthenesFull(n);

  do {
    p=sieve.indexOf(0);
    if (p==-1) {
      break;
    }
    sieve.splice(p, 1);
  } while (true);

  return sieve;
}

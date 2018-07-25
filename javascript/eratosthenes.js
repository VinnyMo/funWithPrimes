/*
  Author:  Vincent T. Mossman
  Updated: July 24, 2018
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

function eratosthenesReduced(n) {
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

  do {
    p=sieve.indexOf(0);
    if (p==-1) {
      break;
    }
    sieve.splice(p, 1);
  } while (true);

  return sieve;
}

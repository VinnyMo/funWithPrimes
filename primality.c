#include <stdbool.h>

/*******************************************************************
 * Function isPrime returns true if value is prime, else returns    *
    false                                                           *
   Note: Very, very inefficient. Right now.                         *
   Another Note: I define PRIME as any number that is EVENLY        *
    PARTITIONED by the UNIT and ONLY by the unit. Screw 'em for not *
    including 1.                                                    *
********************************************************************/
bool isPrime(long int n) {

  /* Vinny's notes

     1.)
     Idea Tested: Check primality of large ints starting from n/2 and decrement until you find a divisor.
     Why?: Maybe large numbers tend to have larger divisors than small numbers on average
     Test Results: Divisors look like they tend to be small numbers, so it didn't do much good to check from n/2 down, things got very  much slower
     Lessons learned: Still might help a bit if we can continue to check up from 1 with one core and check down from n/2 with another somehow. (Hopefully learn how to in parallel programming) Kind of a divide and conquer method or somet\
hing.

     2.)
     Idea Tested: I want proof that 'if(i > (n / 2)) {i = n; break;}' actually saves CPU time
     Why?: Because it should, I want proof.
     Test Results:
      WITHOUT IF (Ran Frequency Test by 1000 to 500000) - 115.540s
      WITH IF (Ran Frequency Test by 1000 to 500000) - 63.820s
     Lessons learned: The if statement is obviously beneficial to the algorithm. Told ya so.

     3.)
     Idea Tested: Big Naturals

     4.) Max difference between primes under 1mil is 114
  */

  long int i = 2;

  while (n % i != 0) {
    if(i > (n / 2)) {i = n; break;} // get rid of useless maths
    i++;
  } // end while (n...
  if (i < n) {
    return false;
  }
  else {
    return true;
  }

} // end isPrime()

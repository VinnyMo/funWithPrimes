/* Some fun with prime numbers
   Author:     Vincent T. Mossman
   Compile by: gcc -o prime prime.c
   Run by:     ./prime
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// function prototypes
bool isPrime(long int);

int main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Usage: %s <followed by [NAT to count to]>\n", argv[0]);
    exit(-1);
  }
  int COUNT_TO, lineCount = 0, i, max = 0;
  sscanf(argv[1], "%d", &COUNT_TO);
  int track[4] = {1, 0, 0, 1}; //Previous Prime Position, Total Distance, Total Primes, Line Start Prime
  clock_t begin = clock();
  printf("\n");
  printf("Difference between primes:\n");
  for (i = 1; i <= COUNT_TO; i++) {
    if (isPrime(i)){
      if (lineCount > 19) {printf("    Primes between %d and %d\n", track[3], i); lineCount = 0;}
      printf("%*d ", 3, i - track[0]); lineCount++;
      if (lineCount == 1) {track[3] = i;}
      track[1] = track[1] + (i - track[0]);
      if (i - track[0] > max) {max = i - track[0];}
      track[0] = i;
      track[2]++;
    }
  }
  printf("    Primes between %d and %d\n", track[3], i);
  clock_t end = clock();
  double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
  printf("\nCPU execution time: %0.3lfs\n", time_spent);
  printf("Average difference between primes: %0.3lf\n", (double) track[1] / (double) track[2]);
  printf("Max difference between primes: %d\n\n", max);

  }

  /*
  long int test = 1;
  while (test != 0) {
    printf("Enter a natural number to test. 0 to exit: ");
    scanf("%d", &test);
    if (isPrime(test)) {
      printf("%d is prime\n", test);
    }
    else {
      printf("%d is not prime\n", test);
    } // end if (is...
  }
  */
  
  /*
  if (argc != 3) {
    printf("Usage: %s <followed by [NAT to count to] followed by [NAT to count by]>\n", argv[0]);
    exit(-1);
  }
  int COUNT_TO, COUNT_BY;
  sscanf(argv[1], "%d", &COUNT_TO);
  sscanf(argv[2], "%d", &COUNT_BY);
  int stats[3] = {COUNT_BY + 1, 0, 0}; //FREQ MIN, FREQ MAX, TOT
  int i, startCount = 1, primeCount = 0;
  clock_t begin = clock();
  printf("\n");
  for (i = 1; i <= COUNT_TO; i++) {
    if (isPrime(i)){primeCount++;}
    if (i % COUNT_BY == 0) {
      printf("%d primes between %d and %d (inclusive)\n", primeCount, startCount, i);
      if (primeCount < stats[0]) {
	stats[0] = primeCount;
      }
      if (primeCount > stats[1]) {
	stats[1] = primeCount;
      }
      stats[2] = stats[2] + primeCount;
      primeCount = 0;
      startCount = i + 1;
    }
  }
  clock_t end = clock();
  double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
  printf("\nCPU execution time: %0.3lfs\n", time_spent);
  printf("Lowest frequency per %d: %d\n", COUNT_BY, stats[0]);
  printf("Highest frequency per %d: %d\n", COUNT_BY, stats[1]);
  printf("Total Primes under %d: %d\n", COUNT_TO, stats[2]);
  printf("Average frequency: %0.3lf% (to %d)\n\n", 100 * ((double) stats[2] / (double) COUNT_TO), COUNT_TO);
*/

}

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
     Lessons learned: Still might help a bit if we can continue to check up from 1 with one core and check down from n/2 with another somehow. (Hopefully learn how to in parallel programming) Kind of a divide and conquer method or something.

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

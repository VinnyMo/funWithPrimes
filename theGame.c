/* A wee prime game
   Author:     Vincent T. Mossman
   Compile by: gcc -o theGame theGame.c
   Run by:     ./theGame
*/

/* Game outline
	1. Computer selects random range of 100 naturals
	2. Player has 3 chances to find prime
	3. If incorrect guess, computer notifies distance to
	    closest prime rounded to 10.
	4. If correct guess, goto (1.)
*/


#include "primality.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//content summary
void clearScreen(void);
  /* clearScreen invokes a system call to clear the console screen for
      formatting purposes.
      */
long int display(long int, long int);
  /* display is responsible for user interface.
     */


int main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Usage: %s <followed by [NAT to test primality]>\n", argv[0]);
    exit(-1);
  }

  clearScreen();

  long int rangeLow = 100;
  long int rangeHigh = rangeLow + 100;

  long int guess;

  bool win = false;

  while(!win) {

    guess = display(rangeLow, rangeHigh);

    clearScreen();

    if (isPrime(guess)) {
      printf("You Win! %lu is prime!\n\n", guess);
      win = true;
    }
    else {
      printf("Sorry, %lu is composite. Try again\n\n", guess);
    }
  }


/*
  long int test;
  sscanf(argv[1], "%lu", &test);

  clock_t begin = clock();

  if (isPrime(test)) {
    printf("\n%lu is prime\n", test);
  }
  else {
    printf("\n%lu is composite\n", test);
  }

  clock_t end = clock();
  double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

  printf("\nCPU execution time: %0.3fs\n\n", time_spent);
*/

}

void clearScreen(void) {

  //note: system call is OS specific - non-portable
  system("clear");

}


long int display(long int low, long int high) {

  long int userGuess;

  printf("\n\n");
  printf("Find a prime number between %lu and %lu.", low, high);
  printf("\n\nYour guess: ");
  scanf("%lu", &userGuess);

  return userGuess;

}

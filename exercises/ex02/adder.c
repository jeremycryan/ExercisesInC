#include <stdio.h>
#include <stdlib.h>

/*
  Prompts the user for a number with scanf, and writes up to
  ten characters to a char pointer.

  number: char array to write to
*/
void read_inputs(char number[]) {

  printf ("Enter number: ");
  scanf ("%10s", number);

  // Give warning if buffer width is exceeded.
  int i = 0;

  while ((getchar()) != '\n') {

    if (i == 0) {
      printf ("Buffer width exceeded. Some characters have been ignored.\n");
    }

    i=1;
  }
}


/*
   Makes sure that all items in number are numbers 0-9.
   If another character is found, number is reset to 0 and
   a warning message is given.

   number - pointer to char array
*/
void check_numeric(char number[]) {

  int i = 0;

  while (1) {

    switch (number[i]) {

      //  End character means you've reached the end of the string
      case '\0': return;

      // These characters are okay
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
         break;

      // Retain EOF character if you want to exit.
      case 'D':
        number[0] = 'D';
        break;

      default:
         printf("Non-numeric input. Treating input as 0.\n");

         // Reset all of number to zeros
         for (int j = 0; j < 10; j++) {

           if (number[j] == '\0') return;
           number[j] = '0';

         }
    }
    i++;
  }
}


/*
   Prompts user to input numbers, one at a time. When the
   input is 'D', prints the sum of all added numbers.
*/

int main() {

  int nums[50];
  char new_num[10] = "000000000";
  int sum = 0;
  int i = 0;

  printf ("This program calculates the sum of several numbers.\n");
  printf ("Enter up to fifty numbers, then enter D to calculate their sum.\n");

  // Initialize nums to zeros
  for (i = 0; i < 50; i++) {
    nums[i] = 0;
  }

  i = 0;
  while (1) {

    read_inputs(new_num);
    check_numeric(new_num);
    if (new_num[0] == 'D') break;
    nums[i] = atoi(new_num);
    i++;

    if (i >= 50) {

      printf ("Maximum number of addends (50) exceeded. Calculating sum now.\n");
      break;

    }

  }

  for (i = 0; i < 50; i++) {
    sum += nums[i];
  }

  printf("The sum of your inputs is %d.\n", sum);

  return 0;
}

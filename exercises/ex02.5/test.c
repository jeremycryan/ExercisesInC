/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void strsplit(char* string, char sep, char* first, char* second) {

  int i = 0;
  int j = 0;
  int second_half = 0;
  while (string[i] != '\0') {
    if (string[i] == sep && !second_half) {

      second_half = 1;
      first[i] = '\0';
      i++;
      continue;

    }
    if (!second_half) {

      first[i] = string[i];

    } else {

      second[j] = string[i];
      j++;

    }

    i++;
  }

  second[j] = '\0';

}

int main (int argc, char *argv[])
{

    char string[] = "Blatant Marsupial.";
    char first[20] = "                   ";
    char second[20] = "                   ";

    strsplit(string, 'a', first, second);

    for (int i = 0; i < 20; i++) {
      if (first[i] == '\0') break;
      printf("%c", first[i]);
    }
    printf("%c", '\n');
    for (int i = 0; i < 20; i++) {
      if (second[i] == '\0') break;
      printf("%c", second[i]);
    }
    printf("%c", '\n');

    return 0;
}

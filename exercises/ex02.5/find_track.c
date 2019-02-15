/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern. Takes a string in the form
// [X-Y], where X is the capital English letter to start with, and Y is the
// capital English character to end the search.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    // TODO: fill this in

    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
      'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // Determine index of start character
    int start_index = 0;
    while (letters[start_index] != pattern[1]) {
      start_index++;
      if (start_index >= 26) return;
    }

    // Determine index of ending character
    int end_index = 0;
    while (letters[end_index] != pattern[3]) {
      end_index++;
      if (end_index >= 26) {
        end_index = 25;
        break;
      }
    }

    // Print each song containing that letter
    int idx = start_index;
    char a_char[26];
    int used[NUM_TRACKS];
    int used_num = 0;
    int continue_flag = 0;

    // Iterate through characters in range
    while (idx <= end_index) {
      a_char[0] = letters[idx];
      for (int i=0; i<NUM_TRACKS; i++) {

          //  Continue if you have already printed the song this call
          for (int j = 0; j < used_num; j++) {
            if (i == used[j]) continue_flag = 1;
          }
          if (continue_flag) {
            continue_flag = 0;
            continue;
          }

          // Print songs that match the character
          if (strstr(tracks[i], a_char)) {
              printf("Track %i: '%s'\n", i, tracks[i]);
              used[used_num] = i;
              used_num++;
          }
      }

      idx++;
    }

}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}

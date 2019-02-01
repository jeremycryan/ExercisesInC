/*
   This file contains code for the card-counting system described in
   Head First C.
*/

#include <stdio.h>
#include <stdlib.h>


/* Returns the value of a card, based on a 2-character input. Valid card
   strings include 'K', 'Q', 'J', 'A', and numbers 2-10. Returns 0 if input
   is invalid.
*/
int card_val(char card_name[2]) {
   int val = 0;
   switch (card_name[0]) {

      /* Queens, Kings, and Jacks are all worth ten points */
      case 'K':
      case 'Q':
      case 'J':
         return 10;

      /* Aces are worth eleven points */
      case 'A':
         return 11;

      /* Return 0 and exit loop if user tries to exit program */
      case 'X':
         return 0;

      /* Otherwise return numeric value of card, or 0 if invalid */
      default:
         val = atoi(card_name);
         if ((val < 1) || (val > 10)) {
            puts("I don't understand that value!");
            return 0;
         }
         return val;
   }
}

/* Updates the card count based on the new card's value.

   Returns 1 if the card is low (2-6)
   Returns 0 if the card is somewhere in the middle (7-9)
   Returns -1 if the card is high (10-A)

   This behaves slightly different than the Head First C code, since it counts
   2s as low cards and aces as high cards. The original program didn't do this.
*/
int count_change(int val) {

   if ((val >= 2) && (val <= 6)) {
      /* Low cards add one to the count */
      return 1;
   } else if ((val == 10) || (val == 11)) {
      /* High cards reduce the count by one */
      return -1;
   } else {
      /* Anything else doesn't affect the count */
      return 0;
   }

}


/* Runs the main loop.

   Each cycle, the user is prompted to input a card. Then, based on the card's
   value, an integer count is updated. Over time, a lower count will mean more
   high-value cards have been played, and the gambler should bet little; a high
   count means that more high-value cards are in the deck, and they can bet
   more rashly.

   The user can input 'X' to stop the program.
*/
int main()
{
    char card_name[3];
    int count = 0;
    int val;
    do {

       /* Prompt user to input a card name */
       puts("Enter the card_name: ");
       scanf("%2s", card_name);
       val = 0;

       /* Determine value of card in points */
       val = card_val(card_name);
       if (val == 0) continue;

       /* Update the count based on card value */
       count += count_change(val);

       printf("Current count: %i\n", count);

    } while (card_name[0] != 'X');
    return 0;
}

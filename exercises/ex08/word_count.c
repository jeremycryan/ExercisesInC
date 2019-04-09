/* Simple example using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/

*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

// Compares two GStrings and compares equality
gboolean str_equal(GString* a, GString* b) {
  gint16 i = 0;
  while (a->str[i] == b->str[i]) {
    if (a->str[i] == '\0') return TRUE;
    i++;
  }
  return FALSE;
}

// Returns a string hash of the string's internal string
guint str_hash(GString*a) {
  return g_str_hash(a->str);
}

// Prints an item of a hash table
void print_entry(GString* word, gint16* count) {
  printf("%s: %d\n", word->str, *count);
}

int main(int argc, char** argv) {

    // Create a new hash table to store words in
    GHashTable* hash = g_hash_table_new(str_hash, str_equal);

    //  Open Pride and Prejudice as a text file
    FILE* fp = fopen("pride_and_prejudice.txt", "r");
    gchar ch;
    gchar word_buffer[30];
    gint16 buffer_idx = 0;
    GString* word;

    // Add words to hash table as they are encountered
    while ((ch = fgetc(fp)) != EOF) {

      switch (ch) {

        // Ignore punctuation
        case '"': case '\'': case '.': case ',': case '?': case '!': case ')':
        case '_': case '”': case '“': case ':': case ';': case '-': case '(':
          break;

        // Add word to has table on newlines
        case ' ': case '\n': case '\t':

          word_buffer[buffer_idx] = g_unichar_tolower(ch);

          // Break out if empty string
          if (buffer_idx <= 1) {
            buffer_idx = 0;
            break;
          }

          // Identify whitespace as end of word
          word_buffer[buffer_idx] = '\0';
          word = g_string_new(word_buffer);
          buffer_idx++;

          // If the word already exists in the table, increment its count by 1.
          // Otherwise, set it to 1, since it's the first occurence.
          if (g_hash_table_lookup(hash, word) != NULL) {
            gint16* old_value_ptr = (gint16*)g_hash_table_lookup(hash, word);
            *old_value_ptr = *old_value_ptr + 1;
            g_hash_table_insert(hash, word, old_value_ptr);
          } else {
            gint16* new_value = malloc(sizeof(gint16*));
            *new_value = 1;
            g_hash_table_insert(hash, word, new_value);
          }

          buffer_idx = 0;
          break;

        // Update buffer on other characters
        default:
          word_buffer[buffer_idx] = g_unichar_tolower(ch);
          buffer_idx++;

      }
    }

    puts("Word counts:\n");
    g_hash_table_foreach(hash, print_entry, NULL);

    return 0;
}

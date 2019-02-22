#include <stdio.h>

int main (int argc, char **argv[])
{

  char c;
  c = getchar();
  FILE *test_files[argc];

  // Open file for each argument
  for (int i = 0; i < argc - 1; i++) {
    test_files[i] = fopen(argv[1+i], "w");
  }

  // Put characters into stdout and each file until you reach EOF char
  while(c!=EOF)  {

    for (int i = 0; i < argc - 1; i++) fputc(c, test_files[i]);

    putchar(c);
    c = getchar();

  }

  // Close all opened files.
  for (int i = 0; i < argc - 1; i++) fclose(test_files[i]);
}

/*
  It took me a while to find the right documentation for understanding
  the use case of tee. Once I understood the problem, it was relatively
  straightforward to get the code running.

  My implementation is a lot simpler than both professional ones,
  having not included option tags or error handling (were we supposed
  to?). Additionally, they partitioned the code into smaller chunks,
  and used other data structures (like enums) to make it easier to
  follow.
*/

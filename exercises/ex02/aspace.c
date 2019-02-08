/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int useless_func() {

  int a = 3;
  printf ("Address of local var a: %p\n", &a);

}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(128);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("q points to %p\n", q);
    useless_func();
    printf ("s points to %p\n", s);

    return 0;
}

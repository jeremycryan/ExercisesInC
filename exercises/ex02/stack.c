/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;

    // Foo creates an array of 42s in its local
    // memory space, then returns a pointer.
    int *array = foo();

    // Bar is allocated stack space in the same
    // spot Foo was, and overwrites the array with
    // other numbers.
    bar();

    // Attempting to print from the array in deallocated
    // stack space results in a seg fault.
    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

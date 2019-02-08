# Homework 2

### The address space

```
+-------------------+
|       Stack       |   < var2 (0x7ffd83593b14)
|       v v v       |
|                   |
|                   |
|                   |
|                   |
|       ^ ^ ^       |   < q    (0x1bb40a0)
|       Heap        |   < p    (0x1bb4010)
+-------------------+
|      Globals      |   < var1 (0x60104c)
+-------------------+
|     Constants     |   < s    (0x400764)
+-------------------+
|       Code        |
+-------------------+
```

### Stack allocated data

1) Presumably, the program was intended to create an array of size SIZE and set all of the cells to 42.

2) I got a warning for returning the address of a local variable. Foo creates an array in local memory, which is deallocated once the function call ends. No bueno.

3) I got a segmentation fault, presumably because I was trying to read from the array that no longer existed in allocated dynamic memory. When I moved the print statement to the inside of bar, it could run without an error, and printed (0, 1, 2...) instead of (42, 42, 42...).

4) The addresses for the array are the same.

### Links to other assignment pieces

Here is my [modified version of aspace.c](https://github.com/jeremycryan/ExercisesInC/blob/master/exercises/ex02/aspace.c)

Here is my [commented version of stack.c](https://github.com/jeremycryan/ExercisesInC/blob/master/exercises/ex02/stack.c).

And finally, here is my [implementation of adder.c](https://github.com/jeremycryan/ExercisesInC/blob/master/exercises/ex02/adder.c). I had a bit of trouble getting the EOF character to end the program, so I instead ended it with a 'D' input. I figured that the assignment was focused more on robust pointer use than input parsing, but other than that one change my program should meet all the requirements.

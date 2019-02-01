#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("Hello, World! %d\n", x);
    return 0;
}

/*
   After adding the line 'int x = 5', two lines were added to
   the assembly code by the compiler:

   subq	$16, %rsp
 	 movl	$5, -4(%rbp)

   After doing a couple internet searches, these lines
   appear to be moving stack pointers to whatever values are
   stored in registers 16 and 5.

   ///////////////////////////////////////////////////

   After applying optimization, a number of things changed
   about the program, and I'm not familiar enough with assembly
   to understand most of them. However, nothing resembling the
   previous two lines exists. It's possible the compiler
   "noticed" that the value of x was not used later in the
   program, and didn't allocate memory or set its value.

   ///////////////////////////////////////////////////

   Upon adding the value of x to the print statement, the
   following lines were added to the optimized assembly code:

 	 movl	$5, %edx
 	 movl	$.LC0, %esi

   Again, I'm not really knowledgeable enough about assembly
   to draw conclusions from this, but it appears to have made
   a difference to the compiler that x is used later on in the
   program. This might suggest that it "cut corners" in the
   first compile it was unable to do the second time around.

*/

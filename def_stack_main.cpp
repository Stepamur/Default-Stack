#include "def_stack_header.h" // is it working???

int main ()
{
    stack_strct pointer = {};
    pointer = StackInit ();

    StackPush (&pointer, 1);
    StackPush (&pointer, 2);
    StackPush (&pointer, 3);
    StackPush (&pointer, 4);
    StackPush (&pointer, 5);

    int popped = StackPop (&pointer);
    printf ("%d was popped \n \n", popped);

    StackPrint (&pointer);

    StackPush (&pointer, 6);
    StackPush (&pointer, 7);
    StackPush (&pointer, 8);
    StackPush (&pointer, 9);
    StackPush (&pointer, 10);

    StackPrint (&pointer);

    StackPush (&pointer, 11);
    StackPush (&pointer, 12);
    StackPush (&pointer, 13);
    StackPush (&pointer, 14);
    StackPush (&pointer, 15);

    StackPrint (&pointer);

    StackPush (&pointer, 16);
    StackPush (&pointer, 17);
    StackPush (&pointer, 18);
    StackPush (&pointer, 19);
    StackPush (&pointer, 20);
    
    StackPrint (&pointer);

    StackDtor (&pointer);


}
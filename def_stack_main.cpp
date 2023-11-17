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

    StackDtor (&pointer);


}
#include "def_stack_header.h"



//void StackDump(); // stack cheking

//void StackMul(); // multiplication

//void StackAdd(); // addition

//void StackSqrt();

//void StackSin();

//void StackCos();

//void StackIn(); //input from the keypad

//void StackHlt(); //stopping

//void StackSub(); // subtraction (/)

data_type* last_elem_ptr(stack_strct* ptr)
{
    return ptr->stack + ptr->stack_size;
};

data_type* first_elem_ptr(stack_strct* ptr) 
{
    return ptr->stack;
};

stack_strct StackInit()
{
    data_type* ptr = (data_type*)calloc(DEF_STACK_SIZE + 10, sizeof (data_type));
    size_t size = DEF_STACK_SIZE;
    assert (ptr != NULL);
    stack_strct stack = {size, 0, ptr};
    StackVrf(&stack);
    return stack;
}

void StackVrf (stack_strct* ptr)
{
    assert (ptr != NULL);

    if (ptr->stack_size <= ptr->quantity * 2)
    {
        data_type* new_ptr = (data_type*)realloc(ptr->stack, ptr->stack_size * 2 * sizeof(data_type));
        assert (new_ptr != NULL);
        ptr->stack = new_ptr;
        ptr->stack_size = ptr->stack_size * 2; 
    }

    if (ptr->stack_size >= ptr->quantity / 2)
    {
        data_type* new_ptr = (data_type*)realloc(ptr->stack, (ptr->stack_size / 2) * sizeof(data_type));
        assert (new_ptr != NULL);
        ptr->stack = new_ptr;
        ptr->stack_size = ptr->stack_size / 2;
    }

}

void StackDtor (stack_strct* ptr)
{
    // let be poison == 65535, must be enhanced lter

    for (data_type* i = first_elem_ptr(ptr);i < ptr->stack + ptr->quantity; ++i)
    {
        *(i) = 65535;
    }

    ptr->stack_size = 1;
    ptr->quantity = 0;

    free (ptr);

    ptr = NULL;

}

void StackPush (stack_strct* ptr, data_type number)
{
    StackVrf (ptr);
    *(last_elem_ptr(ptr) + 1) = number;
    ptr->quantity += 1;
}

data_type StackPop (stack_strct* ptr)
{
    data_type popped_number = *(last_elem_ptr(ptr));
    ptr->quantity -= 1;
    StackVrf (ptr);
    return (popped_number);
}

void StackPrint (stack_strct* ptr)
{
    for (data_type* i = first_elem_ptr(ptr); i < last_elem_ptr(ptr); i++)
    {
        printf ("%d \n", *i);
    }
    printf ("%lud", *size_ptr);
    printf ("%d", *quan_ptr);

}


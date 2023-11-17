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
    return ptr->stack + ptr->quantity;
};

data_type* first_elem_ptr(stack_strct* ptr) 
{
    return ptr->stack;
};

stack_strct StackInit()
{
    //stack_strct* ptr = (stack_strct*)calloc(sizeof(data_type*) + sizeof(size_t) + sizeof(int), sizeof (char));
    data_type* ptr_stck = (data_type*)calloc(DEF_STACK_SIZE + 10, sizeof (data_type));
    size_t size = DEF_STACK_SIZE;
    assert (ptr_stck != NULL);
    stack_strct stack = {size, 0, ptr_stck};
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
        //printf("Stack size was multiplied by 2, now it is %lu \n", ptr->stack_size);
    }
    else
    {
        if (ptr->stack_size >= ptr->quantity / 2)
        {
            data_type* new_ptr = (data_type*)realloc(ptr->stack, (ptr->stack_size / 2) * sizeof(data_type));
            assert (new_ptr != NULL);
            ptr->stack = new_ptr;
            ptr->stack_size = ptr->stack_size / 2;
            //printf("Stack size was divided by 2, now it is %lu \n", ptr->stack_size);
        }
    }

}

void StackDtor (stack_strct* ptr)
{
    // let be poison == 65535, must be enhanced lter

    for (data_type* i = first_elem_ptr(ptr);i < ptr->stack + ptr->quantity; ++i)
    {
        *(i) = 65535;
    }


    //
    //printf ("StackDtor runned towards freeing \n");
    //

    free (ptr->stack);

    //
    //printf ("StackDtor successfully runned through freeing \n");
    //

    ptr->stack = NULL;

}

void StackPush (stack_strct* ptr, data_type number)
{
    StackVrf (ptr);
    *(last_elem_ptr(ptr)) = number;
    ptr->quantity += 1;


    //printf("%d was added into stack \n", number);
    //StackPrint(ptr);

}

data_type StackPop (stack_strct* ptr)
{
    data_type popped_number = *(last_elem_ptr(ptr) - 1);
    //printf ("%d was popped in StackPop \n", popped_number);
    *(last_elem_ptr(ptr) - 1) = 0;
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
    printf ("Size: %lu ", ptr->stack_size);
    printf ("Quantity: %d \n \n", ptr->quantity);

}


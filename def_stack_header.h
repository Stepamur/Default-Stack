#include <stdio.h>
#include <math.h>
#include <assert.h>

#define DEF_STACK_SIZE 10

typedef int data_type;
typedef struct {
    size_t stack_size;
    int quantity; // quantity of elements in stack
    data_type* stack;
} stack_strct;

void StackDtor(stack_strct* ptr); // destroys stack, leaves poison

void StackPrint(stack_strct* ptr); // prints the stack

void StackVrf(stack_strct* ptr); // checks how many elements are in the stack now and adds memory or subtracts it

stack_strct StackInit(); // initialisation of stack

void StackPush(stack_strct* ptr, data_type number); // adding number into the stack

data_type StackPop(stack_strct* ptr); // deleting last number of stack

data_type* last_elem_ptr(stack_strct* ptr);

data_type* first_elem_ptr(stack_strct* ptr);

#define size_ptr (size_t*)((char*)ptr)
#define quan_ptr (int*)((char*)ptr + sizeof(int))


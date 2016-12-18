#ifndef  STACK_H
#define STACK_H
#include "error.h"
typedef struct
{
	int index;
	int stack[100];
}Stack;
void stack_init(Stack* stack);
void stack_push(Stack* stack, int item);
int stack_pop(Stack* stack);
int stack_is_empty(Stack* stack);

#endif // ! STACK_H

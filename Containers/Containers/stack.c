#include "stack.h"

void stack_init(Stack* stack)
{
	stack->index = -1;
}
void stack_push(Stack* stack, int item)
{
	stack->stack[++stack->index] = item;
}
int stack_pop(Stack* stack)
{
	return stack->stack[(stack->index)--];
}

int stack_is_empty(Stack* stack)
{
	if (stack->index == -1) return 1;
	else return 0;
}
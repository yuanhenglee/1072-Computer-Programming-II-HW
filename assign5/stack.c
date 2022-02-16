#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"

void push(NodePtr ptr, Stack* stack){
	ptr->next = *stack;
	*stack = ptr;
}

void pop(Stack* stack){
	Stack tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}

NodePtr top(Stack stack){
	return stack;
}

int isStackEmpty(Stack stack){
	return (!stack);
}

void deleteStack(Stack* stack){
	while(*stack)
	{
		Stack tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
int stackSize(Stack s){
	int count;
	for(count=0;s;++count)
		s=s->next;
	return count;
}

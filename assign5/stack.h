#ifndef _STACK_H_
#define _STACK_H_

#include "mystruct.h"

typedef NodePtr Stack;

/*Push an element pointed by NodePtr to Stack*/
void push(NodePtr, Stack*);

/*Pop an element from Stack*/
void pop(Stack*);

/*Return the latest element of Stack*/
NodePtr top(Stack);

/*Return true if stack is empty*/
int isStackEmpty(Stack);

/*Clean all the elements in the stack*/
void deleteStack(Stack*);

/*Return the number of the elements in the stack*/
int stackSize(Stack);

#endif

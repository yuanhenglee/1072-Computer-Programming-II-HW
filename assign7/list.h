#ifndef _LIST_H_
#define _LIST_H_

struct node;
typedef struct node Node;
typedef Node* NodePtr;
typedef NodePtr List;
typedef NodePtr Position;

struct node{
	char data;
	NodePtr next;
};

struct operation{
	int op;
	int appendlength;
	List deletebuffer;
	struct operation* next;
};

/*Returns true if a list is empty.*/
int isEmpty(List);

/*Returns true if the position is the last element of the list.*/
int isLast(Position);

/*Wrap the data and malloc a Node stores them and return*/
NodePtr createNode(char);

/*Find a specific element in a list and returns its position.*/
Position find(Node, List);

/*Insert a node after a specific position.*/
void insertNode(NodePtr, Position, List*);

/*Delete the node in specific position.*/
void deleteNode(Position, List*);

/*Returns the previous position of current position.*/
Position findPrevious(Position, List);

#endif

#ifndef _LIST_H_
#define _LIST_H_

struct node;
typedef struct node Node;
typedef Node* NodePtr;
typedef NodePtr List;
typedef NodePtr Position;

struct node{
    /*Your stuff here*/
    NodePtr next;
};

/*Returns true if elements of two nodes are equal.*/
int isEqual(Node, Node);

/*Wrap the data and malloc a Node stores them and return*/
NodePtr createNode(/* Your stuff here */);

/*Returns true if a list is empty.*/
int isEmpty(List);

/*Returns true if the position is the last element of the list.*/
int isLast(Position);

/*Find a specific element in a list and returns its position.*/
Position find(Node, List);

/*Insert a node after a specific position.*/
void insertNode(NodePtr, Position, List*);

/*Delete the node in specific position.*/
void deleteNode(Position, List*);

/*Returns the previous position of current position.*/
Position findPrevious(Position, List);

/*Delete all elements in the list.*/
void deleteList(List*);

/*You can add your own function*/
/* ... */

#endif

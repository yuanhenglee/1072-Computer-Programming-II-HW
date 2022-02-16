#ifndef _MY_STRUCT_H_
#define _MY_STRUCT_H_

struct node;
typedef struct node Node;
typedef Node* NodePtr;


struct node{
    char name[10];
    int element;
    struct node* next;
};

/*Returns true if elements of two nodes are equal.*/
int isEqual(Node, Node);

/*Wrap the data and malloc a Node stores them and return*/
NodePtr createNode( char name[], int);


#endif

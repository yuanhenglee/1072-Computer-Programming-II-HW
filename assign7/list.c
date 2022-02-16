#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int isEmpty(List l){
    return (l == NULL);
}

int isLast(Position p){
    return (p != NULL) && (p -> next == NULL);
}

/* Wrap the data and malloc a Node stores them and return */
NodePtr createNode(char data){
	NodePtr new = malloc(sizeof(NodePtr));
	new->data = data;
	new->next = NULL;
	return new;
}

/* Write the condition that two nodes are the same */
Position find(Node node, List l){
    Position tmp = l;
    while(tmp != NULL){
        if( node.data == tmp->data ){
            break;
        }
        else{
            tmp = tmp -> next;
        }
    }
    return tmp;
}

/* Given a list "l" , you have to insert a Node "ptr" behind position "p" */
void insertNode(NodePtr ptr, Position p, List* l){
    /* Write your code here */
}


void deleteNode(Position p, List* l){
    if(!isEmpty(*l)){
        Position prev = findPrevious(p, *l);
        if(prev == NULL){
            *l = p -> next;
        }
        else{
            prev -> next = p -> next;
        }
        p -> next = NULL;
        free(p);
    }
}


Position findPrevious(Position p, List l){
    Position tmp = l;
    while(tmp != NULL){
        if(tmp -> next == p){
            break;
        }
        else{
            tmp = tmp -> next;
        }

    }
    return tmp;
}


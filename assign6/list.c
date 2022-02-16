#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int isEqual(Node node1, Node node2){
}

NodePtr createNode(){
}

int isEmpty(List l){
	return (l == NULL);
}

int isLast(Position p){
	return (p != NULL) && (p -> next == NULL);
}

Position find(Node node, List l){
	Position tmp = l;
	while(tmp != NULL){
		if(isEqual(node,*(tmp))){
			break;
		}
		else{
			tmp = tmp -> next;
		}
	}
	return tmp;
}

void insertNode(NodePtr ptr , Position p, List* l){
}

void deleteNode(Position p, List* l){
}

Position findPrevious(Position p, List l){
	Position tmp = l;
	if(p==l)
		return l;
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

void deleteList(List* l){
}


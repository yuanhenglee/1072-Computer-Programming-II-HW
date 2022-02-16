#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int isEmpty(List l){
    return (l == NULL);
}

int isLast(Position p){
    return (p != NULL) && (p -> next == NULL);
}

Position find(Node node, List l){
    Position tmp = l;
    while(tmp != NULL){
        if(isEqual(node, *tmp)){
            break;
        }
        else{
            tmp = tmp -> next;
        }
    }
    return tmp;
}

void insertNode(NodePtr ptr, Position p, List* l){
    if(ptr == NULL){
        return;
    }
    if(isEmpty(*l)){
        *l = ptr;
    }
    else{
        if(p == NULL){
            ptr -> next = *l;
            *l = ptr;
        }
        else{
            ptr -> next = p -> next;
            p -> next = ptr;
        }
    }
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

void deleteList(List* l){
    Position tmp = *l;
    while(tmp != NULL){
        *l = tmp -> next;
        free(tmp);
        tmp = *l;
    }
    *l = NULL;
}

int listSize(List l){
    int size = 0;
    NodePtr tmp = l;

    while(tmp != NULL){
        ++size;
        tmp = tmp -> next;
    }

    return size;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

int isEqual(Node node1, Node node2){
    return (node1.element == node2.element) && (node1.name == node2.name);
}

NodePtr createNode( char name[], int ele){
    NodePtr ptr = malloc(sizeof(Node));
    strcpy( ptr -> name, name);
    ptr -> element = ele;
    ptr -> next = NULL;
    return ptr;
}


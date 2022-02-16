#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#define MAX_STATION_PASSENGER (8)
#define MAX_CABLE_CAR_LOAD (400)
void exportstack(Stack *root){
	while(*root){
		Stack printtop = top(*root);
		printf("%s ",printtop->name);
		pop(root);
	}
	printf("\n");
}
int main(){
	char str[999];
	int passenger=0,totalweight=0;
	Stack *elevator = NULL;
	while(scanf("%s",str)){
		if(!strcmp(str,"-1")){
			exportstack(root);
			passenger=0;
			totalweight=0;
			continue;
		}
		char name[999];
		int weight;
		sscanf(str,"%s %d",name,&weight);
		++passenger;
		totalweight+=weight;	
		if(totalweight>=MAX_CABLE_CAR_LOAD || passenger>=MAX_STATION_PASSENGER){
			exportstack(root);
			passenger=1;
			totalweight=weight;
			continue;
		}
		Stack new = createNode(name,weight);
		push(new, root);
	}
	return 0;
}


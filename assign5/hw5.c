#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#define MAX_STATION_PASSENGER (8)
#define MAX_CABLE_CAR_LOAD (400)
void exportstack(Stack *root){
	while(*root){
		printf("%s%c",top(*root)->name,(*root)->next?' ':'\n');
		pop(root);
	}
	*root=NULL;
}
void updateLastQ(Queue* LastQ,Queue q){
	*LastQ = q;
	for(int i=0;i<8 && (*LastQ);i++)
		*LastQ = (*LastQ)->next;
}
int main(){
	char str[999];
	Queue q=NULL;
	Stack s=NULL;
	Queue LastQ=NULL;
	int StackCount=0,totalweight=0;
	while(scanf("%s",str)>0){
		if(strcmp(str,"-1")==0){//if test case end -> start queue to stack
			updateLastQ(&LastQ,q);
			while(q){
				if((first(q)->element + totalweight) <= MAX_CABLE_CAR_LOAD && StackCount < MAX_STATION_PASSENGER){//check 8:400 valid
					totalweight+=first(q)->element;
					Queue tmp = q->next;
					push(first(q),&s);
					q = tmp;
					++StackCount;
					if(totalweight == 400){
						exportstack(&s);
						updateLastQ(&LastQ,q);
						StackCount=0;
						totalweight=0;
					}
				}
				else{
					//for(int i=StackCount;i<7 && tmp->next;i++ ){tmp=tmp->next;}
					if(q->next && q!=LastQ && q->next!=LastQ){
						Queue tmp=q;
						while(tmp->next!=LastQ)
							tmp=tmp->next;
						Queue beeninsert=q;
						q=q->next;
						//printf("Insert %s Between %s and %s\n",beeninsert->name,LastQ->name,tmp->next->name);
						beeninsert->next=LastQ;
						tmp->next=beeninsert;
					}
					exportstack(&s);
					updateLastQ(&LastQ,q);
					StackCount=0;
					totalweight=0;
				}
			}
			exportstack(&s);
			updateLastQ(&LastQ,q);
			deleteQueue(&q);
			s=NULL;
			StackCount=0;
			totalweight=0;
			printf("\n");
		}
		else{
			int weight=0;
			scanf("%d",&weight);
			enqueue(createNode(str,weight),&q);
		}
	}
	return 0;
}


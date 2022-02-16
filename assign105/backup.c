#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct listnode
{
	int data;
	struct listnode *nextptr;
	struct listnode *preptr;
}*head=NULL,*tail=NULL;
typedef struct listnode* Listnode;

void test(){
	while(head){
		printf("%d%c",head->data,head==tail?'\n':' ');
		head = head ->nextptr;
	}

}
void inserthead(int target)
{
	printf("insert %d to head\n",target);
	Listnode new = malloc(sizeof(Listnode));
	new->data = target;
	if(!head){
		new->nextptr = NULL;
		new->preptr = NULL;
		head = new;
		tail = new;
	}
	else{
		head->preptr = new;
		new->nextptr = head;
		head = new;
		new->preptr = NULL;
	}
		test();
}
void inserttail(int target)
{
	printf("insert %d to tail   tail: %d\n",target,tail->data);
	Listnode new = malloc(sizeof(Listnode));
	new->data = target;
	if(!tail){
		new->nextptr = NULL;
		new->preptr = NULL;
		head = new;
		tail = new;
		return;
	}
	tail->nextptr = new;
	new->preptr = tail;
	tail = new;
	tail-> nextptr = NULL;
}
int main(){
	char op1[9],op2[9];
	int target;
	while(scanf("%s%s",op1,op2)>0){
		if(strcmp(op1,"insert")==0){
			scanf("%d%*c",&target);
			if(strcmp(op2,"head")==0)
				inserthead(target);
			else
				inserttail(target);

		}
		else if(strcmp(op2,"head")==0 && head){
			Listnode tmp = head;
			head = head->nextptr;
			if(head)
				head->preptr = NULL;
			else
				tail = NULL;
			free(tmp);
			printf("delete head!");
		}
		else if(tail){
			Listnode tmp = tail;
			tail = tail->preptr;
			if(tail)
				tail -> nextptr = NULL;
			else
				head = NULL;
			free(tmp);
			printf("delete tail!");
		}
	}
	while(head){
		printf("%d%c",head->data,head==tail?'\n':' ');
		head = head ->nextptr;
	}
	return 0;
}

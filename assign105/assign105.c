#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct linklist{
	int val;
	struct linklist* next;
	struct linklist* pre;
}*head,*tail;

typedef struct linklist* Linklist;

Linklist CreatNode(int val){
	Linklist new = malloc(sizeof(Linklist));
	new->val = val;
	new->next = NULL;
	new->pre = NULL;
   return new;	
}

void InsertNode(Linklist ptr,Linklist new){
	if(!ptr){
		head = new;
		tail = new;	
	}
	else if(ptr == head){
		new->next = head;
		head->pre = new;
		head = new;
	}
	else{
		tail->next = new;
		new->pre = tail;
		tail = new;
	}
}

void DeleteNode(Linklist ptr){
	if(!ptr)
		return;
	if(head == ptr){
		if(!head->next)
			tail = NULL;
		Linklist tmp =head;
		head = head->next;
		free(tmp);
	}
	else{	
		if(!head->next)
			 head = NULL;
		Linklist tmp = tail;
		tail = tail->pre;
		free(tmp);
	}
}

void PrintList(){
	Linklist tmp = head;
	while(tmp){
		printf("%d%c",tmp->val,tmp == tail?'\n':' ');
		tmp = tmp->next;
	}
}

int main(){
	int Op,InputVal;
	printf("1: insert head\n2: insert tail\n3: delete head\n4:delete tail\n");
	while(scanf("%d%d",&Op,&InputVal)>0){
		switch(Op){
			case 1:
				InsertNode(head,CreatNode(InputVal));			
				break;
			case 2:
				InsertNode(tail,CreatNode(InputVal));			
				break;
			case 3:
				DeleteNode(head);
				break;
			case 4:
				DeleteNode(tail);
				break;
		}
		PrintList();
	}
	return 0;
}

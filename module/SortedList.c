#include <stdio.h>
#include <stdlib.h>

struct linklist{
	int val;
	struct linklist* next;
};
typedef struct linklist* LinkListPtr;

void PrintList(LinkListPtr print){
	printf("Merged Linked List is: ");
	while(print){
		printf("%d%c",print->val,print->next?' ':'\n');
		print = print ->next;
	}
}

LinkListPtr CreatNode(int val){
	LinkListPtr new = malloc(sizeof(LinkListPtr));
	new->next = NULL;
	new->val = val;
	return new;
}

LinkListPtr Merge(LinkListPtr head1,LinkListPtr head2){
	LinkListPtr res = NULL;
	if( !head1 )
		return head2;
	if( !head2 )
		return head1;

	if( head1->val < head2->val ){
		res = head1;
		res->next = Merge( head1->next, head2 );
	}
	else{
		res = head2;
		res->next = Merge( head2->next, head1 );
	}
	return res;
}

LinkListPtr FindMid(LinkListPtr head){
	LinkListPtr fast = head->next;
	LinkListPtr slow = head;
	while( fast ){
		fast = fast->next;
		if( fast ){
			fast = fast->next;
			slow = slow->next;
		}
	}
	LinkListPtr NewHead2 = slow->next;
	slow->next = NULL;
	return NewHead2;
}

void mergesort(LinkListPtr *headPtr){
	if( !*headPtr || !( *headPtr )->next )
		return;
	LinkListPtr NewHead1 = *headPtr;  
	LinkListPtr NewHead2 = FindMid( *headPtr );  

	mergesort( &NewHead1 );
	mergesort( &NewHead2 );

	*headPtr = Merge(NewHead1,NewHead2);	
}

void push(LinkListPtr *head, int new_data) 
{ 
	LinkListPtr new = malloc(sizeof( LinkListPtr )); 
	new->val = new_data; 
	new->next = *head; 
	*head = new; 
}

int main() 
{ 
	LinkListPtr head = NULL; 
	int input;
	while(scanf("%d",&input)>0)
		push(&head, input); 

	mergesort(&head); 
	PrintList(head);

	return 0;
}

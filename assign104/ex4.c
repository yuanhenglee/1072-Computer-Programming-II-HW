#include<stdio.h>
#include<stdlib.h>
struct Linklist
{
	int val;
	struct Linklist *prePtr;
	struct Linklist *nextPtr;
};
int main(){
	int target,temp;
	scanf("%d",&target);
	struct Linklist *head=malloc(sizeof(struct Linklist));
	struct Linklist *Ptr=head;
	while(scanf("%d",&temp)>0)
	{
		struct Linklist *new=malloc(sizeof(struct Linklist));
		new->val=temp;
		Ptr->nextPtr=new;
		new->prePtr=Ptr;
		Ptr=Ptr->nextPtr;
	}
	Ptr->nextPtr=NULL;
	while(--target)
		Ptr=Ptr->prePtr;	
	Ptr->prePtr->nextPtr=Ptr->nextPtr;	
	head=head->nextPtr;
	while(head->nextPtr)
	{
		printf("%d ",head->val);
		head=head->nextPtr;
	}
	printf("%d\n",head->val);
	return 0;
}

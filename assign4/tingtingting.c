#include<stdio.h>
#include<stdlib.h>
struct charnode
{
	char val;
	struct charnode *nextPtr;
};

int main()
{
	char c;
	int i=0;
	struct charnode *nodePtr = malloc(sizeof(struct charnode));
	struct charnode *head = nodePtr;
	while(scanf("%c",&c)>0)
	{
		nodePtr->val=c;
		struct charnode *new = malloc(sizeof(struct charnode));
		nodePtr->nextPtr=new;			
		nodePtr=nodePtr->nextPtr;
	}
	nodePtr->nextPtr=NULL;
	while(head)
	{
			printf("%c",head->val);
			head=head->nextPtr;
	}
	return 0;
}

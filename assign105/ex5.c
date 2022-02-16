#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct charnode
{
	int val;
	struct charnode *nextPtr;
	struct charnode *prePtr;
};
void test(struct charnode *head){
}
int main()
{
	struct charnode *head=malloc(sizeof(struct charnode));
	struct charnode *tail=malloc(sizeof(struct charnode));
	head->val='[';
	head->prePtr=NULL;
	head->nextPtr=tail;
	tail->val=']';
	tail->prePtr=head;
	tail->nextPtr=NULL;
	char op1[9],op2[9];
	int target;
	while(scanf("%s%s",op1,op2)>0)
	{
		if(!strcmp(op1,"insert"))
		{
			scanf("%d",&target);
			if(!strcmp(op2,"head"))
			{
				struct charnode *new = malloc(sizeof(struct charnode));
				new->val = target;
				new->nextPtr = head->nextPtr;
				new->prePtr = head;
				head->nextPtr->prePtr = new;
				head->nextPtr = new;
			}
			else
			{
				struct charnode *new = malloc(sizeof(struct charnode));
				new->val = target;
				new->nextPtr = tail;
				tail->prePtr->nextPtr = new;
				new->prePtr = tail->prePtr;
				tail->prePtr = new;
			}

		}
		else if(!strcmp(op2,"head") && head->nextPtr!=tail)
		{
			struct charnode *tmp = head->nextPtr;
			head->nextPtr = tmp->nextPtr;
			tmp->nextPtr->prePtr = head;
			free(tmp);	
		}
		else if( head->nextPtr!=tail)
		{
			struct charnode *tmp = tail->prePtr;
			tail->prePtr = tmp->prePtr;
			tmp->prePtr->nextPtr = tail;
			free(tmp);	
		}
	}
	while(head->nextPtr->nextPtr)
	{
		printf("%d%c",head->nextPtr->val,head->nextPtr->nextPtr==tail?'\n':' ');
		head=head->nextPtr;
	}
	return 0;
}

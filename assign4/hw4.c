#include<stdio.h>
#include<stdlib.h>
struct charnode
{
	char val;
	struct charnode *nextPtr;
	struct charnode *prePtr;
};

int main()
{
	char str[999];
	while(scanf("%s",str)>0)
	{
		struct charnode *head=malloc(sizeof(struct charnode));
		struct charnode *tail=malloc(sizeof(struct charnode));
		struct charnode *cur=tail;
		head->val='[';
		head->prePtr=NULL;
		head->nextPtr=cur;
		tail->val=']';
		tail->prePtr=head;
		tail->nextPtr=NULL;
		for(int i=0;str[i]!='\0';i++)
		{
			struct charnode *new=malloc(sizeof(struct charnode));
			switch(str[i])
			{
				case '[':
					cur=head->nextPtr;
					//printf("home,");
					break;
				case ']':
					cur=tail;
					break;
				case '^':
					if(cur->prePtr && cur->prePtr->prePtr)
					{
					cur->prePtr->prePtr->nextPtr=cur;
						cur->prePtr=cur->prePtr->prePtr;
					
					}
					//printf("backspace,");
					break;
				default:
					new->val=str[i];
					new->nextPtr=cur;
					new->prePtr=cur->prePtr;
					cur->prePtr->nextPtr=new;
					cur->prePtr=new;
					//		printf("%c,",c);
					break;
			}
		free(new);
		}
		while(head->nextPtr->nextPtr)
		{
			printf("%c",head->nextPtr->val);
			head=head->nextPtr;
		}
		printf("\n");
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct treeNode
{
	struct treeNode* left;
	int data;
	struct treeNode* right;
};

struct treeNode* root = NULL;
void insert(struct treeNode **ptr, int value)
{
	if(*ptr == NULL)
	{
		*ptr = malloc(sizeof(struct treeNode));

		(*ptr) -> data = value;
		(*ptr) -> left = NULL;
		(*ptr) -> right = NULL;
	}
	else
	{
		if(value < (*ptr) -> data)
			insert( &((*ptr) -> left), value);
		else
			insert( &((*ptr) -> right), value);
	}
}

void preOrder(struct treeNode *ptr)
{
	printf("(");
	if(ptr != NULL)
	{
		printf("%d ", ptr -> data);
		preOrder(ptr -> left);
		preOrder(ptr -> right);
	}
	printf(") ");
}

int fromRootToLeaf(struct treeNode *ptr, int sum)
{
	if(!ptr -> left && !ptr -> right)
		return sum + ptr -> data;

	if(!ptr -> left)
		fromRootToLeaf(ptr -> right, sum + ptr -> data);
	else if(!ptr -> right)
		fromRootToLeaf(ptr -> left, sum + ptr -> data);
	else
	{
		int leftOrRight = rand() % 2; // randomly go to left or right.

		if(leftOrRight)
			fromRootToLeaf(ptr -> left, sum + ptr -> data);
		else
			fromRootToLeaf(ptr -> right, sum + ptr -> data);
	}
}

int main()
{
	srand(time(NULL));
	for( int i=0;i < 20;++i ){
		int numberOfNode = 10;
		while(numberOfNode--)
		{
			int value = rand() % 100 + 1;
			insert(&root, value);
		}

		printf("%d ", fromRootToLeaf(root, 0));
		preOrder(root);
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BIGBIG 30

struct treenode;
typedef struct treenode TreeNode;
typedef TreeNode* TreeNodePtr;

struct treenode{
	int val;
	TreeNodePtr parent;

};


TreeNode* nodelist[BIGBIG];
int checkloop[BIGBIG];
int stack;

TreeNode* creatnode( int val){
	TreeNodePtr new = malloc( sizeof( TreeNode ) );
	new->val = val;
	new->parent = NULL;
	return new;
}

TreeNode* findlast( TreeNode* node ,int ogval){
	//printf("%d",node->val);
	if( !node->parent ){
	//	printf("%d\n",node->val);
		return node;
	}
			
	for(int i = 0; i < stack; ++i )
		if( checkloop[i] == node->val )
			return 1;
	checkloop[stack] = node->val;
	++stack;

	return findlast( node->parent,ogval );
}

void freeall(){
	for(int i = 1; i < BIGBIG; ++i ){
		free(nodelist[i]);
		nodelist[i] = NULL;
	}
}

int main(){
	int casecount = 1;
	while(1){
		int a=0,b=0,IsTree = 1;
		while(1){
			scanf("%d%d",&a,&b);
			if( a == 0 && b == 0 )
				break;
			if( a ==-1 && b == -1 )
				break;
			if( a == b )
				IsTree = 0;
			if( nodelist[b] && nodelist[b]->parent )
				IsTree = 0;
			if( !nodelist[a] )
				nodelist[a] = creatnode(a);		
			if( !nodelist[b] )
				nodelist[b] = creatnode(b);
			nodelist[b]->parent = nodelist[a];	
		}

		TreeNodePtr root = NULL;
		for(int i = 1; i < BIGBIG; ++i ){
			if( nodelist[i] ){
				stack = 0;
				memset(checkloop,0,BIGBIG);
				if( !root )
					 root = findlast( nodelist[i],0 );
				else if( findlast( nodelist[i],0 ) != root || root == 1 ){
					IsTree = 0;
					break;
				}
			}
		}

		if( a ==-1 && b == -1 )
			break;
		if( IsTree )
			printf("Case %d is a tree.\n",casecount);
		else 
			printf("Case %d is not a tree.\n",casecount);
		++casecount;
		freeall();
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int max(int a,int b){
	return a>b?a:b;
}

struct treenode;
typedef struct treenode Treenode;
typedef Treenode* TreenodePtr;

struct treenode{
	int val;
	int sum;
	TreenodePtr left,mid,right;
};

TreenodePtr creatnode( int val ){
	//if( !val )
	//	return NULL;
	TreenodePtr new = malloc( sizeof(Treenode) );
	new->val = val;
	new->sum = 0;
	new->left = NULL;
	new->mid = NULL;
	new->right = NULL;
	return new;
}

int findsum( TreenodePtr root, int *res ){
	if( !root )
		return 0;
	
	int left = findsum( root->left, res );
	int mid = findsum( root->mid, res );
	int right = findsum( root->right, res );

	int nodemax = ( root->val + left + mid + right );
	*res = max( nodemax,*res );

	printf("nodemax of %d :%d\n",root->val,nodemax);

	return max( nodemax,0 );
}

void pathsum(){
	TreenodePtr input[999];
	int val,i = 0,res = INT_MIN;
	while( scanf("%d%*c",&val) > 0 ){
			input[i] = creatnode( val );
			++i;
	}
	for( int j = 0 ; ( 3*j+3 ) < i ; ++j ){
		input[j]->left = input[3*j+1];
		input[j]->mid = input[3*j+2];
		input[j]->right = input[3*j+3];
//		printf("%d:\t%d\n\t%d\n\t%d\n\n",input[j]->val,input[j]->left->val,input[j]->mid->val,input[j]->right->val);
	}
	findsum( input[0],&res );
	printf("%d\n",res );


}

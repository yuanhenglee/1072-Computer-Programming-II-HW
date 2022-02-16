#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>


//q1:
void MergeLists(){
	int firstlen,secondlen;
	int *First,*Second,Result[999];
	int stack = 0;

	scanf("%d",&firstlen);
	First = malloc( sizeof(int) * firstlen );
	for( int i = 0; i < firstlen; ++i )
		scanf("%d",First + i);

	scanf("%d",&secondlen);
	Second = malloc( sizeof(int) * secondlen );
	for( int i = 0; i < secondlen; ++i )
		scanf("%d",Second + i);

	if( !firstlen && !secondlen )
		return;

	while( firstlen > 0 || secondlen > 0){

		if( secondlen <= 0 ){
			Result[stack] = *First;
			First += 1;
			--firstlen;
		}
		else if( firstlen <= 0 ){
			Result[stack] = *Second;
			Second += 1;
			--secondlen;
		}
		else if( *First < *Second ){
			Result[stack] = *First;
			First += 1;
			--firstlen;
		}
		else{
			Result[stack] = *Second;
			Second += 1;
			--secondlen;
		}
		++stack;
	}

	for( int i = 0; i < stack-1; ++i )
		printf("%d ",Result[i]);
	printf("%d\n",Result[stack-1]);

}

//q2:
void FLOWFLOW( int CanUP,int N,int M,int i,int j,int gen,int **tubetable,int **Result ){
	if( i == N || i < 0 || j == M || j < 0 || tubetable[i][j] == 0 || ( tubetable[i][j] == 'v' && Result[i][j] <= gen ))//TODO case:order conflict??
		return;

	Result[i][j] = gen;
	tubetable[i][j] = 'v';

	FLOWFLOW( CanUP,N,M,i+1,j,gen + 1,tubetable,Result );
	FLOWFLOW( CanUP,N,M,i,j+1,gen + 1,tubetable,Result );
	FLOWFLOW( CanUP,N,M,i,j-1,gen + 1,tubetable,Result );
	if( CanUP == 1 )
		FLOWFLOW( CanUP,N,M,i-1,j,gen + 1,tubetable,Result );
}


void PourWater(){
	int casecount = 1;
	while( 1 ){
		int CanUP,N,M;
		scanf("%d",&CanUP);
		if( CanUP == -1 )
			return;
		scanf("%d%d",&N,&M);
		int **tubetable = calloc( N,sizeof(int*) );
		int **Result = calloc( N, sizeof(int*) );
		for( int i = 0; i < N; ++i ){
			tubetable[i] = calloc(M,sizeof(int) );
			Result[i] = calloc(M,sizeof(int) );
			for( int j = 0; j < M; ++j )
				scanf("%d",&tubetable[i][j]);
		}

		for( int j = 0; j < M; ++j )
			if( tubetable[0][j] == 1 )
				FLOWFLOW( CanUP,N,M,0,j,1,tubetable,Result );

		printf("Case %d:\n",casecount);
		for( int i = 0; i < N; ++i ){
			for( int j = 0; j < M; ++j )
				printf("%d ",Result[i][j]);
			printf("\n");
		}
		++casecount;
	}
}

//q3:
void CommonSubstring(){
	char str1[999],str2[999];
	scanf("%s%s",str1,str2);
	char result[999] = "z";
	int maxlen = -1;
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for( int i = 0; i < len1; ++i )
		for( int j = 0; j < len2; ++j )
			if( str1[i] == str2[j] ){
				int stack = 0;
				char tmp[999];
				for( int k = 0; k + j < len2 && k + i < len1 && str1[i+k] == str2[j+k] ; ++k ){
					tmp[stack] = str1[i+k];
					++stack;
				}
				tmp[stack] = '\0';
				if( stack > maxlen || ( stack == maxlen && strcmp(tmp,result) > 0 )){
					strcpy(result,tmp);
					maxlen = stack;
				}
			}
	if( maxlen > 0 )
		printf("%d %s\n",maxlen,result);
}

//q4:

int max(int a,int b){
	return a>b?a:b;
}

struct treenode;
typedef struct treenode Treenode;
typedef Treenode* TreenodePtr;

struct treenode{
	int val;
	TreenodePtr left,mid,right;
};

TreenodePtr creatnode( int val ){
	//if( !val )
	//	return NULL;
	TreenodePtr new = malloc( sizeof(Treenode) );
	new->val = val;
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

	//	printf("nodemax of %d :%d\n",root->val,nodemax);

	return max( nodemax,0 );
}

void pathsum(){
	TreenodePtr input[999];
	int val,i = 0,res = INT_MIN;
	char tmpchar;
	while( scanf("%d%c",&val,&tmpchar) > 0 ){
		input[i] = creatnode( val );
		++i;
		if( tmpchar == '\n' )
			break;
	}
	
	int parent = 0, child = 1;
	for( ;child < i; ++parent ){
		if( input[parent]->val == 0 )
			continue;
		input[parent]->left = input[child++];	
		input[parent]->mid = input[child++];	
		input[parent]->right = input[child++];	
	}
	
	findsum( input[0],&res );
	printf("%d\n",res );


}
int main(int argc, char *argv[]){
	int menu = 0;
	int quit = 0;
	while(!quit){
		printf( "=======MENU=========\n"
				"1 - Merge two lists\n"
				"7 - EXIT\n"
				"====================\n"
				"Enter Your choice:\n");
		scanf("%d", &menu);
		getchar();
		switch( menu ){
			case 1:
				MergeLists();
				break;
			case 2:
				PourWater();
				break;
			case 3:
				CommonSubstring();
				break;
			case 4:
				pathsum();
				break;
			case 7:
				quit = 1;
				break;
			default:
				printf("Wrong choice!\n");
				break;
		}
		printf("\n");
	}

	return 0;
}

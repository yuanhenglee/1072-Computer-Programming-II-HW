#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BIGBIG 999

int node[ BIGBIG ];

int IsTree(){
	int root = 0;
	int zero = 1;
	for( int i = 0; i < BIGBIG; ++i ){	
		if( node[i] != 0 )
			zero  = 0;
		if( node[i] > 2 )
			return 0;
		if( node[i] == 1 )
		{
			++root;
			if( root > 1)
				return 0;
		}
	}
	if( zero )
		return 1;
	return root;

}

void test(){
	for( int i = 0 ;i<10; ++i )
		printf("%d",node[i]);
	printf("\n");
	
}


int main(){
	int casecount = 1;
	while(1){
		int a=0,b=0;
		memset( node,0,BIGBIG );
		while(1){
			scanf("%d%d",&a,&b);
			if( a == 0 && b == 0 )
				break;
			if( a ==-1 && b == -1 )
				break;
			
			if( a == b )
				node[a] = 3;
			if( node[a] == 0 )
				node[a] = 1;
			if( node[b] == 0 )
				node[b] = 1;
			++node[b];
			
//			printf("now scan: %d %d\n",a,b);


		}


		if( a ==-1 && b == -1 )
			break;
		if( IsTree() )
			printf("Case %d is a tree.\n",casecount);
		else 
			printf("Case %d is not a tree.\n",casecount);
//		test();
		++casecount;

	}
	return 0;
}

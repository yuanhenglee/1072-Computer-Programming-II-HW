#include <stdio.h>
#include <stdlib.h>

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
			tubetable[i] = malloc(sizeof(int) * M);
			Result[i] = malloc(sizeof(int) * M);
			for( int j = 0; j < M; ++j )
				scanf("%d",&tubetable[i][j]);
		}
		
		for( int j = 0; j < M; ++j )
			if( tubetable[0][j] == 1 )
			FLOWFLOW( CanUP,N,M,0,j,1,tubetable,Result );

		printf("Case %d:\n",casecount);
		for( int i = 0; i < N; ++i )
			for( int j = 0; j < M; ++j )
				printf("%d%c",Result[i][j],j == M-1?'\n':' ');
		++casecount;
	}
}

int main(){
	PourWater();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

void PourWater(){
	int CanUP,N,M;
	scanf("%d%d%d",&CanUP,&N,&M);
	int **Result = malloc(sizeof(int*) * N);
		for( int i = 0; i < M; ++i )
			Result[i] = malloc(sizeof(int) * M);
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < M; ++j )
			scanf("%d",&Result[i][j]);

	for( int i = 0; i < N; ++i )
		for( int j = 0; j < M; ++j )
			printf("%d%c",Result[i][j],j == M-1?'\n':' ');
}

void MergeLists(){
	int firstlen,secondlen;
	int *First,*Second,Result[999];
	int stack;

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

int main(){
	PourWater();
	return 0;
}


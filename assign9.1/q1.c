#include <stdio.h>
#include <stdlib.h>

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

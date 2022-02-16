#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SWAP(x,y) {int t;t=x;x=y;y=t;}

int partition(int number[], int left, int right) { 
	int i = left - 1; 
	int j;
	for(j = left; j < right; j++) { 
		if(number[j] <= number[right] || j == right) { 
			i++; 
			SWAP(number[i], number[j]); 
		} 
	} 

	SWAP(number[i+1], number[right]); 
	return i+1; 
} 


void quickSort(int number[], int left, int right) { 
	if(left < right) { 
		int q = partition(number, left, right); 
		quickSort(number, left, q-1); 
		quickSort(number, q+1, right); 
	} 
} 

void caseone(){
	while(1){
		int list[999];
		int i = 0 ;
		char tmpchar;
		while( 2 ){
			scanf("%d%c",&list[i],&tmpchar) ;
			//	printf("d:%d.c:%c\n",list[i],tmpchar);
			++i;
			if( tmpchar == '\n' )
				break;
		}
		if( list[0] == -1 )
			break;
		quickSort(list, 0 , i-1 );

		/*
		   for( int j = 0; j < i ; ++j )


		   for( int k = 0 ; k < i - j; ++k )
		   if( list[k] > list[k+1] )
		   SWAP(list[k],list[k+1]);
		 */
		for( int j = 0; j < i ; ++j )
			printf("%d ",list[j]);
		printf("\n");
	}

}




void casetwo(){
	int edge;
	scanf("%d",&edge);
	int *list = calloc(9999,sizeof(int));
	int biginput = 0;
	for( int i = 0;i < edge;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		list[a] = b;
		if( a> biginput )
			biginput = a;
		if( b> biginput )
			biginput = b;
	}
	int max = 0;
	//printf("e:%d\n",edge);

	for( int i = 0; i <= biginput ; ++i ){
		int index = i;
		int sum = 1;


		while( list[index] != 0 ){
			index = list[index];
			//		printf("%d->%d\n",index,list[index]);
			++sum;
		}

		if( sum > max )
			max = sum;

	}
	printf("%d\n",max);
}

void casethree(){
	int count = 0;
	int input[599];
	char tmpchar;
	while( scanf("%d%c",&input[count],&tmpchar) > 0 ){
		count++;
		if( tmpchar == '\n' )
			break;
	}
	--count;
	int res[599];
	if( count == 0 )
		res[0] = -1;
		
	for( int i = 0 ;i < count; ++i ){
		int max = input[i];
		int flag = 0;
		for( int j = 0 ; j < count ;++j ){

			int next; 
			if( i+j > count )
				next = input[(i+j)%count];
			else
				next = input[i+j];

			if(next > max){
				max = next;
				flag = 1;
		//		printf("best for %d:%d\n",i,max);
				break;
			}

		}
		if( !flag )
			res[i] = -1;
		else
		res[i] = max;

	}
	res[count] = res[0];

	for( int i = 0 ;i <= count; ++i )
		printf("%d ",res[i]);
	printf("\n");
	
}

void fincode( int target, int step, int R, int *buttom ){
	


}

void casefour(){
	int L,U,R;
	int i = 0;
	while( ++i ){
		scanf("%d%d%d",&L,&U,&R);
		if( L == U && U == R )
			return;
		int *buttom = calloc( R,sizeof(int) );
		for( int i = 0; i < R; ++i ){
			scanf("%d",buttom[i]);
		}
		printf("Case %d:",i);
		findcode( (U-L+10000 )%10000,0,R,buttom);



	}
}


int main(int argc, char *argv[]){
	int menu = 0;
	int quit = 0;
	while(!quit){
		printf( "=======MENU=========\n"
				"1 - Sort\n"
				"2 - The Longest Path\n"
				"3 - The Next Bigger Number\n"
				"4 - Unlock the Lock\n"
				"5 - The Sultan's Successors\n"
				"7 - EXIT\n"
				"====================\n"
				"Enter Your choice:\n");
		scanf("%d", &menu);
		getchar();
		switch( menu ){
			case 1:{
					   /* write Problem A's solution here */
					   caseone();
					   break;
				   }
			case 2:{
					   /* write Problem B's solution here */
					   casetwo();
					   break;
				   }
			case 3:{
					   /* write Problem C's solution here */
					   casethree();
					   break;
				   }
			case 4:{
					   /* write Problem D's solution here */
					   casefour();
					   break;
				   }
			case 5:{
					   /* write Bonus' solution here */
					   casetwo();
					   break;
				   }
			case 6:{
					   /* write Union Set Operator function solution here */
					   casetwo();
					   break;
				   }
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

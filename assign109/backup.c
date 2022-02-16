#include <stdio.h>
#include <math.h>

int GetExp( char *num ){
	int sum = 0;
	int two = 64;
	for( int i = 0 ; i < 7 ; ++i ){
		sum+=( ( num[i]-'0' ) * two);
		two/=2;	
	}
	return pow(2,sum - 63);
}

double GetMantissa( char *num ){
	double sum = 0;
	double two = 0.5;
	for( int i = 0 ; i < 8 ; ++i ){
		sum+=( ( num[i]-'0' ) * two);
		two/=2;	
	}
	return sum + 1;

}

int main(){
	char num[17];
	while( scanf("%s",num) > 0 ){
		if( num[0] == '0' )
			printf(" ");
		else
			printf("-");
	
			

		printf("%8.6le\n",GetMantissa( &num[8] ) * GetExp( &num[1] ) );

	}

   return 0;
}

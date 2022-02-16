#include <stdio.h>
#include <math.h>
#include <string.h>

double GetExp( char *num ){
	double sum = 0;
	int two = 64;
	for( int i = 0 ; i < 7 ; ++i ){
		sum+=( ( num[i]-'0' ) * two);
		two/=2;	
	}
	return pow(2,sum - 63 - 8 );
}

double GetMantissa( char *num ){
	double sum = 0;
	double two = 128;
	for( int i = 0 ; i < 8 ; ++i ){
		sum+=( ( num[i]-'0' ) * two);
		two/=2;	
	}
	return sum + 256;

}

int main(){
	char num[17];
	while( scanf("%s",num) > 0 ){
		if( strcmp( &num[1],"000000000000000" ) == 0 ){
			printf(" 0.000000e+000\n");		
			continue;
		}
		if( num[0] == '0' )
			printf(" ");
		else
			printf("-");
		
		char res[17];
		sprintf(res,"%le",GetMantissa( &num[8] ) * GetExp( &num[1] ) );
		
		if( res[12] == '\0' ){
			res[13] = '\0';
			res[12] = res[11];
			res[11] = res[10];
			res[10] = '0';
		}

		printf("%s\n",res);
	}

   return 0;
}

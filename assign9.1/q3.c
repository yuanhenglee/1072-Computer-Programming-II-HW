#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CommonSubstring(){
	char str1[999],str2[999];
	scanf("%s%s",str1,str2);
	char result[999] = "z";
	int maxlen = 1;
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
				if( stack > maxlen  || ( stack == maxlen && *tmp < *result )){
					strcpy(result,tmp);
					maxlen = stack;
				}
			}
	printf("%d %s\n",maxlen,result);
}

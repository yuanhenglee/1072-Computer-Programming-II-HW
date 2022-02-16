#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "q1.c"
#include "q2.c"
#include "q3.c"
#include "q4.c"

int main(){
	int OP;
	while( scanf("%d",&OP) > 0 ){
		switch(OP){
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
		}
	}
	
	return 0;
}


#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){
	int a ;
	scanf("%d",&a);
	srand(time(NULL));
	while(a--){
		int d1,d2,channel,price;
		d1 = rand()%365 +1;
		d2 = d1 + rand()%(365-d1);
		channel = rand()%4 +1;
		price = rand()%91 +10;
		char str[7];
		switch(rand()%4){
			case 0:
				strcpy(str,"CHT");
				break;
			case 1:
				strcpy(str,"FET");
				break;
			case 2:
				strcpy(str,"TWM");
				break;
			case 3:
				strcpy(str,"T-STAR");
				break;
			case 4:
				strcpy(str,"APTG");
				break;
		}
		printf("%s %d %d %d %d\n",str,d1,d2,channel,price);

	}
	return 0;
}


# include <stdio.h>
int input;
char str[999];
void printcombination(int a,int b,int steps)
{
	if(!a && !b)
	{
		printf("%s\n",str);
		return;
	}
	if(b>=a)
	{
		if(a)
		{
			str[steps]='(';
			printcombination(a-1,b,steps+1);
		}
		if(b)
		{
			str[steps]=')';
			printcombination(a,b-1,steps+1);
		}
	}
}
int main() {
	while(scanf("%d",&input)>0)
	{
		str[2*input]='\0';
		printcombination(input,input,0);		
	}
	return 0;
}

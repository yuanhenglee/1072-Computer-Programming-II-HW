# include <stdio.h>
int input;
void printcombination(int a,int b,int steps)
{
	if(!a && !b)
	{
		printf("\n");
		return;
	}
	if(steps==1)
	{
		printf("(");
		printcombination(a-1,b,steps+1);
	}
	else 
	{
		if(a)
		{
			printf("(");
			printcombination(a-1,b,steps+1);
		}
		if(b>1 || (!a && b==1))
		{
			printf(")");
			printcombination(a,b-1,steps+1);
		}
	}
}
int main() {
	while(scanf("%d",&input)>0)
		printcombination(input,input,1);		
	return 0;
}

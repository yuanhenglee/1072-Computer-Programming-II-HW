#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int findsum(int *stick,int wanted,int sticknum)
{
	for(int i=sticknum-1;i>=0;i--)
	{
		if(stick[i]==0)
			continue;
		if(stick[i]==wanted || findsum(stick,wanted-stick[i],i))
		{
			stick[i]=0;
			return 1;
		}
	}

	return 0;
}
int main()
{
	int testnum;
	scanf("%d",&testnum);
	if(!testnum)
			printf("no\n");
	for(int i=0;i<testnum;i++)
	{
		int sticknum,sum=0,goal=4,flag=1;
		scanf("%d",&sticknum);
		int stick[9999];
		for(int j=0;j<sticknum;j++)
		{
			scanf("%d",&stick[j]);
			sum+=stick[j];	
		}//check
		if(sticknum<4)
		{
			printf("no\n");
			continue;		
		}
		if(sum%4)
		{
			printf("no\n");
			continue;	
		}
		sum/=4;
		for(int j=0;j<sticknum-1;j++)
			for(int k=j+1;k<sticknum-j;k++)
				if(stick[j]<stick[k])
					swap(&stick[j],&stick[k]);
		if(stick[0]>sum)
		{
			printf("no\n");
			continue;	
		}
		for(int j=0;j<sticknum && goal>0;j++)
		{
			if(stick[j]==0)
				continue;
			if(stick[j]==sum)
			{				
				stick[j]=0;
				goal--;
				continue;
			}
			if(findsum(stick,sum-stick[j],sticknum) && goal>0)
			{				
				stick[j]=0;
				goal--;
				continue;
			}
			flag=0;
		}
		if(flag && goal==0)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}

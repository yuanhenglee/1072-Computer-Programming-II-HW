#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#define TABLELEN 40
#define TABLEWID 45
#define CENTERLEN 15
#define CHECKMORE (steps-StepsRemain+1) 
void testprint(int **GoTable)
{
/*		for(int k=0;k<TABLELEN;k++)
		{
		for(int l=0;l<TABLEWID;l++)
		printf("%d ",GoTable[k][l]);
		printf("\n");
		}
		printf("-------------------------------------\n");
*/		
}
int p=0,h=0,e=0,steps,ogmaxlen=CENTERLEN,allstone;
int checkwin(int **GoTable,int StepsRemain,int StoneColor,int i,int j);
void checknearby(int **GoTable,int StepsRemain,int StoneColor,int i,int j);
void TakeStep(int **GoTable,int StepsRemain,int StoneColor);
int main()
{
	int blackcount=0,whitecount=0;
	int **GoTable = (int **)malloc(TABLELEN * sizeof(int *)); 
	for (int j=0; j<TABLELEN; j++) 
		GoTable[j] = (int *)malloc(TABLEWID * sizeof(int)); 
	char str[16];
	scanf("%d",&steps);
	while(scanf("%s",str)>0)
	{
		if(str[0]=='=')
			continue;
		for(int j=0;str[j]!='\0';j++)
		{
			switch(str[j])
			{
				case 'B':
					GoTable[ogmaxlen][j+CENTERLEN]=1;
					blackcount++;
					break;
				case 'W':
					GoTable[ogmaxlen][j+CENTERLEN]=-1;
					whitecount++;
					break;
			}
		}
		ogmaxlen++;
	}
	allstone=blackcount+whitecount;
	TakeStep(GoTable,steps,blackcount>whitecount?-1:1);
	printf("%d %d %d\n",p,h,e);
	return 0;
}
int checkwin(int **GoTable,int StepsRemain,int StoneColor,int i,int j)
{//win=>0 recursive=>1

	if((allstone+CHECKMORE)<9/* && StepsRemain!=0*/)
	{
		if(StepsRemain==0)
		{		
			e++;
			return 0;
		}
		return 1;
	}
	int hoz=1,vtc=1,dia=1,rdia=1;
	//hoz
	for(int count=1;GoTable[i][j+count]==StoneColor;count++)
		hoz++;
	for(int count=1;GoTable[i][j-count]==StoneColor;count++)
		hoz++;
	if(hoz>4)
	{
		(StoneColor==1?p++:h++);
		return 0;
	}
	//vtc
	for(int count=1;GoTable[i+count][j]==StoneColor;count++)
		vtc++;
	for(int count=1;GoTable[i-count][j]==StoneColor;count++)
		vtc++;	
	if(vtc>4)
	{
		(StoneColor==1?p++:h++);
		return 0;
	}
	//dia
	for(int count=1;GoTable[i+count][j+count]==StoneColor;count++)
		dia++;
	for(int count=1;GoTable[i-count][j-count]==StoneColor;count++)
		dia++;
	if(dia>4)
	{
		(StoneColor==1?p++:h++);
		return 0;
	}
	//rdia
	for(int count=1;GoTable[i-count][j+count]==StoneColor;count++)
		rdia++;
	for(int count=1;GoTable[i+count][j-count]==StoneColor;count++)
		rdia++;
	if(rdia>4)
	{
		(StoneColor==1?p++:h++);
		return 0;
	}
	if(StepsRemain==0)
	{	
		e++;
		return 0;
	}
	return 1;
}
void TakeStep(int **GoTable,int StepsRemain,int StoneColor)
{
	for(int i=CENTERLEN-CHECKMORE;i<ogmaxlen+CHECKMORE;i++)
		for(int j=CENTERLEN-CHECKMORE;j<TABLEWID-CENTERLEN+CHECKMORE;j++)
			if(GoTable[i][j]==0 && (GoTable[i+1][j]!=0 ||GoTable[i-1][j]!=0 ||GoTable[i][j+1]!=0 ||GoTable[i][j-1]!=0) )
			{
				int **NewTable = (int **)malloc(TABLELEN * sizeof(int *)); 
				for (int k=0; k<TABLELEN; k++) 
					NewTable[k] = (int *)malloc(TABLEWID * sizeof(int)); 
				for(int k = 0; k < TABLELEN; k++ )
					memcpy(&(NewTable[k][0]), &(GoTable[k][0]), TABLEWID * sizeof(int));
				NewTable[i][j]=StoneColor;
				if(checkwin(NewTable,StepsRemain-1,StoneColor,i,j))
					TakeStep(NewTable,StepsRemain-1,StoneColor>0?-1:1);
			}
}

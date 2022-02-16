#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
int NumsofPlans=1;

struct ComPlan{
	int D1,D2,Channel,Price;
	char Name[7];

};

struct Choice{
	int D1,D2;
	struct Choice* next;
	struct ComPlan* plan;

};

typedef struct Choice* ChoicePtr;
typedef struct ComPlan* ComPlanPtr; 

ComPlanPtr FindBest(int Day,ComPlanPtr Plans,ComPlanPtr OGplan);

ChoicePtr CreatNewChoice(ComPlanPtr Best);

int ISPCmp(struct ComPlan a); 

void PrintChoices(ChoicePtr head,int sum);

int main(){
	struct ComPlan Plans[999];
	int TotalCost = 0;
	Plans[0].D1 = 1;
	Plans[0].D2 = 365;
	Plans[0].Price = INT_MAX;
	while( scanf("%s %d %d %d %d", Plans[NumsofPlans].Name,&Plans[NumsofPlans].D1,&Plans[NumsofPlans].D2,&Plans[NumsofPlans].Channel,&Plans[NumsofPlans].Price) > 0 ){
		++NumsofPlans;
	}
	ChoicePtr head = CreatNewChoice(FindBest(1,Plans,&Plans[0]));
	ChoicePtr tmp = head;
	for( int i=2 ; i < 365 ; ++i ){
		ComPlanPtr best = FindBest(i,Plans,tmp->plan);
		if( i != tmp->plan->D2 && best->Price >= tmp->plan->Price )//  normal day && still cheaper => next day  
			continue;
		tmp->D2 = i;
		//	printf("Day %d, reach end of %s:%d, find best %s:%d\n",i,tmp->plan->Name,tmp->plan->Price,best->Name,best->Price);
		ChoicePtr New = CreatNewChoice(best);
		New->D1 = tmp->D2;
		tmp->next = New;
		TotalCost += ( (tmp->D2 - tmp->D1) * tmp->plan->Price );
		tmp = New;
	}
	tmp->next = NULL;
	TotalCost += ( (tmp->D2 - tmp->D1) * tmp->plan->Price );
	PrintChoices(head,TotalCost);
	return 0;

}

ComPlanPtr FindBest(int Day,ComPlanPtr Plans,ComPlanPtr OGplan){
	ComPlanPtr Best = &Plans[0];
	for(int i=1;i<NumsofPlans;++i){
		if(	&Plans[i] != OGplan)
			if(Plans[i].D1 <= Day && Plans[i].D2 > Day)
				if(Plans[i].Price < Best->Price || ( Plans[i].Price == Best->Price && ISPCmp(Plans[i]) > ISPCmp(*Best) ))
					Best = &Plans[i];
	}
	//	printf("Best for day %d : %s%d from %d to %d\n",Day,Best->Name,Best->Price,Best->D1,Best->D2);
	return Best;
}

ChoicePtr CreatNewChoice(ComPlanPtr Best){
	ChoicePtr new = malloc(sizeof(ChoicePtr));
	new->D1 = Best->D1;
	new->D2 = Best->D2;
	new->plan = Best;
	new->next = NULL;
	return new;
}

int ISPCmp(struct ComPlan a){
	int i;
	switch(a.Name[1]){
		case 'H':
			i = 4;
			break;
		case 'E':
			i = 3;
			break;
		case 'W':
			i = 2;
			break;
		case '-':
			i = 1;
			break;
		case 'P':
			i = 0;
			break;
	}
	return i;
}

void PrintChoices(ChoicePtr head,int sum){
	printf("%d\n",sum);
	while(head){
//		if( head->plan->Price != INT_MAX )
			printf("%d ~ %d %s channel %d NTD%d\n",head->D1,head->D2,head->plan->Name,head->plan->Channel,head->plan->Price);
		head = head->next;
	}
}


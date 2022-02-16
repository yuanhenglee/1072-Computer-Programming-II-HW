#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct stack
{
	int lastChoice;
	int lastNum;
	struct stack *next;
};

struct stack *command = NULL;
void push(int cho, int num)
{
	struct stack *temp = malloc(sizeof(struct stack));

	temp -> lastChoice = cho;
	temp -> lastNum = num;
	temp -> next = NULL;

	if(command == NULL)
		command = temp;
	else
	{
		temp -> next = command;
		command = temp;
	}
}
int totalSizeNow = 0;

int main()
{
	int numberOfCases = 10; 
	printf("%d\n", numberOfCases);

	srand(time(NULL));

	int isFirstTime = 1;

	while(numberOfCases)
	{
		int choice = (rand() % 4) + 1;
		
		if(isFirstTime) // the first time will append
		{
			choice = 1;
			isFirstTime = 0;
		}
		switch(choice)
		{
			case 1:
				{
					int size = rand() % 10 + 1;
					totalSizeNow += size;
					
					char output[11];
					for(int i = 0; i < size; i++)
						output[i] = (char)(rand() % 26 + 97);

					output[size] = '\0';
					printf("1 %s\n", output);
					
					numberOfCases--;
					push(1, size);
					break;
				}
			case 2:
				{
					if(totalSizeNow == 0)
						break;

					int deleteSize = rand() % totalSizeNow + 1;
					printf("2 %d\n", deleteSize);

					totalSizeNow -= deleteSize;
					numberOfCases--;
					push(2, deleteSize);
					break;
				}	
			case 3:
				{
					if(totalSizeNow == 0)
						break;

					int printIndex = rand() % totalSizeNow + 1;
					printf("3 %d\n", printIndex);

					numberOfCases--;
					break;
				}
			case 4:
				{
					if(command == NULL)
						break;

					if(command -> lastChoice == 1)
						totalSizeNow -= command -> lastNum;
					else
						totalSizeNow += command -> lastNum;
					
					printf("4\n");
					
					numberOfCases--;
					command = command -> next;	
					break;
				}
		}
	}	
	return 0;
}
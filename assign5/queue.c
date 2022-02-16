#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"

void enqueue(NodePtr ptr, Queue* queue){
	Queue tmp = *queue;
	if(!(*queue)){
		*queue = ptr;
		return;
	}
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = ptr;
}

void dequeue(Queue* queue){
	Queue tmp = *queue;
	//printf("ogq: %s,newq: %s\n",tmp->name,tmp->next->name);
	*queue = (*queue)->next;
	free(tmp);
	
}

NodePtr first(Queue queue){
	return queue;
}

int isQueueEmpty(Queue queue){
	return (!queue);
}

void deleteQueue(Queue* queue){
	while(*queue)
	{
		Queue tmp = *queue;
		*queue = (*queue)->next;
		free(tmp);
	}
}

int queueSize(Queue q){
	int i;
	for(i=0;q;i++)
		q = q->next;
	return i;
}


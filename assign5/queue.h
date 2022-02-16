#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "mystruct.h"

typedef NodePtr Queue;

/*Enqueue an element pointed by NodePtr to Queue*/
void enqueue(NodePtr, Queue*);

/*Dequeue an element from Queue*/
void dequeue(Queue*);

/*Return the oldest element of Queue*/
NodePtr first(Queue);

/*Return true if queue is empty*/
int isQueueEmpty(Queue);

/*Clean all the elements in the queue*/
void deleteQueue(Queue*);

/*Return the number of the elements in the queue*/
int queueSize(Queue);

#endif


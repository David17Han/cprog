#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#pragma warning(disable:4996)


Queue* initQueue()
{
	Queue * queue;
	queue=(Queue *)malloc(sizeof(Queue));
	queue->front=0;
	queue->rear=0;
	return queue;

}


void enQueue(Queue * queue,char c)
{
	queue->a[queue->rear]=c;
	queue->rear++;

}

char deQueue(Queue *queue)
{
	char c;
	if(queue->front!=queue->rear){
		c=queue->a[queue->front];
		queue->front++;
	}
	return c;
}

int isQueueEmpty(Queue * queue)
{
	if(queue->front==queue->rear) return EMPTY;
	else return NOTEMPTY;
}

char* testDoubleMain(double x,char * s)
{
	int i=0;
	char c;
	Queue *queue;
	x=x-(int)x;
	queue=initQueue();
	while(i<10)
	{
		x=x*10;
		c=(int)x+'0';
		enQueue(queue,c);
		x=x-(int)x;
		i++;
	}
	i=0;
	while(!isQueueEmpty(queue))
	{
		s[i]=deQueue(queue);
		i++;
	}
	printf("0.%s\n",s);
	return s;
}
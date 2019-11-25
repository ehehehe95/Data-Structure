#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue *pq)
{
	pq->front=0;
	pq->rear=0;
}

int QIsEmpty(Queue *pq)
{
	if(pq->front==pq->rear)
		return TRUE;

	else
		return FALSE;
}

int NextPosIdx(int pos)	// need this function for specify the case idx meets the end of the array
{
	if(pos+1==QUE_LEN)
		return 0;
	else
		return pos+1;
}

void Enqueue(Queue *pq, Data data)
{
	if(NextPosIdx(pq->rear)==pq->front)
	{
		printf("Queue Memory error!");
		exit(-1);
	}

	pq->rear=NextPosIdx(pq->rear);
	pq->queArr[pq->rear]=data;

}

Data Dequeue(Queue *pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue is not Empty");
		exit(-1);
	}

	pq->front=NextPosIdx(pq->front); //do not erase the data in the array just ignore it by moving the front pointer
	return pq->queArr[pq->front];
}

Data Qpeek(Queue *pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue is not Empty");
		exit(-1);
	}


	return pq->queArr[NextPosIdx(pq->front)];
}

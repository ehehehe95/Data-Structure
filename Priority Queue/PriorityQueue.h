#ifndef __PRIORITY_QUEUE__
#define __PRIORITY_QUEUE_

#define TRUE	1
#define FALSE	0

#define QUEUE_LEN	100

typedef char QData;
typedef int PriorityComp(QData d1,QData d2);

typedef struct _heap
{
	PriorityComp *comp;
	int numOfData;
	QData heapArr[QUEUE_LEN];
}PriorityQ;

void PQInit(PriorityQ *ph,PriorityComp pc);
int PQIsEmpty(PriorityQ *ph);

void PEnqueue(PriorityQ *ph,QData data);
QData PDequeue(PriorityQ *ph);

#endif


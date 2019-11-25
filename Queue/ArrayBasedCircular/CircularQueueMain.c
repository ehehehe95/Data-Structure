#include <stdio.h>
#include <Windows.h>
#include "CircularQueue.h"

int main(void)
{
	Queue q;
	QueueInit(&q);

	Enqueue(&q,1) ; Enqueue(&q,2) ;
	Enqueue(&q,3) ; Enqueue(&q,4) ;
	Enqueue(&q,5) ; Enqueue(&q,6) ;
	Enqueue(&q,7) ;

	while(!QIsEmpty(&q))
		printf("%d\n",Dequeue(&q));

	system("pause");
	return 0;
}
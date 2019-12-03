#include <stdio.h>
#include <Windows.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	HeapInit(&heap);

	HInsert(&heap,'H',9);
	HInsert(&heap,'E',10);
	HInsert(&heap,'A',11);
	HInsert(&heap,'P',12);

	HInsert(&heap,'I',6);
	HInsert(&heap,'S',7);
	HInsert(&heap,' ',8);

	HInsert(&heap,'T',1);
	HInsert(&heap,'H',2);
	HInsert(&heap,'I',3);
	HInsert(&heap,'S',4);
	HInsert(&heap,' ',5);
	//"THIS IS HEAP"

	while(HIsEmpty(&heap)==FALSE)
		printf("%c", HDelete(&heap));


	system("pause");
	return 0;
}
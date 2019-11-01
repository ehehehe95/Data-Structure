#include <stdio.h>
#include "DLinkedList.h"
#include <Windows.h>
int WhoIsPrecede(int d1, int d2)
{
	if(d1<d2)
		return 0;
	else
		return 1;
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list,WhoIsPrecede);

	//Instert 5datas in the list
	Linsert(&list,11); Linsert(&list,11);
	Linsert(&list,22); Linsert(&list,22);
	Linsert(&list,33);

	printf("Current number of Data: %d \n", LCount(&list));

	//print all the data in the list
	if(LFirst(&list,&data))
	{
		printf("%d  ",data);

		while(LNext(&list,&data))
			printf("%d  ",data);

	}

	printf("\n\n");

	//search for number 22 and remove
	if(LFirst(&list,&data))
	{
		if(data==22)
			LRemove(&list);
		
		while(LNext(&list,&data))
		{
			if(data==22)
				LRemove(&list);
		}
	}

	//print all the data reamining in the list

	if(LFirst(&list,&data))
	{
		printf("%d  ",data);

		while(LNext(&list,&data))
			printf("%d  ",data);

	}

	system("pause");

	return 0;
}

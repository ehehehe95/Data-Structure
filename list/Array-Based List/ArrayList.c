#include <stdio.h>
#include "ArrayList.h"

// Define the functions in the List ADT

void ListInit(List * plist)				//initialize the list
{
	plist->numOfData=0;
	plist->curPosition=-1;
}

void Linsert(List *plist, LData data)	//save the data in the list
{
	if(plist->numOfData>LIST_LEN)
	{
		puts("Can't save the Data!");
			return;
	}
	plist->arr[plist->numOfData]=data;
	plist->numOfData++;
}

int LFirst(List *plist, LData *pdata)	//save the fist data in the list to the pdata, if suceed return 1, else return 0
{
	if(plist->numOfData==0)
		return FALSE;
	plist->curPosition=0;
	*pdata=plist->arr[0];
	return TRUE;
}

int LNext(List *plist, LData *pdata)	//save the next data in the list to the pdata, if suceed return 1, else return 0
{
		if(plist->curPosition>=plist->numOfData-1)
		return FALSE;
		plist->curPosition++;
		*pdata=plist->arr[plist->curPosition];
		return TRUE;
}


LData LRemove(List *plist)				//erase the data from the list and return
{
	int Rpos=plist->curPosition;
	int num=plist->numOfData;
	int i;
	LData Rdata=plist->arr[Rpos];

	for(i=Rpos; i<num-1; i++)
		plist->arr[i]=plist->arr[i+1];
	
	plist->numOfData--;
	plist->curPosition--;//decrease the current position because the datas are moved left by one, current curPosition points the data that is not read
	return Rdata;
}

int LCount(List *plist)				    //return the number of the data saved in the list
{
	return plist->numOfData;
}

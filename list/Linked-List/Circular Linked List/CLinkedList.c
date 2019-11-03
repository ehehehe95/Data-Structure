#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
	plist->tail=NULL;
	plist->cur=NULL;
	plist->before=NULL;
	plist->numOfData=0;
}

void LInsert(List *plist, Data data)	//insert the data in the tail
{
	Node *newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;

	if(plist->tail==NULL)
	{
		plist->tail=newNode;
		plist->tail->next=newNode;	 // for only one node in the list head and same should be same
	}

	else
	{
		newNode->next=plist->tail->next; //new =Node next points head
	
		plist->tail->next=newNode;
		plist->tail=newNode;
	}

	plist->numOfData++;
}

void LInsertFront(List *plist,Data data)
{
	Node *newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;

	if(plist->tail==NULL)
	{
		plist->tail=newNode;
		newNode->next=newNode;	 // for only one node in the list head and same should be same
	}

	else
	{
		newNode->next=plist->tail->next;
		plist->tail->next=newNode;
	}

	plist->numOfData++;
}

// there's not much difference when data is added head or tail on circular list. only tail points the different node


int LFirst(List *plist, Data *pdata)	
{
	if(plist->tail==NULL)
		return FALSE;

	plist->before=plist->tail;
	plist->cur=plist->tail->next;

	*pdata=plist->cur->data;
	return TRUE;
}
	
int LNext(List *plist, Data *pdata)	// Lnext does not check whether the search of data reached the end of the list, so can be repeated infinetly
{
	if(plist->tail==NULL)
		return FALSE;

	plist->before=plist->cur;
	plist->cur=plist->cur->next;
		
	*pdata=plist->cur->data;
	return TRUE;
}
	

Data LRemove(List *plist)	// erase the node pointed by cur, and return the data
{
	Node *Rpos=plist->cur;
	Data Rdata=plist->cur->data;

	if(Rpos==plist->tail)
	{
		if(plist->tail==plist->tail->next)
			plist->tail=NULL;
		else
			plist->tail=plist->before;
	}

	plist->before->next=plist->cur->next;
	plist->cur=plist->before;

	free(Rpos);
	plist->numOfData--;
	return Rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}
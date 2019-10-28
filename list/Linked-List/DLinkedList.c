#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"




void ListInit(List * plist)
{
	plist->head=(Node *)(malloc(sizeof(Node))); // make a dummy node
	plist->head->next=NULL;
	plist->comp=NULL;
	plist->numOfData=0;
}

void Linsert(List *plist, LData data)	//save the data in the list
{
	if(plist->comp==NULL)
	{
		Node *newNode=(Node*)malloc(sizeof(Node));
		newNode->data=data;
		newNode->next=plist->head->next;
		plist->head->next=newNode;

		(plist->numOfData)++;
	}
	else
	{
		/// not decided yet
	}
}


int LFirst(List *plist, LData *pdata)	//save the fist data in the list to the pdata, if suceed return 1, else return 0
{
	if(plist->head->next==NULL)
		return FALSE;

	plist->before=plist->head;
	plist->cur=plist->head->next;

	*pdata=plist->cur->data;
	return TRUE;
}

int LNext(List *plist, LData *pdata)	//save the next data in the list to the pdata, if suceed return 1, else return 0
{
	if(plist->cur->next==NULL)
		return FALSE;

	plist->before=plist->cur;
	plist->cur=plist->cur->next;

	*pdata=plist->cur->data;
	return TRUE;
}

LData LRemove(List *plist)				//erase the data in the current read position at the list and return
{
	LData Rdata=plist->cur->data;

	plist->before->next=plist->cur->next;
	free(plist->cur);
	plist->cur=plist->before; //cur position and before position points the same position so successive call is not allowed

	(plist->numOfData)--;
	return Rdata;
}

int LCount(List *plist)				//return the number of the data saved in the list
{
	return plist->numOfData;
}
void SetSortRule(List *plist, int (*comp)(LData d1,LData d2))
{
	// not decided yet
}

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

	plist->head->next=(Node *)(malloc(sizeof(Node)));
	plist->

int LFirst(List *plist, LData *pdata);	//save the fist data in the list to the pdata, if suceed return 1, else return 0
int LNext(List *plist, LData *pdata);	//save the next data in the list to the pdata, if suceed return 1, else return 0

LData LRemove(List *plist);				//erase the data from the list and return
int LCount(List *plist);				//return the number of the data saved in the list

void SetSortRule(List *plist, int (*comp)(LData d1,LData d2));


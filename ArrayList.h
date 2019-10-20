#include "NameCard.h"
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

#define LIST_LEN	100
typedef NameCard * LData;

//define the ArrayList structure, current position is -1 when the list is empty
typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
}	ArrayList;

typedef ArrayList List;

void ListInit(List * plist);	//initialize the list
void Linsert(List *plist, LData data);	//save the data in the list

int LFirst(List *plist, LData *pdata);	//save the fist data in the list to the pdata, if suceed return 1, else return 0
int LNext(List *plist, LData *pdata);	//save the next data in the list to the pdata, if suceed return 1, else return 0

LData LRemove(List *plist);				//erase the data from the list and return
int LCount(List *plist);				//return the number of the data saved in the list

#endif

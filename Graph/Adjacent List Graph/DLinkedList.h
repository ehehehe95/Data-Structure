#pragma once

#define TRUE		1
#define FALSE		0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
} Node;

typedef struct _linkedList
{
	Node* head;			//pointer pointing dummy node
	Node* cur;			//current read position
	Node* before;		//read position before
	int numOfData;
	int (*comp)(LData d1, LData d2);	//sort the data by the function comp
} LinkedList;

typedef LinkedList List;

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

// others are same with the array List

void ListInit(List* plist);	//initialize the list
void LInsert(List* plist, LData data);	//save the data in the list

int LFirst(List* plist, LData* pdata);	//save the fist data in the list to the pdata, if suceed return 1, else return 0
int LNext(List* plist, LData* pdata);	//save the next data in the list to the pdata, if suceed return 1, else return 0

LData LRemove(List* plist);				//erase the data from the list and return
int LCount(List* plist);				//return the number of the data saved in the list

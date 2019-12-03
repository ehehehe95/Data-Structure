#include <stdio.h>
#include "SimpleHeap.h"

void HeapInit(Heap *ph)
{
	ph->numOfData=0;
}

int HIsEmpty(Heap *ph)
{
	if(ph->numOfData==0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx/2;
}

int GetLChildIDX(int idx)
{
	return idx*2;
}
int GetRChildIDX(int idx)
{
	return idx*2+1;
}

int GetHiPriChildIDX(Heap *ph, int idx)	// retruns the index of higher priority child node
{
	if(GetLChildIDX(idx)>ph->numOfData)
		return 0;

	else if(GetLChildIDX(idx)==ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
		if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap *ph,HData data, Priority pr)
{
	int idx=ph->numOfData+1;		//start comparing putting new node on the last
	HeapElem nelem={pr,data};

	while(idx !=1)
	{
		if(pr< ph->heapArr[GetParentIDX(idx)].pr)	//if new node has higher priority
		{
			ph->heapArr[idx]=ph->heapArr[GetParentIDX(idx)];		//put parent node to child node
			idx=GetParentIDX(idx);		//and move the new node's index to parent node
		}

		else
			break;
	}

	ph->heapArr[idx]=nelem;
	ph->numOfData+=1;
}
	
HData HDelete(Heap *ph)	// delete the root node and put the last node in the root node position and compare
{	
	HData Rdata=ph->heapArr[1].data;
	HeapElem lastElem=ph->heapArr[ph->numOfData];

	int parentIdx=1;
	int childIdx;

	while(childIdx=GetHiPriChildIDX(ph,parentIdx))
	{

		if(ph->heapArr[childIdx].pr<lastElem.pr)		//if last element(parent node) has a lower priority than child node
		{
			ph->heapArr[parentIdx]=ph->heapArr[childIdx];//move child node to parent node
			parentIdx=childIdx;	//change last node's target Idx to child node idx
		}

		else	//if last element has a higher priority or same priority break
			break;
	}

	ph->heapArr[parentIdx]=lastElem;
	ph->numOfData-=1;

	return Rdata;
}
#include <stdio.h>
#include "PriorityQueue.h"

void PQInit(PriorityQ *ph, PriorityComp pc)
{
	ph->numOfData=0;
	ph->comp=pc;
}

int PQIsEmpty(PriorityQ *ph)
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

int GetHiPriChildIDX(PriorityQ *ph, int idx)	// retruns the index of higher priority child node
{
	if(GetLChildIDX(idx)>ph->numOfData)
		return 0;

	else if(GetLChildIDX(idx)==ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)],ph->heapArr[GetRChildIDX(idx)])<0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void PEnqueue(PriorityQ *ph,QData data)
{
	int idx=ph->numOfData+1;		

	while(idx !=1)
	{
		if(ph->comp(data,ph->heapArr[GetParentIDX(idx)])>0)	//if data has a higher priority
		{
			ph->heapArr[idx]=ph->heapArr[GetParentIDX(idx)];		//put parent node to child node
			idx=GetParentIDX(idx);		//and move the new node's index to parent node
		}

		else
			break;
	}

	ph->heapArr[idx]=data;
	ph->numOfData+=1;
}
	
QData PDequeue(PriorityQ *ph)	// delete the root node and put the last node in the root node position and compare
{	
	QData Rdata=ph->heapArr[1];
	QData lastElem=ph->heapArr[ph->numOfData];

	int parentIdx=1;
	int childIdx;

	while(childIdx=GetHiPriChildIDX(ph,parentIdx))
	{

		if(ph->comp(lastElem,ph->heapArr[childIdx])<0)		//if last element(parent node) has a lower priority than child node
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
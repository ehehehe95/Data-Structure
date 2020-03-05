#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;

	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	pstack->topIndex++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		puts("Stack meomory error!");
		system("pasue");
		exit(-1);
	}

	rIdx = pstack->topIndex;
	pstack->topIndex--;

	return pstack->stackArr[rIdx];
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("Stack meomory error!");
		system("pasue");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
#include <stdio.h>
#include "ArrayBaseStack.h"

void StackInit(Stack *pstack)
{
	pstack->topIndex=-1;
}

int SIsEmpty(Stack *pstack)
{
	if(pstack->topIndex==-1)
		return TRUE;

	else
		return FALSE;
}
void SPush(Stack *pstack, Data data)
{

Data Spop(Stack *pstack);
Data Speek(Stack *pstack);
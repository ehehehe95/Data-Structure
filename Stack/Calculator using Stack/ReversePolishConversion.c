#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBasedStack.h"

int GetOpPrio(char op) //return the priority of the operator
{
	switch(op)
	{
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 2;
	case '(':
		return 1;
	}
	
	return -1;
}

int WhoPrec(char op1, char op2)
{
	int op1Pr=GetOpPrio(op1);
	int op2Pr=GetOpPrio(op2);

	if(op1Pr > op2Pr)		//op1 has a higher priority
		return 1;

	else if(op1Pr < op2Pr)	//op2 has a higher priority 
		return -1;

	else					//if two operator has same priority
		return 0;
}


void ConvToRPN(char exp[])
{
	Stack stack;
	int expLen=strlen(exp);
	char *convExp=(char*)malloc(expLen+1);

	char temp, popOp;
	int i, idx=0;

	memset(convExp,0,sizeof(char)*expLen+1);
	StackInit(&stack);

	for(i=0; i<expLen ; i++)
	{
		temp=exp[i];

		if(isdigit(temp))	//if the character in the temp is a number save it to the arr
		{
			convExp[idx++]=temp;
		}

		else
		{
			switch(temp)
			{
			case '(':
				SPush(&stack, temp);
				break;

			case ')':
				while(1)
				{
					popOp=SPop(&stack);
					if(popOp=='(')
						break;
					convExp[idx++]=popOp;
				}
				break;
			
			case '+': case '-':
			case '*': case' /':
				// if temp has a same or lower priority to the operator in the stack, pop the data until it meets lower priority operator or empty 
				while(!SIsEmpty(&stack) && WhoPrec(SPeek(&stack), temp) >=0 )	
					convExp[idx++]=SPop(&stack);

				SPush(&stack,temp);
				break;
			}
		}
	}

	while(!SIsEmpty(&stack))
		convExp[idx++]=SPop(&stack);

	strcpy(exp,convExp);
	free(convExp);
}

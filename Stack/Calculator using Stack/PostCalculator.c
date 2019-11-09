#include "ListBasedStack.h"
#include <string.h>
#include <ctype.h>

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen=strlen(exp);

	int i;
	char temp, op1, op2;

	for(i=0; i<expLen; i++)
	{
		temp=exp[i];

		if(isdigit(temp))
		{
			SPush(&stack, temp-'0'); // temp's ascii code - '0''s ascii code ->int num
		}

		else
		{
			op1=SPop(&stack);
			op2=SPop(&stack);

			switch(temp)
			{
			case '+':
				SPush(&stack, op1+op2);
				break;

			case '-':
				SPush(&stack, op1-op2);
				break;

			case '*':
				SPush(&stack, op1*op2);
				break;

			case '/':
				SPush(&stack, op2/op1);
				break;
			}
		}
	}
	
	return SPop(&stack);
}
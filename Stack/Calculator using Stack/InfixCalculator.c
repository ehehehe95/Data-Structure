#include <string.h>
#include <stdlib.h>
#include "PostCalculator.h"
#include "ReversePolishConversion.h"

int EvalInfixExp(char exp[])
{
	int len= strlen(exp);
	int result;

	char *excpy=(char*)malloc(len+1);
	strcpy(excpy,exp);

	ConvToRPN(excpy);
	result=EvalRPNExp(excpy);

	free(excpy);
	
	return result;
}
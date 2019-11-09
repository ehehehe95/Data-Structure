#include <stdio.h>
#include "ReversePolishConversion.h"
#include <Windows.h>
int main(void)

{
	char exp1[]="1+2*3";
	char exp2[]="(1+2)*3";
	char exp3[]="((1-2)+3)*(5-2)";

	ConvToRPN(exp1);
	ConvToRPN(exp2);
	ConvToRPN(exp3);

	printf("%s \n",exp1);
	printf("%s \n",exp2);
	printf("%s \n",exp3);

	system("pause");
	return 0;
}
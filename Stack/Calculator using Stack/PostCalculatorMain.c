#include <stdio.h>
#include "PostCalculator.h"
#include <Windows.h>
int main(void)

{
	char exp1[]="42*8+";
	char exp2[]="123+*4/";


	printf("%d \n",EvalRPNExp(exp1));
	printf("%d \n",EvalRPNExp(exp2));

	system("pause");
	return 0;
}
#include <stdio.h>
#include "ArrayBaseStack.h"
#include <Windows.h>

int main(void)
{

	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5); SPush(&stack, 6);
	SPush(&stack, 7); SPush(&stack, 8);

	while(!SIsEmpty(&stack))
		printf("%d ",SPop(&stack));

	system("pause");
	return 0;
}


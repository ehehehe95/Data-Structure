#ifndef __LIST_BASED_STACK__
#define __LIST_BASED_STACK__

#define TRUE	1
#define FALSE	0

typedef char Data;

typedef struct __node
{
	Data data;
	struct __node *next;
} Node;

typedef struct _listStack
{
	Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif

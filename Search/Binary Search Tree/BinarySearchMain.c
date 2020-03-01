#include <stdio.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode* bstRoot;
	BTreeNode* sNode;	//search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 19);
	BSTInsert(&bstRoot, 7);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 13);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 23);
	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 8);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("search failed! \n");
	else
		printf("key searched succeed : %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 3);
	if (sNode == NULL)
		printf("search failed! \n");
	else
		printf("key searched succeed : %d \n", BSTGetNodeData(sNode));
	
	sNode = BSTSearch(bstRoot, 19);
	if (sNode == NULL)
		printf("search failed! \n");
	else
		printf("key searched succeed : %d \n", BSTGetNodeData(sNode));

	return 0;
}
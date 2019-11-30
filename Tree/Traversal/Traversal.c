#include <stdio.h>
#include "Traversal.h"

typedef void VisitFuncPtr(BTData data);

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if(bt==NULL)
		return;

	
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if(bt==NULL)
		return;

	action(bt->data);
	InorderTraverse(bt->left, action);
	InorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if(bt==NULL)
		return;

	InorderTraverse(bt->left, action);
	InorderTraverse(bt->right, action);
	action(bt->data);
}

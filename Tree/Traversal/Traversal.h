
#ifndef __TRAVERSAL_H__
#define __TRAVERSAL_H__

#include "BinaryTree.h"


typedef void VisitFuncPtr(BTData data);

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

#endif


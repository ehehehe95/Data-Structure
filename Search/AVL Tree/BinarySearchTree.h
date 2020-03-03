#ifndef __BINARY_SEARCH_H__
#define __BINARY_SEARCH_H__

#include "BinaryTree.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode** pRoot);		//make binary search tree(BST) and initialize

BSTData BSTGetNodeData(BTreeNode* bst);		//return the data saved in the node

void BSTInsert(BTreeNode** pRoot, BSTData data);		// save the data in the BST

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);	//search the data in the BST

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);					//remove the node from the tree and return the address of the remove node

#endif
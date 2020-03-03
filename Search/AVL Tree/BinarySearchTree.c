#include <stdio.h>
#include "BinarySearchTree.h"
#include "BinaryTree.h"

void BSTMakeAndInit(BTreeNode** pRoot)		//make binary search tree(BST) and initialize
{
	*pRoot = NULL;
}
BSTData BSTGetNodeData(BTreeNode* bst)		//return the data saved in the node
{
	return bst->data;
}
void BSTInsert(BTreeNode** pRoot, BSTData data)		// save the data in the BST
{
	BTreeNode* pVRoot = makeBTReeNode();
	BTreeNode* ParentNode = pVRoot;
	BTreeNode* CurrentNode = *pRoot;
	BTreeNode* NewNode = NULL;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (CurrentNode != NULL)
	{
		if (data == GetData(CurrentNode))
			return;									//overlap of the key is not allowed
		
		ParentNode = CurrentNode;
		
		if (GetData(CurrentNode) > data)
			CurrentNode = GetLeftSubTree(CurrentNode);

		else
			CurrentNode = GetRightSubTree(CurrentNode);

	}
	
	NewNode = MakeBTreeNode();
	SetData(NewNode, data);

	if (ParentNode != NULL)
	{
		if (GetData(ParentNode) > data)
			MakeLeftSubTree(ParentNode,NewNode);

		else
			MakeRightSubTree(ParentNode, NewNode);
	}

	else
	{
		*pRoot = NewNode;
	}

}
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)	//search the data in the BST
{
	BTreeNode* Current=bst;

	while (Current != NULL)
	{
		if (GetData(Current) == target)
			return Current;

		else if (GetData(Current) > target)
			Current = GetLeftSubTree(Current);

		else
			Current = GetRightSubTree(Current);
	}

	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)		//remove the node from the tree and return the address of the remove node
{
	BTreeNode* pVRoot = MakeBTreeNode();	//make a virtual node for the case removing root node
	BTreeNode* ParentNode = pVRoot;
	BTreeNode* CurrentNode = *pRoot;
	BTreeNode* delNode;

	ChangeRightSubTree(pVRoot, *pRoot);		// make root node to the subtree of a virtual root node

	while (CurrentNode != NULL&&GetData(CurrentNode)==target)
	{
		ParentNode = CurrentNode;

		if (GetData(CurrentNode) > target)
			CurrentNode = GetLeftSubTree(CurrentNode);
		else
			CurrentNode = GetRightSubTree(CurrentNode);
	}

	if (CurrentNode == NULL)
		return NULL;

	delNode = CurrentNode;

	if (delNode->left == NULL && delNode->right == NULL)	//if the node is a terminal node
	{
		if(GetLeftSubTree(ParentNode)==delNode)
			RemoveLeftSubTree(ParentNode);
		else
			RemoveRightSubTree(ParentNode);
	}

	if (delNode->left == NULL || delNode->right == NULL)	//if the node has a one subtree
	{
		BTreeNode* delChildNode;

		if (GetLeftSubTree(delNode) != NULL)
			delChildNode = GetLeftSubTree(delNode);
		
		else
			delChildNode = GetRightSubTree(delNode);

		if (GetLeftSubTree(ParentNode) == delNode)
			ChangeLeftSubTree(ParentNode, delChildNode);
		else
			ChangeRightSubTree(ParentNode, delChildNode);

	}

	//if (delNode->left != NULL && delNode->right != NULL)	//if the node has both left and right subtree
	else
	{
		BTreeNode* mNode = GetRightSubTree(delNode);
		BTreeNode* mpNode = delNode;
		int delData;
		// find the smallest data on the right subtree
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(delNode);
		SetData(delNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));

		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		delNode = mNode;
		SetData(delNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return delNode;

}
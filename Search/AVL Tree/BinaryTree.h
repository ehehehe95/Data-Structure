#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;

	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode *MakeBTreeNode(void);		//make a node and return the adress

BTData GetData(BTreeNode* bt);		//return the data saved in the node

void SetData(BTreeNode* bt, BTData data);		//set the data in the node

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);		//return the adress of left and right subtree

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);		//set the left and right subtree of the main node

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);				// Remove left or right subtree and return the removed address

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);	// change the left or right child node without free the memory

#endif

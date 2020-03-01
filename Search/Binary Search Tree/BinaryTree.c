#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"



BTreeNode * MakeBTreeNode(void)		//make a node and return the adress
{
    BTreeNode *newNode = (BTreeNode*) malloc(sizeof(BTreeNode));

    if (newNode == NULL)
        return NULL;
     newNode->left = NULL;
     newNode->right = NULL;

    return newNode;
}

BTData GetData(BTreeNode* bt)		//return the data saved in the node
{
    return bt->data;
}

void SetData(BTreeNode* bt, BTData data)		//set the data in the node
{
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)		//return the adress of left and right subtree
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->left != NULL)
        free(main -> left);

    main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)		//set the left and right subtree of the main node
{
    if (main->right != NULL)
        free(main -> right);

    main->right = sub;
}

BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
    BTreeNode* delNode;

    if (bt != NULL)
    {
        delNode = bt->left;
        bt->left = NULL;
    }
    
    return delNode;

}
BTreeNode* RemoveRightSubTree(BTreeNode* bt)				// Remove left or right subtree and return the removed address
{
    BTreeNode* delNode;

    if (bt != NULL)
    {
        delNode = bt->right;
        bt->right = NULL;
    }

    return delNode;

}
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    main->left = sub;
}

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)       // change the left or right child node without free the memory
{
    main->right = sub;
}
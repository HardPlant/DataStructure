#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "queue.h"
typedef int ElementType;
typedef struct TreeNode {
	ElementType data;
	struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode TreeHeader;
TreeHeader* makeTree()
{
	return makeNode(0);
}
TreeNode* makeNode(ElementType data)
{
	TreeNode* toMake = (TreeNode*)malloc(sizeof(TreeNode));
	toMake->data = data;
	toMake->left = NULL;
	toMake->right = NULL;
}
TreeHeader insertTree(TreeHeader* head)
{

}
TreeHeader deleteTree(TreeHeader* head)
{

}
void printNode(TreeNode* root);
void inorder(TreeNode *root, int(*FUNC)(TreeNode*));
void preorder(TreeNode *root, int(*FUNC)(TreeNode*));
void postorder(TreeNode *root, int(*FUNC)(TreeNode*));
void levelorder(TreeNode* ptr, int(*FUNC)(TreeNode*));
int getNodeOfOneChild(TreeNode* ptr);
int findMin(TreeNode* root, int min);
int findMax(TreeNode* root, int max);
void findMinMax(TreeNode *root);
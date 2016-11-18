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

void printNode(TreeNode* root);
void inorder(TreeNode *root, int(*FUNC)(TreeNode*));
void preorder(TreeNode *root, int(*FUNC)(TreeNode*));
void postorder(TreeNode *root, int(*FUNC)(TreeNode*));
void levelorder(TreeNode* ptr, int(*FUNC)(TreeNode*));
int getNodeOfOneChild(TreeNode* ptr);
int findMin(TreeNode* root, int min);
int findMax(TreeNode* root, int max);
void findMinMax(TreeNode *root);
#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;
void inorder(TreeNode *root);
void preorder(TreeNode *root);
void postorder(TreeNode *root);

void level_order(root);

#endif
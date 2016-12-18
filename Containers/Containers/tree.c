#include "tree.h"
#include "queue.h"
void inorder(TreeNode *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}
void preorder(TreeNode *root)
{
	if (root)
	{
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(TreeNode *root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}
}

void level_order(root);
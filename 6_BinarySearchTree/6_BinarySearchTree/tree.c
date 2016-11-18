#include "tree.h"
#include "queue.h"
void printNode(TreeNode* root)
{
	printf("%d ", root->data);
}
void inorder(TreeNode *root, int(*FUNC)(TreeNode*))
{
	if (root != NULL)
	{

		inorder(root->left, (*FUNC));
		(*FUNC)(root);
		inorder(root->right, (*FUNC));
	}

}
void preorder(TreeNode *root,int (*FUNC)(TreeNode*))
{
	if (root != NULL)
	{
		(*FUNC)(root);
		preorder(root->left, (*FUNC));
		preorder(root->right, (*FUNC));
	}
}
void postorder(TreeNode *root, int(*FUNC)(TreeNode*))
{
	if (root != NULL)
	{
		postorder(root->left,(*FUNC));
		postorder(root->right, (*FUNC));
		(*FUNC)(root);
	}
}

int postorderPlus(TreeNode *root, int(*FUNC)(TreeNode*))
{
	if (root != NULL)
	{
		return postorderPlus(root->left, (*FUNC))
			+ postorderPlus(root->right, (*FUNC))
			+ (*FUNC)(root);
	}
	else return 0;
}
void levelorder(TreeNode* ptr, int(*FUNC)(TreeNode*))
{
	Queue* levelQueue = makeQueue();

	if (ptr != NULL)
		return;
	enqueue(levelQueue, ptr);
	while (!isEmpty(levelQueue))
	{
		ptr = dequeue(levelQueue);
		(*FUNC)(ptr);
		if (ptr->left != NULL)
			enqueue(levelQueue, ptr->left);
		if (ptr->right != NULL)
			enqueue(levelQueue, ptr->right);
	}
}

int getNodeOfOneChild(TreeNode* ptr)
{
	if (ptr->left)
		if (!ptr->right)
			return 1;
	if (ptr->right)
		if (!ptr->left)
			return 1;
	return 0;
}
int findMin(TreeNode* root, int min)
{
	int left, right;
	if (root != NULL)
	{
		left = findMin(root->left, min);
		right = findMin(root->right, min);
		min = root->data < min ? root->data : min;
		if (min < left && min < right)
			return min;
		if (left < right)
			return left;
		else
			return right;
	}
	return INT_MAX;
}
int findMax(TreeNode* root, int max)
{
	int left, right;
	if (root != NULL)
	{
		left = findMax(root->left, max);
		right = findMax(root->right, max);
		max = left > max ? left : max;
		max = right > max ? right : max;
	}
	return max;
}
void findMinMax(TreeNode *root)
{
	int min = findMin(root, root->data);
	int max = findMax(root, root->data);
	printf("%d %d", min, max);
}
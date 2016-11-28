#pragma once
#include "binarySearchTree.h"
BTreeRefCount = 0;
BTreeNode* makeBTreeNode(ElementType data)
{
	BTreeNode* toMake = (BTreeNode*)malloc(sizeof(BTreeNode));
	if (toMake == NULL)
	{
		fprintf_s(stderr, "�Ҵ� ����! : %s", __func__);
		return NULL;
	}
	toMake->key = data;
	toMake->left = NULL;
	toMake->right = NULL;
	return toMake;
}
BTree* makeBTree(ElementType data)
{
	return makeBTreeNode(data);
}

int isTerminalNode(BTreeNode* node)
{
	return (node->left == NULL && node->right == NULL);
}
void initBTreeRefCount()
{
	BTreeRefCount = 0;
}

int getBTreeRefCount(char* str)
{
	printf("%s �� �湮 Ƚ�� : %d\n", str,BTreeRefCount);
	return BTreeRefCount;
}
ElementType BTgetKey(BTreeNode* current)
{
	return current->key;
}
BTreeNode* BTgoLeft(BTreeNode* current)
{
	BTreeRefCount += 1;
	return current->left;
}
BTreeNode* BTgoRight(BTreeNode* current)
{
	BTreeRefCount += 1;
	return current->right;
}
BTreeNode* searchBTree(BTreeNode *node, ElementType key)
{
	while (node != NULL)
	{
		if (key == BTgetKey(node))
			return node;
		else if (key < BTgetKey(node))
			node = BTgoLeft(node);
		else
			node = BTgoRight(node);
	}
	return NULL; // ����
}

BTree* insertBTree(BTreeNode** root, ElementType key)
{
	BTreeNode *parent, *temp;
	BTreeNode *toInsert;
	temp = *root;
	parent = NULL;
	if (root == NULL)
	{
		return makeBTreeNode(key);
	}
	while (temp != NULL)
	{
		if (key == BTgetKey(temp)) // �̹� �����ϸ� �߰����� �ʰ� �״�� ��ȯ.
			return *root;	  // �����Ѵٸ� ������ ��带 �ѹ� Ÿ�� �״�� ������ NULL�� ������ ���� �Ҵ��ϸ� �� ����.
		parent = temp;
		if (key < BTgetKey(parent))
			temp = BTgoLeft(parent);
		else
			temp = BTgoRight(parent);
	}
	toInsert = makeBTreeNode(key);
	if (parent != NULL)
		if (key < BTgetKey(parent))
			parent->left = toInsert;
		else parent->right = toInsert;
	else *root = toInsert;
	return *root; // root�� �״�ΰų� toInsert��.
}
BTreeNode* deleteBTree(BTreeNode **root, ElementType key)
{
	BTreeNode *parent, *child, *successor, *succesorParent, *temp;
	parent = NULL;
	temp = *root;
	while (temp != NULL && BTgetKey(temp) != key)
	{
		parent = temp;
		if (key < BTgetKey(parent))
			temp = BTgoLeft(parent);
		else
			temp = parent->right;
	}
	if (temp == NULL)
		return *root;
	else if (isTerminalNode(temp))
	{
		if (parent != NULL)
		{
			if (BTgoLeft(parent) == temp)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			*root = NULL;
	}
	else if ((BTgoLeft(temp) == NULL) || (BTgoRight(temp) == NULL))
	{
		child = ((BTgoLeft(temp) != NULL)) ? temp->left : temp->right;
		if (parent != NULL)
			if (BTgoLeft(parent) == temp)
				parent->left = child;
			else
				parent->right = child;
		else
			*root = child;
	}
	else
	{
		succesorParent = temp;
		successor = temp->right;
		while ((BTgoLeft(successor) != NULL))
		{
			succesorParent = successor;
			successor = successor->left;
		}
		if ((BTgoLeft(succesorParent) == successor))
			succesorParent->left = successor->right;
		else
			succesorParent->right = successor->right;
		temp->key = BTgetKey(successor);
		temp = successor;
	}
	free(temp);
	return *root;
}
void printBTreeNode(BTreeNode* root)
{
	BTreeRefCount++;
	printf("%d ", BTgetKey(root));
}
void printBTree(BTree* head)
{
	if (head == NULL)
		return;
	inorder(head, printBTreeNode);
	printf("\n");
}
void inorder(BTreeNode* head, void(*func)(BTreeNode*))
{
	if (head != NULL)
	{
		inorder(BTgoLeft(head), func);
		func(head);
		inorder(BTgoRight(head), func);
	}
}
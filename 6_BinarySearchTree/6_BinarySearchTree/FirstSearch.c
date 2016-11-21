#include "FirstSearch.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>
ElementType getAbsTree(BTreeNode* root, ElementType key)
{
	if (root == NULL || root->key - key < 0) return INT_MAX; // NULL 비교 방지
	return root->key - key;
}
BTreeNode* inorderAbs(BTreeNode *root, ElementType key)
{
	ElementType mindiff;
	ElementType left;
	ElementType right;
	BTreeNode* rootLeft;
	BTreeNode* rootRight;
	if (root == NULL)
		return root;
	rootLeft = goLeft(root);
	rootRight = goRight(root);
	if (root != NULL)
	{
		mindiff = getAbsTree(root, key);
		left = getAbsTree(rootLeft, key);
		right = getAbsTree(rootRight, key);
		if (mindiff < left && mindiff < right)
			return root;
		else if (left < right)
			return inorderAbs(rootLeft,key);
		else
			return inorderAbs(rootRight,key);
	}
}
ListNode* searchListNodeNearest(ListHeader *head, ElementType data)
{
	ListNode* current;
	ListNode* nearest;
	if (head == NULL)
		return NULL;
	current = head->first;
	nearest = head->first;
	while (current != NULL)
	{
		goingCountList++;
		if (data - nearest->data> 0 && current->data - data < nearest->data - data)
			nearest = current;
		current = current->link;
	}
	return nearest;
}

int FirstSearchUSL(ListHeader* head, ElementType key)
{
	ListNode* toFind = searchListNode(head, key);
	initGoingCountList();
	if (toFind == NULL)
	{
		toFind = searchListNodeNearest(head, key);
		insertListNode(&head, makeListNode(abs(toFind->data - key)));
		removeListNode(&head, toFind);
	}
	else if (toFind->data == key)
	{
		removeListNode(&head, toFind);
	}
	return getGoingCountList();
}
int FirstSearchBTree(BTree* head, ElementType key)
{
	initGoingCount();
	BTreeNode* toFind = searchBTree(head, key);
	if (toFind == NULL)
	{
		toFind = inorderAbs(head, key);
		if (toFind == NULL)
		{
			printf("존재하지 않음 : %s\n", __func__);
			return getGoingCount();
		}
		insertBTree(&head, abs(key - (toFind->key)));
		deleteBTree(&head, toFind->key);
	}
	else if (toFind->key == key)
	{
		deleteBTree(&head, key);
	}
	return getGoingCount();
}

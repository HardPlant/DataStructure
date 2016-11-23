#ifndef FIRST_SEARCH_H
#define FIRST_SEARCH_H
#include "binarySearchTree.h"
#include "linkedlist.h"


int FirstSearchBTree(BTree* head, ElementType key);
ElementType getAbsTree(BTreeNode* root, ElementType key);
int FirstSearchUSL(ListHeader* head, ElementType key);
ListNode* searchListNodeNearest(ListHeader *head, ElementType data);
BTreeNode* inorderAbs(BTreeNode *root, ElementType key);

#endif
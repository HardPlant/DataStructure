#ifndef BINARY_SEARCH_TREE_H_6
#define BINARY_SEARCH_TREE_H_6
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct BTreeNode {
	ElementType key;
	struct BTreeNode *left, *right;
}BTreeNode;
int isTerminalNode(BTreeNode* node);
typedef BTreeNode BTree;
BTreeNode* makeBTreeNode(ElementType data);
BTree* makeBTree(ElementType data);
BTreeNode* searchBTree(BTreeNode *node, ElementType key);
BTree* insertBTree(BTreeNode** root, ElementType key);
BTreeNode* deleteBTree(BTreeNode **root, ElementType key);
int BTreeRefCount;
void initBTreeRefCount();
int getBTreeRefCount(char* str);
void printBTreeNode(BTreeNode* root);
void printBTree(BTree* head);
BTreeNode* BTgoLeft(BTreeNode* current);
BTreeNode* BTgoRight(BTreeNode* current);
ElementType BTgetKey(BTreeNode* current);
void inorder(BTreeNode* head, void(*func)(BTreeNode*));
#endif

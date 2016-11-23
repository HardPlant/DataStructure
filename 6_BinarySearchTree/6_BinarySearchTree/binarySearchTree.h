#ifndef BINARY_SEARCH_TREE_H_6
#define BINARY_SEARCH_TREE_H_6
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
int goingCount;
void initGoingCount();
int getGoingCount();
void printBTreeNode(BTreeNode* root);
void printBTree(BTree* head);
BTreeNode* goLeft(BTreeNode* current);
BTreeNode* goRight(BTreeNode* current);
#endif

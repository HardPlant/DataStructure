#ifndef LARGETST_SEARCH_MAIN_H
#define LARGETST_SEARCH_MAIN_H
#include "MaxHeap.h"
#include "binarySearchTree.h"

void getDS(char DStoUse[]);
void BSTLoopEntry();
void MaxHeapLoopEntry();
int isAvailableDS(char DStoUse[]);
int isCommand(char input[]);
int isInputEnd();
int* getMultipleInt();

void BTreeLargestSearch(BTree* head, ElementType item);
void maxHeapLargestSearch(MaxHeap *head, KeyType key);
#endif

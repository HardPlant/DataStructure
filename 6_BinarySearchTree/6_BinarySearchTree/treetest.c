#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if ((!test)) {FAIL(); return 1; } } while (0)
#define _verify(test) do {int r = test(); tests_run++; if (r) return r; } while(0)
#define square(n) (n)*(n)
#include "tree.h"
#include "binarySearchTree.h"
#include "linkedlist.h"
#include "FirstSearch.h"
#include <stdio.h>

int tests_run = 0;

int makeTree_01()
{
	BTree* mock = makeBTree(2);
	insertBTree(&mock, 1);
	insertBTree(&mock, 3);
	_assert(mock->key == 2);
	_assert(mock->left->key == 1);
	_assert(mock->right->key == 3);
	return 0;
}
int leftright_01()
{
	BTree* mock = makeBTree(2);
	BTreeNode* current = mock;
	insertBTree(&mock, 1);
	insertBTree(&mock, 3);
	initGoingCount();
	current = goLeft(current);
	_assert((getGoingCount() == 1));
	_assert((mock->left->key == 1));
	current = mock;
	current = goRight(mock);
	_assert((getGoingCount() == 2));
	_assert((current->key == 3));
	return 0;
}
int searchBTree_01()
{
	BTree* mock = makeBTree(2);
	BTree* toFind;
	insertBTree(&mock, 1);
	insertBTree(&mock, 3);			// 2
	insertBTree(&mock, 4);		//   1   3
	insertBTree(&mock, 2);	 //            4
	insertBTree(&mock, 7);  //              7
	initGoingCount();
	toFind = searchBTree(mock, 7);
	_assert((getGoingCount() == 3));
	_assert((toFind->key == 7));
	return 0;
}
int deleteBTree_01()
{
	BTree* mock = makeBTree(2);
	insertBTree(&mock, 1);
	insertBTree(&mock, 3);
	deleteBTree(&mock, 1);
	_assert((mock->left == NULL));
	return 0;
}
int BST_FirstSearch_01()
{
	BTree* mock = makeBTree(300);
	insertBTree(&mock, 600);
	insertBTree(&mock, 350);
	insertBTree(&mock, 200);
	insertBTree(&mock, 400);
	insertBTree(&mock, 750);
	insertBTree(&mock, 110);
	printf("%d\n", FirstSearchBTree(mock, 10));
	printf("%d\n", FirstSearchBTree(mock, 100));
	printf("%d\n", FirstSearchBTree(mock, 100));
	printf("%d\n", FirstSearchBTree(mock, 100));
	printf("%d\n", FirstSearchBTree(mock, 400));
	printf("%d\n", FirstSearchBTree(mock, 350));
	printf("%d\n", FirstSearchBTree(mock, 600));
	printf("%d\n", FirstSearchBTree(mock, 750));
	printf("%d\n", FirstSearchBTree(mock, 300));
	printBTree(mock);
	return 0;
}
int BST_List_01()
{
	BTree* mock = makeBTree(300);
	insertBTree(&mock, 600);
	insertBTree(&mock, 350);
	insertBTree(&mock, 200);
	insertBTree(&mock, 400);
	insertBTree(&mock, 750);
	insertBTree(&mock, 110);
	deleteBTree(&mock, 600);
	printBTree(mock);
	printf("\n%d\n", getGoingCount());
	return 0;
}
int USL_insertdelete_01()
{
	ListHeader* UST = makeLinkedList();
	insertListNode(&UST, makeListNode(300));
	insertListNode(&UST, makeListNode(600));
	insertListNode(&UST, makeListNode(350));
	insertListNode(&UST, makeListNode(200));
	_assert((UST->first->data == 300));
	_assert((UST->first->link->data == 600));
	_assert((UST->first->link->link->data == 350));
	_assert((UST->first->link->link->link->data == 200));
	removeListNode(&UST, makeListNode(350));
	_assert((UST->first->data == 300));
	_assert((UST->first->link->data == 600));
	_assert((UST->first->link->link->data == 200));
	return 0;
}
int USL_search_01()
{
	ListHeader* UST = makeLinkedList();
	insertListNode(&UST, makeListNode(300));
	insertListNode(&UST, makeListNode(600));
	insertListNode(&UST, makeListNode(350));
	insertListNode(&UST, makeListNode(200));
	_assert((searchListNode(UST,300)->data == 300));
	_assert((searchListNode(UST,600)->data == 600));
	removeListNode(&UST, makeListNode(200));
	_assert((searchListNode(UST,200) == NULL));
	return 0;
}
int USL_FirstSearch_01()
{
	ListHeader* UST = makeLinkedList();
	insertListNode(&UST, makeListNode(300));
	insertListNode(&UST, makeListNode(600));
	insertListNode(&UST, makeListNode(350));
	insertListNode(&UST, makeListNode(200));
	insertListNode(&UST, makeListNode(400));
	insertListNode(&UST, makeListNode(700));
	insertListNode(&UST, makeListNode(800));
	initGoingCountList();
	FirstSearchUSL(UST, 100);
	FirstSearchUSL(UST, 100);
	FirstSearchUSL(UST, 300);
	FirstSearchUSL(UST, 600);
	FirstSearchUSL(UST, 350);
	FirstSearchUSL(UST, 200);
	FirstSearchUSL(UST, 400);
	FirstSearchUSL(UST, 700);
	FirstSearchUSL(UST, 800);
	printf("%d\n", getGoingCountList());
	displayListNode(UST);
	return 0;
}
int all_tests() {/*
	_verify(makeTree_01);
	_verify(leftright_01);
	_verify(searchBTree_01);
	_verify(deleteBTree_01);
	_verify(USL_insertdelete_01);
	_verify(USL_search_01);*//*
	_verify(USL_FirstSearch_01);*/
	_verify(BST_FirstSearch_01);
	return 0;
}
int testmain() {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run : %d\n", tests_run);

	return result != 0;
}

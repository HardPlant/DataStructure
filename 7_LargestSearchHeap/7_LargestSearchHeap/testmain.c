#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if ((!test)) {FAIL(); return 1; } } while (0)
#define _verify(test) do {int r = test(); tests_run++; if (r) return r; } while(0)
#include "binarySearchTree.h"
#include "MaxHeap.h"
#include "main.h"
#include <stdio.h>

int isMaxHeap(MaxHeap* mock, int index);

int tests_run = 0;
int testMaxHeap(MaxHeap* mock)
{
	return isMaxHeap(mock, 1);
}
int isMaxHeap(MaxHeap* mock, int index)
{
	if (!isNull(mock, index))
	{
		int left = MHgoLeft(index);
		int right = MHgoRight(index);
		if (mock->heap[left].key < mock->heap[index].key
			&& mock->heap[right].key < mock->heap[index].key)
			return 1 * isMaxHeap(mock,MHgoLeft(index)) * isMaxHeap(mock, MHgoRight(index));
		else
			return 0;
	}
	return 1;
}
int makeTree_01()
{
	MaxHeap* mock = makeMaxHeap();
	MHelement item;
	item.key = 300;
	insertMaxHeap(mock, item);
	item.key = 600;
	insertMaxHeap(mock, item);
	item.key = 350;
	insertMaxHeap(mock, item);
	item.key = 200;
	insertMaxHeap(mock, item);
	item.key = 750;
	insertMaxHeap(mock, item);
	item.key = 115;
	insertMaxHeap(mock, item);
	item.key = 125;
	insertMaxHeap(mock, item);
	item.key = 75;
	insertMaxHeap(mock, item);
	item.key = 150;
	insertMaxHeap(mock, item);
	item.key = 250;
	insertMaxHeap(mock, item);
	item.key = 320;
	insertMaxHeap(mock, item);
	item.key = 270;
	insertMaxHeap(mock, item);
	item.key = 170;
	insertMaxHeap(mock, item);
	item.key = 500;
	insertMaxHeap(mock, item);
	item.key = 450;
	insertMaxHeap(mock, item);
	item.key = 330;
	insertMaxHeap(mock, item);
	item.key = 620;
	insertMaxHeap(mock, item);
	item.key = 800;
	insertMaxHeap(mock, item);
	deleteMaxHeap(mock);
	maxHeapLargestSearch(mock, 500);
	maxHeapLargestSearch(mock, 358);
	maxHeapLargestSearch(mock, 200);
	maxHeapLargestSearch(mock, 375);
	_assert((testMaxHeap(mock) == 1));
	return 0;
}
int all_tests() {
	_verify(makeTree_01);
	return 0;
}
int testmain() {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run : %d\n", tests_run);

	return result != 0;
}

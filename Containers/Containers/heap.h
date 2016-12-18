#ifndef  HEAP_H
#define HEAP_H
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAX_ELEMENT 100
typedef struct
{
	int key;
}MinHeap_element;

typedef struct
{
	MinHeap_element heap[MAX_ELEMENT];
	int heap_size;
}minHeap;
void minHeap_init(minHeap *h);
int minHeap_isEmpty(minHeap *h);
void minHeap_insert_min_heap(minHeap *h, MinHeap_element item);
MinHeap_element minHeap_delete_min_heap(minHeap *h);

MinHeap_element Heap_makeItem(int key);

#endif // ! HEAP_H

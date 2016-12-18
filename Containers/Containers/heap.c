#include "heap.h"

MinHeap_element Heap_makeItem(int key)
{
	MinHeap_element item;
	item.key = key;
	return item;
}
void minHeap_init(minHeap *h)
{
	h->heap_size = 0;
}
int minHeap_isEmpty(minHeap *h)
{
	if (h->heap_size == 0)
		return TRUE;
	else
		return FALSE;
}

void minHeap_insert_min_heap(minHeap *h, MinHeap_element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) // 차이점 1 (max는 > )
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
MinHeap_element minHeap_delete_min_heap(minHeap *h)
{
	int parent, child;
	MinHeap_element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) &&
			(h->heap[child].key > h->heap[child + 1].key)) // 차이점 2 (max는 <)
			child++;
		if (temp.key <= h->heap[child].key) break; // 차이점 3(max는 >=)
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void _minHeap_list(minHeap *h, int index)
{
	if ((h->heap[index].key >0))
	{
		printf("%d ", h->heap[index].key);
		_minHeap_list(h, index * 2);
		_minHeap_list(h, index * 2 + 1);
	}
	else
		printf("- ", h->heap[index].key);
}
void minHeap_list(minHeap *h)
{
	_minHeap_list(h, 1);
	printf("\n");
}

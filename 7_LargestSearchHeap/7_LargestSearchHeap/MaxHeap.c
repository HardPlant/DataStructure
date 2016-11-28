#include "MaxHeap.h"
#include <stdio.h>
#include <stdlib.h>
MHRefCount = 0;
MaxHeap* makeMaxHeap()
{
	MaxHeap* toMake = (MaxHeap*)malloc(sizeof(MaxHeap));
	int index;
	toMake->heap_size = 0;
	for (index = 0; index < MAX_ELEMENT; index++)
	{
		toMake->heap[index].key = 0;
	}
	return toMake;
}
void insertMaxHeap(MaxHeap *head, MHelement item)
{
	int i, parent;
	i = ++(head->heap_size);
	parent = MHgoParent(i);
	while ((i != 1) && (item.key > MHgetKey(head,parent)))
	{
		head->heap[i] = head->heap[parent];
		i = parent;
		parent = MHgoParent(i);
	}
	head->heap[i] = item;

}
MHelement deleteMaxHeap(MaxHeap *head)
{
	int parent, child;
	MHelement item, temp;
	item = head->heap[1];
	temp = head->heap[(head->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= head->heap_size)
	{
		if ((child < head->heap_size)
			&& (head->heap[child].key) < head->heap[child + 1].key)
			child++;
		if (temp.key >= head->heap[child].key)
			break;
		head->heap[parent] = head->heap[child];
		parent = child;
		child *= 2;
	}
	head->heap[parent] = temp;
	return item;
}
KeyType searchMaxHeap(MaxHeap *head, KeyType key)
{
	int left, right, current;
	current = 1;
	while (head->heap[current].key != key)
	{
		left = MHgoLeft(current);
		right = MHgoRight(current);
		if (isNull(head,current)) // 단말 노드 도달
		{
			return -1;
		}

		if (head->heap[left].key < key && head->heap[right].key < key) // 키가 현재 노드값이 아니고 자식 노드들보다 클 경우 실패
		{
			return -1;
		}
		if (head->heap[left].key < key && head->heap[right].key >= key)
			current = right;
		else
			current = left;
	}
}
void listMaxHeap(MaxHeap *head)
{
	int rootIndex = 1;
	postOrderPrint(head, rootIndex);
	printf("\n");
}
void postOrderPrint(MaxHeap *head, int current)
{
	if (!isNull(head, current))
	{
		printf("%d ", head->heap[current].key);
		postOrderPrint(head, MHgoLeft(current));
		postOrderPrint(head, MHgoRight(current));
	}
}
void initMHRefCount()
{
	MHRefCount = 0;
}

int getMHRefCount(char* str)
{
	printf("%s 시 방문 횟수 : %d\n", str, MHRefCount);
	return MHRefCount;
}
int MHgoLeft(int index)
{
	MHRefCount++;
	return index * 2;
}
int MHgoRight(int index)
{
	MHRefCount++;
	return (index * 2)+1;
}
int MHgoParent(int index)
{
	MHRefCount++;
	return index / 2;
}
int MHgetKey(MaxHeap *head, int current)
{
	if (current == 1) MHRefCount++;
	return head->heap[current].key;
}
int isNull(MaxHeap *head, int current)
{
	if (head->heap[current].key == 0)
		return 1;
	else
		return 0;
}
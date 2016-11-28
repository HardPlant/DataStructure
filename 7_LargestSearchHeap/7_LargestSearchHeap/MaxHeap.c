#include "MaxHeap.h"
#include <stdio.h>
#include <stdlib.h>
MaxHeap* makeMaxHeap()
{
	MaxHeap* toMake = (MaxHeap*)malloc(sizeof(MaxHeap));
	toMake->heap_size = 0;
	return toMake;
}
void insertMaxHeap(MaxHeap *head, element item)
{
	int i;
	i = ++(head->heap_size);
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h - head[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
element deleteMaxHeap(MaxHeap *head)
{
	int parent, child;
	element item, temp;
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
		left = goLeft(current);
		right = goRight(current);
		if (head->heap[left].key == 0 && head->heap[right].key == 0) // 단말 노드 도달
		{
			fprintf(stderr, "찾을 수 없음\n");
			return -1;
		}

		if (head->heap[left].key < key && head->heap[right].key < key) // 키가 현재 노드값이 아니고 자식 노드들보다 클 경우 실패
		{
			fprintf(stderr, "찾을 수 없음\n");
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
	inorderPrint(head, rootIndex);
}
void inorderPrint(MaxHeap *head, int current)
{
	if (!isNull(head, current))
	{
		inorderPrint(head, goLeft(current));
		printf("%d ", head->heap[current].key);
		inorderPrint(head, goRight(current));
	}
}
int goLeft(int index)
{
	return index * 2;
}
int goRight(int index)
{
	return (index * 2)+1;
}
int goParent(int index)
{
	return index / 2;
}
int isNull(MaxHeap *head, int current)
{
	if (head->heap[current].key == 0)
		return 1;
	else
		return 0;
}
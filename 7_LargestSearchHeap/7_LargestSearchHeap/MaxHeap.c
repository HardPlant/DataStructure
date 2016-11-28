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
	int parent, leftChild,rightChild;
	MHelement item, temp;
	item = head->heap[1];
	temp = head->heap[(head->heap_size)--];
	parent = 1;
	leftChild = MHgoLeft(parent);
	rightChild = MHgoRight(parent);
	while (leftChild <= head->heap_size)
	{
		if ((leftChild < head->heap_size))
		{
			if (MHgetKey(head,leftChild) >= MHgetKey(head,rightChild))
				head->heap[parent] = head->heap[leftChild];
			else if (MHgetKey(head, leftChild) < MHgetKey(head, rightChild))
				head->heap[parent] = head->heap[rightChild];
		}
		if (temp.key >= head->heap[leftChild].key)
			break;
		parent = leftChild;
		rightChild = MHgoRight(leftChild); 
		leftChild = MHgoLeft(leftChild);
		
	}
	head->heap[parent] = temp;
	return item;
}
int searchMaxHeap(MaxHeap *head, KeyType key)
{
	int left, right, current;
	current = 1;
	int index;
	for (index = 1; index < head->heap_size; index++)
	{
		MHRefCount++;
		left = MHgoLeft(index);
		right = MHgoRight(index);
		if (head->heap[index].key == key)
			return index;
		if (MHgetKey(head, left) < key && MHgetKey(head, right) < key)
			break;
	}
	return -1;
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
	printf("%s ½Ã ¹æ¹® È½¼ö : %d\n", str, MHRefCount);
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
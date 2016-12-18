#include "ComplexSort.h"
#include "../../Containers/Containers/heap.h"
#define SWAP(x,y,tmp) ( (tmp)=(x),(x)=(y),(y)=(tmp) )
int partition(int list[], int leftIndex, int rightIndex)
{
	int pivot, temp;
	int lowIndex, highIndex;
	lowIndex = leftIndex;
	highIndex = rightIndex+1;
	pivot = list[leftIndex];
	printf("------pivot %d ([%d]) \n", pivot, leftIndex);
	do
	{
		do lowIndex++; while (lowIndex <= rightIndex && list[lowIndex] < pivot);
		do highIndex--; while (highIndex >= leftIndex && list[highIndex] > pivot);

		if (lowIndex < highIndex)
		{
			SWAP(list[lowIndex], list[highIndex], temp);
			for (int i = 0; i < 9; i++)
				printf("%d ", list[i]);
			printf("\n");
		}

	} while (lowIndex < highIndex);

	SWAP(list[leftIndex], list[highIndex], temp);
	for (int i = 0; i < 9; i++)
		printf("%d ", list[i]);
	printf("\n");
	return highIndex;
}
void _quickSort(int list[], int left, int right)
{
	if (left < right)
	{
		int q = partition(list, left, right);
		_quickSort(list, left, q - 1);
		_quickSort(list, q+1, right);
	}
}
void quickSort(int list[], int length)
{
	_quickSort(list, 0, length - 1);
}

void heapSort(int list[], int length)
{
	minHeap heap;
	minHeap_init(&heap);
	for (int i = 0; i < length; i++)
	{
		minHeap_insert_min_heap(&heap, (MinHeap_element) { list[i] });
		minHeap_list(&heap);
	}
	for (int i = 0; i < length; i++)
	{
		list[i] = minHeap_delete_min_heap(&heap).key;
		minHeap_list(&heap);
	}


}
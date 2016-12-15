#include "ComplexSort.h"
#include <iostream>
#include <queue>
#include <functional>
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

		if (lowIndex < highIndex) SWAP(list[lowIndex],list[highIndex], temp);

	} while (lowIndex < highIndex);

	SWAP(list[leftIndex], list[highIndex], temp);
	printf("After: high = %d\n",highIndex);
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
using namespace std;
void heap_view(priority_queue<int, vector<int>, greater<int>> queue)
{
	while (!queue.empty())
	{
		cout << queue.top() << " ";
		queue.pop();
	}
	cout << endl;
}
void heapSort(int list[], int length)
{
	using namespace std;

	priority_queue<int,vector<int>,greater<int>> heap;
	
	int i = 0;
	for (i = 0; i < length; i++)
	{
		heap.emplace(list[i]);
		heap_view(heap);
	}
	printf("-----------\n");
	for (i = 0; i < length; i++)
	{
		list[i] = heap.top();
		heap.pop();
		heap_view(heap);
	}
}

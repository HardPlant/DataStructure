#include "SimpleSort.h"
#define SWAP(x,y,tmp) ( (tmp)=(x),(x)=(y),(y)=(tmp) )

void selectSort(int list[], int length)
{
	int current, exchange, tmp;
	int leastIndex = 0;
	for (current = 0; current < length - 1; current++)
	{
		leastIndex = current;
		for (exchange = current + 1; exchange < length; exchange++)
		{
			if (list[leastIndex] > list[exchange])
				leastIndex = exchange;
		}
		SWAP(list[current], list[leastIndex], tmp);
	}
}
void insertSort(int list[], int length)
{
	int current, goRight;
	int key;
	for (current = 1; current < length - 1; current++)
	{
		key = list[current];
		for (goRight = current - 1; current >= 0 && key < list[goRight]; goRight--)
		{
			list[goRight + 1] = list[goRight];
		}
		list[goRight + 1] = key;
	}
}
void bubbleSort(int list[], int length)
{
	int current, exchange, tmp;
	for (current = length - 1; current > 0; current--)
	{
		for (exchange = 0; exchange < current; exchange++)
			if (list[exchange] > list[exchange + 1])
				SWAP(list[exchange], list[exchange + 1], tmp);
	}
}

void inc_insertSort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap)
	{
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}


void shellSort(int list[], int length)
{
	int i, gap;
	for (gap = length / 2; gap > 0; gap / 2)
	{
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertSort(list, i, length - 1, gap);

	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#define INPUT_END -65535

int main()
{
	char DStoUse[20] = "\0";
	getDS(DStoUse);
	if (strncmp(DStoUse, "BST", sizeof("BST")) == 0)
		BSTLoopEntry();
	if (strncmp(DStoUse, "MaxHeap", sizeof("MaxHeap")) == 0)
		MaxHeapLoopEntry();
}
void getDS(char DStoUse[])
{
	do
	{
		printf("자료구조 : MaxHeap, BST\n");
		printf("사용할 자료구조를 입력하세요: ");
		scanf_s("%s",DStoUse,20);
	} while (!isAvailableDS(DStoUse));
}
void BSTLoopEntry()
{
	char input[100];
	BTree* createdDS;
	int* ints;
	int* current;
	createdDS = NULL;
	printf("입력 예 : \n\t Insert 300, 600, 200 \n\t List \n\t Search 500, 358\n");
	while (1)
	{
		printf("무엇을 할까요? (Insert, Search, List) : ");
		scanf_s("%s", input, sizeof(input));
		if (isCommand(input))
		{
			if (strncmp(input, "Insert", sizeof("Insert")) == 0)
			{
				ints = getMultipleInt();
				current = ints;
				while (*current != INPUT_END)
				{
					insertBTree(&(createdDS), *current);
					current++;
				}
				free(ints);
			}
			if (strncmp(input, "Search", sizeof("Search")) == 0)
			{
				ints = getMultipleInt();
				current = ints;
				while (*current != INPUT_END)
				{
					BTreeLargestSearch(createdDS, *current);
					current++;
				}
				free(ints);
			}
			if (strncmp(input, "List", sizeof("List")) == 0)
			{
				printBTree(createdDS);
			}
		}
		else
		{
			printf("잘못 입력하셨습니다.\n");
		}
	}
}
void MaxHeapLoopEntry()
{
	char input[100];
	MaxHeap* createdDS = makeMaxHeap();
	int* ints;
	int* current;
	MHelement item;
	printf("입력 예 : \n\t Insert 300, 600, 200 \n\t List \n\t Search 500, 358\n");
	while (1)
	{
		printf("무엇을 할까요? (Insert, Search, List) : ");
		scanf_s("%s", input, sizeof(input));
		if (isCommand(input))
		{
			if (strncmp(input, "Insert", sizeof("Insert")) == 0)
			{
				ints = getMultipleInt();
				current = ints;
				while (*current != INPUT_END)
				{
					item.key = *current;
					insertMaxHeap(createdDS, item);
					current++;
				}
				free(ints);
			}
			if (strncmp(input, "Search", sizeof("Search")) == 0)
			{
				ints = getMultipleInt();
				current = ints;
				while (*current != INPUT_END)
				{
					maxHeapLargestSearch(createdDS, *current);
					current++;
				}
				free(ints);
			}
			if (strncmp(input, "List", sizeof("List")) == 0)
			{

				listMaxHeap(createdDS);
				
			}
		}
		else
		{
			printf("잘못 입력하셨습니다.\n");
		}
	}
}
int isAvailableDS(char DStoUse[])
{
	if (strncmp(DStoUse, "BST", sizeof("BST")) == 0) return 1;
	if (strncmp(DStoUse, "MaxHeap", sizeof("MaxHeap")) == 0) return 1;
	else return 0;
}
int isCommand(char input[])
{
	if (strncmp(input, "Insert", sizeof("Insert")) == 0) return 1;
	if (strncmp(input, "Search", sizeof("Search")) == 0) return 1;
	if (strncmp(input, "List", sizeof("List")) == 0) return 1;
	return 0;
}

int* getMultipleInt()
{
	char input[100];
	char* splittedNumber;
	char* left;
	int in;
	int* list = (int*)calloc(20,sizeof(int));
	int index = 0;
	while (1)
	{
		if (isInputEnd()) break;

		scanf_s("%s", input, sizeof(input));

		splittedNumber = strtok_s(input, ",", &left);
		while (splittedNumber != NULL)
		{
			in = atoi(splittedNumber);
			list[index] = in;
			index++;
			splittedNumber = strtok_s(NULL, ",", &left);
		}
	}
	list[index] = INPUT_END;
	return list;
}
int isInputEnd()
{
	char current;
	current = getc(stdin);
	if (current == '\n') return 1;
	ungetc(current, stdin);
	return 0;
}

void BTreeLargestSearch(BTree* head, ElementType item)
{
	BTree* largest, *current;
	int currentKey;
	initBTreeRefCount();
	if (head == NULL)
	{
		getBTreeRefCount("검색");
		return;
	}
	largest = head;
	while (largest->right != NULL)
	{
		largest = BTgoRight(largest);
	}
	if (largest->key < item)
	{
		getBTreeRefCount("검색");
		return;
	}
	current = head;
	while (current != NULL && BTgetKey(current) != item)
	{
		currentKey = BTgetKey(current);
		if (currentKey > item)
			current = BTgoLeft(current);
		else if (currentKey < item)
			current = BTgoRight(current);
	}
	if (current == NULL && largest->key > item)
	{
		insertBTree(&head, largest->key - item);
		deleteBTree(&head, largest->key);
	}
	else if (current->key == item)
		deleteBTree(&head, item);
	getBTreeRefCount("검색");
}
void maxHeapLargestSearch(MaxHeap *head, KeyType key)
{
	MaxHeap* largest = head;
	MHelement item;
	int currentIndex = 1;
	int leftIndex, rightIndex;
	initMHRefCount();
	if (MHgetKey(head, currentIndex) < key)
	{
		getMHRefCount("검색");
		return;
	}
	if (MHgetKey(head, currentIndex) == key)
	{
		deleteMaxHeap(head);
		getMHRefCount("검색");
		return;
	}
	if (MHgetKey(head, currentIndex) > key)
	{
		item.key = MHgetKey(largest, 1) - key;
		deleteMaxHeap(head);
		insertMaxHeap(head, item);
		getMHRefCount("검색");
		return;
	}
}
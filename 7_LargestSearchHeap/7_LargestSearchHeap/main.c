#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main()
{
	char DStoUse[20] = "\0";
	getDS(DStoUse);
	loopEntry(DStoUse);
}
void getDS(char DStoUse[])
{
	do
	{
		printf("자료구조 : MaxHeap, BST\n");
		printf("사용할 자료구조를 입력하세요: ");
		scanf_s("%s",DStoUse,sizeof(DStoUse));
	} while (!isAvailableDS(DStoUse));
}
void loopEntry(char DStoUse[])
{
	char input[100];
	void* createdDS;
	createdDS = allocateDS(DStoUse);
	printf("입력 예 : \n\t Insert 300, 600, 200 \n\t List \n\t Search 500, 358\n");
	while (1)
	{
		printf("무엇을 할까요? (Insert, Search, List) : ");
		scanf_s("%s", input, sizeof(input));
		if (isCommand(input))
		{
			excuteCommand(input, DStoUse, createdDS);
		}
		else
		{
			printf("잘못 입력하셨습니다.\n");
		}
	}
}
int* makeArray() // int 임시 함수
{
	int* toMake = (int*)malloc(sizeof(int));
	return toMake;
}
void* allocateDS(char DStoUse[])
{
	void* toAllocate = NULL;
	if (strncmp(DStoUse, "BST", sizeof("BST")) == 0)
	{
		toAllocate = (void*)makeArray();
	}
	if (strncmp(DStoUse, "MaxHeap", sizeof("MaxHeap")) == 0)
	{

	}
	return toAllocate;
}
int isAvailableDS(char DStoUse[])
{
	if (strncmp(DStoUse, "BST", sizeof("BST")) == 0) return 1;
	if (strncmp(DStoUse, "MaxHeap", sizeof("MaxHeap")) == 0) return 1;
	else return 0;
}
void parse(char input[], int size)
{
	printf("%s\n", input);
}
int isCommand(char input[])
{
	if (strncmp(input, "Insert", sizeof("Insert")) == 0) return 1;
	if (strncmp(input, "Search", sizeof("Search")) == 0) return 1;
	if (strncmp(input, "List", sizeof("List")) == 0) return 1;
	return 0;
}
void excuteCommand(char input[], char DStoUse[], void* createdDS)
{
	if (strncmp(input, "Insert", sizeof("Insert")) == 0)
	{
		selectInsert(DStoUse,createdDS);
	}
	if (strncmp(input, "Search", sizeof("Search")) == 0)
	{

	}
	if (strncmp(input, "List", sizeof("List")) == 0)
	{

	}
}
void selectInsert(char DStoUse[], void* createdDS)
{
	void(*insertFunc)(void*, int) = 0;
	if (strncmp(DStoUse, "BST", sizeof("BST")) == 0) insertFunc = insertBST;
	if (strncmp(DStoUse, "MaxHeap", sizeof("MaxHeap")) == 0) insertFunc = insertMaxHeap;
	insertCommand(createdDS, insertFunc);
}
void insertBST(void* createdDS, int data) // int 임시 함수
{
	printf("%d\n", data);
}
int insertCommand(void* createdDS, void*(*insertFunc)(void*, int))
{
	char input[100];
	char* splittedNumber;
	char* left;
	int in;
	while (1)
	{
		if (isInputEnd()) break;

		scanf_s("%s", input, sizeof(input));

		splittedNumber = strtok_s(input, ",", &left);
		while (splittedNumber != NULL)
		{
			in = atoi(splittedNumber);
			insertFunc(createdDS, in);
			splittedNumber = strtok_s(NULL, ",", &left);
		}
	}
	return 0;
}
void insertMaxHeap(void* createdDS, int data)
{
	printf("InsertMaxHeap\n");
	return 0;
}
int isInputEnd()
{
	char current;
	current = getc(stdin);
	if (current == '\n') return 1;
	ungetc(current, stdin);
	return 0;
}
//void selectList(char DStoUse[])
//{
//	int(*excute)();
//	if (strcpy(DStoUse, "BST") == 0) excute = listBST;
//	if (strcpy(DStoUse, "MaxHeap") == 0) excute = listMaxHeap;
//	return excute;
//}
//void selectSearch(char DStoUse[])
//{
//	int(*excute)();
//	if (strcpy(DStoUse, "BST") == 0) excute = largestSearchBST;
//	if (strcpy(DStoUse, "MaxHeap") == 0) excute = largestSearchMaxHeap;
//	return excute;
//}

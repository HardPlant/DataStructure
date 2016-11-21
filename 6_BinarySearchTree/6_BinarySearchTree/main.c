#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "FirstSearch.h"

void USLLoop()
{
	char buf[10] = "List";
	ListHeader* USL = makeLinkedList();
	while (!(strcmp(buf, "Exit\n") == 0))
	{
		fprintf(stdout, "Exit : 종료, Insert, Search, List 명령어 사용 가능 : ");
		fgets(buf, 10, stdin);
		if (strcmp(buf, "Insert\n") == 0)
		{
			char buf[10] = "a";
			int input;
			while (1)
			{
				fprintf(stdout, "Stop - 종료, 10자까지만 가능 : ");
				fgets(buf, 10, stdin);
				if (strcmp(buf, "Stop\n") == 0)
					break;
				input = atoi(buf);
				insertListNode(&USL, makeListNode(input));
				fflush(stdin);
			}
		}
		if (strcmp(buf, "Search\n") == 0)
		{
			char buf[10] = "a";
			int input;
			int count;
			while (1)
			{
				fprintf(stdout, "Stop - 종료, 10자까지만 가능 : ");
				fgets(buf, 10, stdin);
				if (strcmp(buf, "Stop\n") == 0)
					break;
				input = atoi(buf);
				count = FirstSearchUSL(USL, input);
				printf("방문횟수 : %d\n", count);
				fflush(stdin);
			}
		}
		if (strcmp(buf, "List\n") == 0)
		{
			fprintf(stdout, "현재 리스트 : ");
			displayListNode(USL);
			fprintf(stdout, "\n");
		}
		fflush(stdin);
	}
}

void BSTLoop()
{
	char buf[10] = "List";
	BTree* BST = NULL;
	while (!(strcmp(buf, "Exit\n") == 0))
	{
		fprintf(stdout, "Exit : 종료, Insert, Search, List 명령어 사용 가능 : ");
		fgets(buf, 10, stdin);
		if (strcmp(buf, "Insert\n") == 0)
		{
			char buf[10] = "a";
			int input;
			while (1)
			{
				fprintf(stdout, "Stop - 종료, 10자까지만 가능 : ");
				fgets(buf, 10, stdin);
				if (strcmp(buf, "Stop\n") == 0)
					break;
				input = atoi(buf);
				if (BST == NULL)
					BST = makeBTree(input);
				else
					insertBTree(&BST, input);
				fflush(stdin);
			}
		}
		if (strcmp(buf, "Search\n") == 0)
		{
			char buf[10] = "a";
			int input;
			int count;
			while (1)
			{
				fprintf(stdout, "Stop - 종료, 10자까지만 가능 : ");
				fgets(buf, 10, stdin);
				if (strcmp(buf, "Stop\n") == 0)
					break;
				input = atoi(buf);
				count = FirstSearchBTree(BST, input);
				printf("방문횟수 : %d\n", count);
				fflush(stdin);
			}
		}
		if (strcmp(buf, "List\n") == 0)
		{
			fprintf(stdout, "현재 리스트 : ");
			printBTree(BST);
			fprintf(stdout, "\n");
		}
		fflush(stdin);
	}
}

int main()
{
	char buf[10] = "USL";
	fprintf(stdout, "BST - 이진 트리, USL - 정렬되지 않은 리스트 : ");
	fgets(buf, 10, stdin);
	if (strcmp(buf, "BST\n") == 0)
		BSTLoop();
	else
		USLLoop();
	return 0;
}
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
void initGoingCountList()
{
	goingCountList = 0;
}

int getGoingCountList()
{
	return goingCountList;
}
ListNode* makeListNode(ElementType data)
{
	ListNode* toMake = (ListNode*)malloc(sizeof(ListNode));
	if (toMake == NULL)
		fprintf_s(stderr, "%s : 메모리 할당 실패", __func__);
	toMake->data = data;
	toMake->link = NULL;
	return toMake;
}
ListHeader* makeLinkedList()
{
	ListHeader* toMake = (ListHeader*)malloc(sizeof(ListHeader));
	if (toMake == NULL)
		fprintf_s(stderr, "%s : 메모리 할당 실패", __func__);
	toMake->first = NULL;
	toMake->last = NULL;
	return toMake;
}
void insertListNode(ListHeader **pHead, ListNode *newNode)
{
	goingCountList+= 1;
	if (*pHead == NULL || (*pHead)->first == NULL)
	{
		*pHead = makeLinkedList();
		(*pHead)->first = newNode;
		(*pHead)->last = newNode;
		printf("삽입 시 방문 횟수 :3회\n");
	}
	else
	{
		(*pHead)->last->link = newNode;
		(*pHead)->last = newNode;
		printf("삽입 시 방문 횟수 :2회\n");
	}
	
}

void removeListNode(ListHeader **phead, ListNode *removed)
{
	ListNode** current;
	if (*phead == NULL)
		return;
	current = &((*phead)->first);
	while (*current != NULL && (*current)->data != removed->data)
	{
		current = &((*current)->link);
		goingCountList += 1;
	}
	if (*current == NULL)
		return;
	else
	{
		if ((*current)->link != NULL)
		{
			(*current)->data = (*current)->link->data;
			(*current)->link = (*current)->link->link;
		}
		else
			(*current) = NULL;
	}
}
void displayListNode(ListHeader *head)
{
	ListNode* current;
	if (head == NULL)
		return NULL;
	current = head->first;
	while (current != NULL)
	{
		printf("%d->", current->data);
		current = current->link;
	}
	printf("\n");
}
ListNode* searchListNode(ListHeader *head, ElementType data)
{
	ListNode* current;
	if (head == NULL)
		return NULL;
	current = head->first;
	while (current != NULL)
	{
		goingCountList++;
		if (current->data == data)
			return current;
		current = current->link;
	}
	return NULL;
}

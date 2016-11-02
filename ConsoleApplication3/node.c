#include "node.h"
#include <stdio.h>
void error(char* msg)
{
	fprintf(stderr, msg);
	return -1;
}
Node* makeNode(int data)
{
	Node* toMake = (Node*)malloc(sizeof(Node));
	toMake->item = data;
	toMake->link = NULL;
	toMake->past = NULL;
	return toMake;
}

Queue* makeQueue()
{
	Queue* toMake = (Queue*)malloc(sizeof(Queue));
	toMake->head = NULL;
	toMake->tail = NULL;
	toMake->length = -1;
	return toMake;
}
int isEmpty(Queue* dest)
{
	if (dest->head == NULL) return 1;
	else return 0;
}
void enqueue(Queue* dest, ElementType data)
{
	Node* src = makeNode(data);
	if (src == NULL)
		error("�޸� �Ҵ� �Ұ�");
	if (isEmpty(dest))
	{
		dest->head = src;
		dest->tail = src;
	}
	else
	{
		dest->tail->link = src;
		src->past = dest->tail;
		dest->tail = src;
	}
	dest->length++;
}
ElementType peek(Queue* dest)
{
	if (isEmpty(dest))
	{
		error("ť�� ��� ����");
		return -1;
	}
	return dest->head->item;
}
ElementType dequeue(Queue* dest)
{
	Node* toPop;
	ElementType result;
	if (isEmpty(dest))
		error("ť�� ��� ����");
	else
	{
		toPop = dest->head;
		result = toPop->item;
		dest->head = dest->head->link;
		if (dest->head == NULL)
			dest->tail == NULL;
		else
			dest->head->past = NULL;
		free(toPop);
		dest->length--;
		return result;
	}
}
void destroy(Queue* dest)
{
	while (isEmpty(dest))
		dequeue(dest);
	free(dest);
}
void printQueue(Queue* dest)
{
	if (isEmpty(dest)) return -1;
	Node* current = dest->head;
	while (current != NULL)
	{
		printf("%d ", current->item);
		current = current->link;
	}
	printf("\n");
}
ElementType at(Queue* dest, int index)
{
	Node* current;
	int i;
	if (isEmpty(dest))
	{
		error("�� ť");
		return -1;
	}
	if (index > dest->length + 1)
	{
		error("ť ���� �ʰ�");
		return -1;
	}
	if (index == dest->length) return dest->tail->item;
	current = dest->head;
	for (i = 0; i < index; i++)
		if(current->link != NULL)
			current = current->link;
	return current->item;
}
int getKbonacciNumber(Queue* dest, int k)
{
	Node* beforeTail;
	int index, data;
	beforeTail = dest->tail;
	data = 0;
	for (index = 0; index < k; index++, beforeTail = beforeTail->past)
		data += beforeTail->item;
	return data;
}
void makeKbonacci(Queue* dest, int k, int n)
{
	int index;
	for(index = 0; index < k - 1; index++)
		enqueue(dest, 0);
	enqueue(dest,1);
	for(index = k; index < n; index++)
	{
		enqueue(dest,getKbonacciNumber(dest, k));
	}
}
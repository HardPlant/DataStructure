#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE_SIZE 100
#include "error.h"
typedef int QueueElement;
typedef struct {
	QueueElement queue[MAX_QUEUE_SIZE];
	int front, rear;
} CircularQueue;
void circularQueue_Init(CircularQueue *q);
int circularQueue_isEmpty(CircularQueue *q);
void circularQueue_enqueue(CircularQueue *q, QueueElement item);
QueueElement circularQueue_dequeue(CircularQueue *q);
QueueElement circularQueue_peek(CircularQueue *q);

typedef struct QueueNode
{
	QueueElement item;
	struct QueueNode *link;
}QueueNode;
typedef struct
{
	QueueNode *front, *rear;
}Queue;


void Queue_init(Queue *q);
int Queue_isEmpty(Queue *q);
void Queue_enqueue(Queue *q, QueueElement item);
QueueElement Queue_dequeue(Queue *q);
QueueElement Queue_peek(Queue *q);

#endif
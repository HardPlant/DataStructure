#include "queue.h"
void circularQueue_Init(CircularQueue *q)
{
	q->front = q->rear = 0;
}
int circularQueue_isEmpty(CircularQueue *q)
{
	return (q->front == q->rear);
}
int circularQueue_isFull(CircularQueue *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void circularQueue_enqueue(CircularQueue *q, QueueElement item)
{
	if (circularQueue_isFull(q))
		error("큐 포화");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
QueueElement circularQueue_dequeue(CircularQueue *q)
{
	if (circularQueue_isEmpty(q))
		error("큐 공백");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
QueueElement circularQueue_peek(CircularQueue *q)
{
	if (circularQueue_isEmpty(q))
		error("큐 공백");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}


void Queue_init(Queue *q)
{
	q->front = q->rear = NULL;
}
int Queue_isEmpty(Queue *q)
{
	return (q->front == NULL);
}
void Queue_enqueue(Queue *q, QueueElement item)
{
	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("메모리");
	else
	{
		temp->item = item;
		temp->link = NULL;
		if (Queue_isEmpty(q))
		{
			q->front = temp;
			q->rear = temp;
		}
		else
		{
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}
QueueElement Queue_dequeue(Queue *q)
{
	QueueNode *temp = q->front;
	QueueElement item;

	if (Queue_isEmpty(q))
	{
		error("큐 공백");
	}
	else
	{
		item = temp->item;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return item;
	}
}
QueueElement Queue_peek(Queue *q)
{
	if (Queue_isEmpty(q))
		error("큐 공백");
	else
		return q->front->item;
}
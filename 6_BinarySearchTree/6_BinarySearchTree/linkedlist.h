#ifndef	LINKEDLIST_H_1
#define LINKEDLIST_H_1
typedef int ElementType;
typedef struct ListNode
{
	ElementType data;
	struct ListNode* link;
}ListNode;

typedef struct ListHeader
{
	struct ListNode* first;
	struct ListNode* last;
}ListHeader;

ListNode* makeListNode(ElementType data);
ListHeader* makeLinkedList();
void insertListNode(ListHeader **pHead, ListNode *newNode);
void removeListNode(ListHeader **phead, ListNode *removed);
void displayListNode(ListHeader *head);
ListNode* searchListNode(ListHeader *head, ElementType data);
int goingCountList;
void initGoingCountList();
int getGoingCountList();
#endif
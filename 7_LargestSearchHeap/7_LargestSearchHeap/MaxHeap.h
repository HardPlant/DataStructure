#ifndef MAX_HEAP
#define MAX_HEAP
#define MAX_ELEMENT 200
typedef int KeyType;
typedef struct {
	KeyType key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

typedef HeapType MaxHeap;
MaxHeap* makeMaxHeap();
void insertMaxHeap(MaxHeap *heap, element item);
element deleteMaxHeap(MaxHeap *heap);
KeyType searchMaxHeap(MaxHeap *head, KeyType key);

int goLeft(int index);
int goRight(int index);
int goParent(int index);
#endif

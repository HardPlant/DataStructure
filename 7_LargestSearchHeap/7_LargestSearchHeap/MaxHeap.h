#ifndef MAX_HEAP
#define MAX_HEAP
#define MAX_ELEMENT 200
typedef int KeyType;
typedef struct {
	KeyType key;
} MHelement;
typedef struct {
	MHelement heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

typedef HeapType MaxHeap;
MaxHeap* makeMaxHeap();
void insertMaxHeap(MaxHeap *heap, MHelement item);
void insertMaxHeapInt(MaxHeap *head, int data);
MHelement deleteMaxHeap(MaxHeap *heap);
KeyType searchMaxHeap(MaxHeap *head, KeyType key);
void listMaxHeap(MaxHeap *head);
void inorderPrint(MaxHeap *head, int current);

int MHgoLeft(int index);
int MHgoRight(int index);
int MHgoParent(int index);
int isNull(MaxHeap *head, int current);
#endif

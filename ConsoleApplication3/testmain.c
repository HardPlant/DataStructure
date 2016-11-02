#include <stdio.h>
#include "node.h"
#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if ((!test)) {FAIL(); return 1; } } while (0)
#define _verify(test) do {int r = test(); tests_run++; if (r) return r; } while(0)
#define square(n) (n)*(n)
int tests_run = 0;

int square_01() {
	int x = 5;
	_assert(square(x) == 25);
	return 0;
}
int makeNode_01() {
	Node* testnode = makeNode(1);
	_assert(testnode!= NULL);
	_assert(testnode->item == 1);
	_assert(testnode->link == NULL);
	free(testnode);
	return 0;
}
int makeQueue_01() {
	Queue* testnode = makeQueue();
	_assert((testnode->head == NULL));
	_assert((testnode->tail == NULL));
	_assert((testnode->length == -1));
	_assert(isEmpty(testnode));
	free(testnode);
	return 0;
}
int enqueue_01() {
	Queue* testnode = makeQueue();
	enqueue(testnode, 5);
	_assert(testnode->head->item == 5);
	enqueue(testnode, 7);
	_assert(testnode->tail == 7);
	free(testnode);

	return 0;
}

int peek_01() {
	Queue* testnode = makeQueue();
	Node* entry = makeNode(1);
	enqueue(testnode, entry);
	_assert(peek(testnode) == 1);
	free(entry);
	free(testnode);
	return 0;
}
int dequeue_01() {
	Queue* testnode = makeQueue();
	enqueue(testnode, 5);
	enqueue(testnode, 7);
	_assert(dequeue(testnode) == 5);
	_assert(!isEmpty(testnode));
	_assert(dequeue(testnode) == 7);
	_assert(isEmpty(testnode));
	free(testnode);
	return 0;
}
int at_01() {
	Queue* testnode = makeQueue();
	enqueue(testnode, 4);
	enqueue(testnode, 7);
	enqueue(testnode, 5);
	_assert(at(testnode,0) == 4);
	_assert(at(testnode,1) == 7);
	_assert(at(testnode,2) == 5);
	destroy(testnode);
	return 0;
}
int makeKbonacci_01() {
	Queue* testnode = makeQueue();
	int k = 2;
	int n = 1;
	makeKbonacci(testnode, k, n);
	_assert(!isEmpty(testnode));
	_assert(at(testnode, 0) == 0);
	_assert(at(testnode, 1) == 1);
	destroy(testnode);
	return 0;
}
int makeKbonacci_02() {
	Queue* testnode = makeQueue();
	int k = 3;
	int n = 6;
	makeKbonacci(testnode, k, n);
	_assert(at(testnode, 0) == 0);
	_assert(at(testnode, 1) == 0);
	_assert(at(testnode, 2) == 1);
	_assert(at(testnode, 3) == 1);
	_assert(at(testnode, 4) == 2);
	_assert(at(testnode, 4) == 4);
	destroy(testnode);
	return 0;
}
int makeKbonacci_03() {
	Queue* testnode = makeQueue();
	int k = 4;
	int n = 9;
	makeKbonacci(testnode, k, n);
	_assert(at(testnode, 0) == 0);
	_assert(at(testnode, 1) == 0);
	_assert(at(testnode, 2) == 0);
	_assert(at(testnode, 3) == 1);
	_assert(at(testnode, 4) == 2);
	_assert(at(testnode, 5) == 3);
	_assert(at(testnode, 6) == 6);
	_assert(at(testnode, 7) == 12);
	_assert(at(testnode, 8) == 12+6+3+2);
	destroy(testnode);
	return 0;
}
int all_tests() {
	_verify(square_01);
	_verify(makeNode_01);
	_verify(enqueue_01);
	_verify(peek_01);
	_verify(dequeue_01);
	_verify(at_01);
	_verify(makeKbonacci_01);
	_verify(makeKbonacci_02);
	_verify(makeKbonacci_03);
	return 0;
}
int testmain() {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run : %d\n", tests_run);

	return result != 0;
}
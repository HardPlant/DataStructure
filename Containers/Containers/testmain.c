#define _assert(message, test) do { if (!(test)) return message; } while (0)
#define _run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
#include "error.h"
#include "graph.h"
#include "queue.h"
#include "tree.h"
#include "heap.h"
#include <stdio.h>

int tests_run = 0;

static char * createQueue01() {
	Queue queue;
	Queue_init(&queue);
	Queue_enqueue(&queue, 0);
	Queue_enqueue(&queue, 1);
	Queue_enqueue(&queue, 2);
	_assert("", queue.front->item == 0);
	_assert("", queue.rear->item == 2);
	Queue_dequeue(&queue);
	_assert("", queue.front->item == 1);
	Queue_enqueue(&queue, 3);
	_assert("", queue.rear->item == 3);

	return 0;
}
static char * createGraph01() {
	matGraph graph;
	matGraph_init(&graph);
	matGraph_insert_vertex(&graph, 0);
	matGraph_insert_vertex(&graph, 1);
	matGraph_insert_vertex(&graph, 2);
	_assert("", graph.n == 3);
	matGraph_insert_vertex(&graph, 3);
	matGraph_insert_vertex(&graph, 4);
	matGraph_insert_edge(&graph, 0, 1);
	matGraph_insert_edge(&graph, 0, 2);
	matGraph_insert_edge(&graph, 0, 4);
	matGraph_insert_edge(&graph, 1, 2);
	matGraph_insert_edge(&graph, 2, 3);
	matGraph_insert_edge(&graph, 3, 4);
	matGraph_dfs(&graph, 0);
	printf("\n");
	matGraph_bfs(&graph, 0);
	printf("\n");
	return 0;
}
static char * createGraph02() {
	listGraph graph;
	listGraph_init(&graph);
	listGraph_insert_vertex(&graph, 0);
	listGraph_insert_vertex(&graph, 1);
	listGraph_insert_vertex(&graph, 2);
	_assert("", graph.n == 3);
	listGraph_insert_edge(&graph, 0, 1);
	listGraph_insert_edge(&graph, 0, 2);
	listGraph_insert_edge(&graph, 1, 2);
	listGraph_dfs(&graph, 0);
	printf("\n");
	listGraph_bfs(&graph, 0);
	printf("\n");
	return 0;
}
static char * GraphConnected01() {
	matGraph graph;
	matGraph_init(&graph);
	matGraph_insert_vertex(&graph, 0);
	matGraph_insert_vertex(&graph, 1);
	matGraph_insert_vertex(&graph, 2);
	_assert("", graph.n == 3);
	matGraph_insert_vertex(&graph, 3);
	matGraph_insert_vertex(&graph, 4);
	_assert("", !(graph.n == 3));
	matGraph_insert_edge(&graph, 0, 1);
	matGraph_insert_edge(&graph, 0, 2);
	matGraph_insert_edge(&graph, 3, 4);
	find_connected_component(&graph);
	print_visited();
	printf("\n");
	return 0;
}
static char * createMinHeap01()
{
	minHeap heap;
	int key;
	minHeap_init(&heap);
	minHeap_insert_min_heap(&heap, (MinHeap_element) { 4 });
	minHeap_insert_min_heap(&heap, (MinHeap_element) { 2 });
	minHeap_insert_min_heap(&heap, (MinHeap_element) { 1 });
	minHeap_insert_min_heap(&heap, (MinHeap_element) { 7 });
	key = minHeap_delete_min_heap(&heap).key;
	_assert("fail!", key == 1);
	key = minHeap_delete_min_heap(&heap).key;
	_assert("", key == 2);
	key = minHeap_delete_min_heap(&heap).key;
	_assert("", key == 4);
	key = minHeap_delete_min_heap(&heap).key;
	_assert("", key == 7);

	return 0;
}
static char * kruskal01()
{
	matGraph graph;
	matGraph_init(&graph);
	matGraph_insert_vertex(&graph, 0);
	matGraph_insert_vertex(&graph, 1);
	matGraph_insert_vertex(&graph, 2);
	matGraph_insert_vertex(&graph, 3);
	matGraph_insert_vertex(&graph, 4);
	matGraph_insert_vertex(&graph, 5);
	matGraph_insert_vertex(&graph, 6);
	matGraph_insert_weightedEdge(&graph, 0, 1, 29);
	matGraph_insert_weightedEdge(&graph, 1, 2, 16);
	matGraph_insert_weightedEdge(&graph, 2, 3, 12);
	matGraph_insert_weightedEdge(&graph, 3, 4, 22);
	matGraph_insert_weightedEdge(&graph, 4, 5, 27);
	matGraph_insert_weightedEdge(&graph, 5, 0, 10);
	matGraph_insert_weightedEdge(&graph, 6, 1, 15);
	matGraph_insert_weightedEdge(&graph, 6, 3, 18);
	matGraph_insert_weightedEdge(&graph, 6, 4, 25);
	printf("\kruskal : \n");

	kruskal(&graph);
	return 0;
}
static char * prim01()
{
	matGraph graph;
	matGraph_init(&graph);
	matGraph_insert_vertex(&graph, 0);
	matGraph_insert_vertex(&graph, 1);
	matGraph_insert_vertex(&graph, 2);
	matGraph_insert_vertex(&graph, 3);
	matGraph_insert_vertex(&graph, 4);
	matGraph_insert_vertex(&graph, 5);
	matGraph_insert_vertex(&graph, 6);
	matGraph_insert_weightedEdge(&graph, 0, 1, 29);
	matGraph_insert_weightedEdge(&graph, 1, 2, 16);
	matGraph_insert_weightedEdge(&graph, 2, 3, 12);
	matGraph_insert_weightedEdge(&graph, 3, 4, 22);
	matGraph_insert_weightedEdge(&graph, 4, 5, 27);
	matGraph_insert_weightedEdge(&graph, 5, 0, 10);
	matGraph_insert_weightedEdge(&graph, 6, 1, 15);
	matGraph_insert_weightedEdge(&graph, 6, 3, 18);
	matGraph_insert_weightedEdge(&graph, 6, 4, 25);
	printf("\nprim : \n");
	prim(&graph);
	printf("\n");
	return 0;
}
static char * dijkstra01()
{
	matGraph graph;
	matGraph_init(&graph);
	matGraph_insert_vertex(&graph, 0);
	matGraph_insert_vertex(&graph, 1);
	matGraph_insert_vertex(&graph, 2);
	matGraph_insert_vertex(&graph, 3);
	matGraph_insert_vertex(&graph, 4);
	matGraph_insert_vertex(&graph, 5);
	matGraph_insert_vertex(&graph, 6);
	matGraph_insert_weightedEdge(&graph, 0, 1, 7);
	matGraph_insert_weightedEdge(&graph, 0, 2, 29);
	matGraph_insert_weightedEdge(&graph, 1, 2, 16);
	matGraph_insert_weightedEdge(&graph, 2, 3, 12);
	matGraph_insert_weightedEdge(&graph, 3, 4, 22);
	matGraph_insert_weightedEdge(&graph, 4, 5, 27);
	matGraph_insert_weightedEdge(&graph, 5, 0, 10);
	matGraph_insert_weightedEdge(&graph, 6, 1, 15);
	matGraph_insert_weightedEdge(&graph, 6, 3, 18);
	matGraph_insert_weightedEdge(&graph, 6, 4, 25);
	printf("\ndijkstra : \n");
	shortest_path(&graph, 0);
	printf("\n");
	return 0;
}
static char * floyd01()
{
	matGraph graph;
	matGraph_init(&graph);
	matGraph_insert_vertex(&graph, 0);
	matGraph_insert_vertex(&graph, 1);
	matGraph_insert_vertex(&graph, 2);
	matGraph_insert_vertex(&graph, 3);
	matGraph_insert_vertex(&graph, 4);
	matGraph_insert_vertex(&graph, 5);
	matGraph_insert_vertex(&graph, 6);
	matGraph_insert_weightedEdge(&graph, 0, 1, 7);
	matGraph_insert_weightedEdge(&graph, 0, 2, 29);
	matGraph_insert_weightedEdge(&graph, 1, 2, 16);
	matGraph_insert_weightedEdge(&graph, 2, 3, 12);
	matGraph_insert_weightedEdge(&graph, 3, 4, 22);
	matGraph_insert_weightedEdge(&graph, 4, 5, 27);
	matGraph_insert_weightedEdge(&graph, 5, 0, 10);
	matGraph_insert_weightedEdge(&graph, 6, 1, 15);
	matGraph_insert_weightedEdge(&graph, 6, 3, 18);
	matGraph_insert_weightedEdge(&graph, 6, 4, 25);
	printf("\nployd : \n");
	floyd(&graph);
	printf("\n");
	return 0;
}
static char * tsort01()
{
	listGraph graph;
	listGraph_init(&graph);
	listGraph_insert_vertex(&graph, 0);
	listGraph_insert_vertex(&graph, 1);
	listGraph_insert_vertex(&graph, 2);
	listGraph_insert_vertex(&graph, 3);
	listGraph_insert_vertex(&graph, 4);
	listGraph_insert_vertex(&graph, 5);
	listGraph_insert_edge(&graph, 0, 2);
	listGraph_insert_edge(&graph, 0, 3);
	listGraph_insert_edge(&graph, 1, 3);
	listGraph_insert_edge(&graph, 1, 4);
	listGraph_insert_edge(&graph, 2, 3);
	listGraph_insert_edge(&graph, 2, 5);
	listGraph_insert_edge(&graph, 3, 5);
	listGraph_insert_edge(&graph, 4, 5);

	printf("\n");
	topo_sort(&graph);
	printf("\n");
	return 0;
}
static char * all_tests() {
	_run_test(createQueue01);
	_run_test(createGraph01);
	_run_test(GraphConnected01);
	_run_test(createMinHeap01);
	_run_test(kruskal01);
	_run_test(prim01);
	_run_test(dijkstra01);
	_run_test(floyd01);
	_run_test(tsort01);
	return 0;
}

int main(int argc, char **argv) {
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
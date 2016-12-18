#ifndef  GRAPH_H
#include "error.h"
#define GRAPH_H
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0
typedef struct {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}matGraph;

void matGraph_init(matGraph *g);
void matGraph_insert_vertex(matGraph *g, int v);
void matGraph_insert_edge(matGraph *g, int start, int end);
void matGraph_insert_weightedEdge(matGraph *g, int start, int end, int weight);

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType
{
	int n;
	GraphNode *adj_list[MAX_VERTICES];
}listGraph;
void listGraph_init(listGraph *g);
void listGraph_insert_vertex(listGraph *g, int v);
void listGraph_insert_edge(listGraph *g, int u, int v);

void visitedInit();

void matGraph_dfs(matGraph *g, int v);
void listGraph_dfs(listGraph *g, int v);

void matGraph_bfs(matGraph *g, int v);
void listGraph_bfs(listGraph *g, int v);

void find_connected_component(matGraph *g);
void print_visited();


#define MAX_ELEMENT 100
typedef struct
{
	int key;
	int u;
	int v;
}Kruskal_Element;

typedef struct
{
	Kruskal_Element heap[MAX_ELEMENT];
	int heap_size;
}Kruskal_GraphHeap;
void KruskalHeap_init(Kruskal_GraphHeap *h);
int KruskalHeap_isEmpty(Kruskal_GraphHeap *h);
void KruskalHeap_insert_min_heap(Kruskal_GraphHeap *h, Kruskal_Element item);
Kruskal_Element KruskalHeap_delete_min_heap(Kruskal_GraphHeap *h);

Kruskal_Element KruskalHeap_makeItem(int key);

int parent[MAX_VERTICES];
int num[MAX_VERTICES];

void set_init(int n);
int set_find(int vertex);
void set_union(int s1, int s2);

void kruskal(matGraph *target);

int selected[MAX_VERTICES];
int dist[MAX_VERTICES];

int get_min_vertex(int n);
void prim(matGraph *graph);


#endif // ! GRAPH_H

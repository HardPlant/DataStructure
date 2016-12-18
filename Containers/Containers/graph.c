#include "graph.h"
#include "queue.h"
#include "stack.h"
#include <stdlib.h>
void matGraph_init(matGraph *g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			if(r==c)
				g->adj_mat[r][c] = 0;
			else
				g->adj_mat[r][c] = INT_MAX / 4;
}
void matGraph_insert_vertex(matGraph *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
		error("정점개수 초과");
	g->n++;
}
void matGraph_insert_edge(matGraph *g, int start, int end)
{
	if (start >= g->n || end >= g->n)
		error("간선삽입: 정점번호 오류");
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
void matGraph_insert_weightedEdge(matGraph *g, int start, int end, int weight)
{
	if (start >= g->n || end >= g->n)
		error("정점번호 오류");
	g->adj_mat[start][end] = weight;
	g->adj_mat[end][start] = weight;
}
void listGraph_init(listGraph *g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
void listGraph_insert_vertex(listGraph *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
		error("정점개수");
	g->n++;
}
void listGraph_insert_edge(listGraph *g, int u, int v)
{
	GraphNode *node;
	if (u >= g->n || v >= g->n)
		error("번호오류");
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

int visited[MAX_VERTICES];
void visitedInit()
{
	int i = 0;
	for (i = 0; i < MAX_VERTICES; i++)
		visited[i] = 0;
}

void _matGraph_dfs(matGraph *g, int v)
{
	int w;
	visited[v] = TRUE;
	printf("%d ", v);
	for (w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited[w])
			_matGraph_dfs(g, w);
}
void matGraph_dfs(matGraph *g, int v)
{
	visitedInit();
	_matGraph_dfs(g, v);
}
void _listGraph_dfs(listGraph *g, int v)
{
	GraphNode *w;
	visited[v] = TRUE;
	printf("%d ", v);
	for (w = g->adj_list[v]; w ; w=w->link)
		if (!visited[w->vertex])
			_listGraph_dfs(g, w->vertex);
}
void listGraph_dfs(listGraph *g, int v)
{
	visitedInit();
	_listGraph_dfs(g, v);
}

void _matGraph_bfs(matGraph *g, int v)
{
	int w;
	Queue q;
	Queue_init(&q);
	visited[v] = TRUE;
	printf("%d ", v);
	Queue_enqueue(&q, v);
	while (!Queue_isEmpty(&q))
	{
		v = Queue_dequeue(&q);
		for(w=0;w<g->n;w++)
			if (g->adj_mat[v][w] && !visited[w])
			{
				visited[w] = TRUE;
				printf("%d ", w);
				Queue_enqueue(&q, w);
			}
	}
}
void matGraph_bfs(matGraph *g, int v)
{
	visitedInit();
	_matGraph_bfs(g, v);
}
void _listGraph_bfs(listGraph *g, int v)
{
	GraphNode *w;
	Queue q;
	Queue_init(&q);
	visited[v] = TRUE;
	printf("%d ", v);
	Queue_enqueue(&q, v);
	while (!Queue_isEmpty(&q))
	{
		v = Queue_dequeue(&q);
		for (w = g->adj_list[v]; w; w =w->link)
			if (!visited[w->vertex])
			{
				visited[w->vertex] = TRUE;
				printf("%d ", w->vertex);
				Queue_enqueue(&q, w->vertex);
			}
	}
}
void listGraph_bfs(listGraph *g, int v)
{
	visitedInit();
	_listGraph_bfs(g, v);
}


void find_connected_component(matGraph *g)
{
	int i;
	int count = 0;

	visitedInit();

	for (i = 0; i < g->n; i++)
	{
		if (!visited[i])
		{
			count++;
			matGraph_dfs(g, i);
		}
	}
}
void print_visited()
{
	const int row = 10;
	const int col = 5;
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
			printf("v[%2d]=%d ", i*j, visited[j]);
		printf("\n");
	}
}

void set_init(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		parent[i] = -1;
		num[i] = 1;
	}
}
int set_find(int vertex)
{
	int p, s, i = -1;
	for (i = vertex; (p = parent[i]) >= 0; i = p);
	s = i;
	for (i = vertex; (p = parent[i]) >= 0; i = p)
		parent[i] = s;
	return s;
}
void set_union(int s1, int s2)
{
	if (num[s1] < num[s2])
	{
		parent[s1] = s2;
		num[s2] += num[s1];
	}
	else
	{
		parent[s2] = s1;
		num[s1] += num[s2];
	}
}

Kruskal_Element KruskalHeap_makeItem(int key)
{
	Kruskal_Element item;
	item.key = key;
	return item;
}
void KruskalHeap_init(Kruskal_GraphHeap *h)
{
	h->heap_size = 0;
}
int KruskalHeap_isEmpty(Kruskal_GraphHeap *h)
{
	if (h->heap_size == 0)
		return TRUE;
	else
		return FALSE;
}
void KruskalHeap_insert_min_heap(Kruskal_GraphHeap *h, Kruskal_Element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) // 차이점 1 (max는 > )
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
Kruskal_Element KruskalHeap_delete_min_heap(Kruskal_GraphHeap *h)
{
	int parent, child;
	Kruskal_Element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) &&
			(h->heap[child].key > h->heap[child + 1].key)) // 차이점 2 (max는 <)
			child++;
		if (temp.key <= h->heap[child].key) break; // 차이점 3(max는 >=)
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void insert_heap_edge(Kruskal_GraphHeap *h, int u, int v, int weight)
{
	Kruskal_Element e;
	e.u = u;
	e.v = v;
	e.key = weight;
	KruskalHeap_insert_min_heap(h, e);
}
void insert_all_edges(Kruskal_GraphHeap *h, matGraph *target)
{
	int i, j;
	for (i = 0; i < target->n; i++)
		for (j = 0; j < target->n; j++)
		{
			if(target->adj_mat[i][j] != 0)
				insert_heap_edge(h, i, j, target->adj_mat[i][j]);
		}
}
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == INT_MAX)
			printf("MAX ");
		else if (arr[i] == INT_MAX / 4)
			printf("INF ");
		else
			printf("%3d ", arr[i]);
	}
	printf("\n");
}
void kruskal(matGraph *target)
{
	int edge_accepted = 0;
	int n = target->n;
	Kruskal_GraphHeap h;
	int uset, vset;
	Kruskal_Element e;

	KruskalHeap_init(&h);
	insert_all_edges(&h, target);
	set_init(n);
	printf("\n");
	while (edge_accepted < (n - 1))
	{
		e = KruskalHeap_delete_min_heap(&h);
		uset = set_find(e.u);
		vset = set_find(e.v);
		printf("parent: ");
		printArray(parent, target->n);
		printf("num   : ");
		printArray(num, target->n);
		if (uset != vset)
		{
			printf("(%d,%d) %d \n", e.u, e.v, e.key);
			edge_accepted++;
			set_union(uset, vset);
		}
	}
}
int get_min_vertex(int n)
{
	int v, i;
	for(i=0;i<n;i++)
		if (!selected[i])
		{
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (dist[i] < dist[v]))
			v = i;
	return (v);
}
void prim_getDist(int dist[], int size)
{
	int sum = 0;
	int i;
	printf("\n");
	for (i = 0; i < size; i++)/*
	{
		if (dist[i] == INT_MAX) continue;
		sum += dist[i];
	}
	printf("\n현재 거리 : %d\n", sum);*/
		printf("%d ", dist[i]);
	printf("\n");
}
void prim(matGraph *graph)
{
	int s = 0;
	int n = graph->n;
	int i, u, v;

	for (u = 0; u < n; u++)
	{
		dist[u] = INT_MAX;
		selected[u] = FALSE;
	}
	dist[s] = 0;
	for (i = 0; i < n; i++)
	{
		u = get_min_vertex(n);
		selected[u] = TRUE;
		if (dist[u] == INT_MAX) return;
		printf("%d-> ", u);
		for (v = 0; v < n; v++)
			if (graph->adj_mat[u][v] != INT_MAX)
				if (!selected[v] && graph->adj_mat[u][v] < dist[v])
				{
					
					dist[v] = graph->adj_mat[u][v];
					printf("dist: ");
					printArray(dist, graph->n);
				}// dist[0]은 정점 번호, 
//		prim_getDist(dist, n);
	}
}


int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i=0;i<n;i++)
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	return minpos;
}
void shortest_path(matGraph* graph, int start)
{
	int n = graph->n;
	int i, u, w;
	for (i = 0; i < n; i++)
	{
		distance[i] = graph->adj_mat[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;
	distance[start] = 0;
	printf("First:\n");
	printArray(distance, graph->n);
	printf("First:\n");
	for (i = 0; i < n - 1; i++)
	{
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + graph->adj_mat[u][w] < distance[w])
				{
					distance[w] = distance[u] + graph->adj_mat[u][w];
					printArray(distance, graph->n);
				}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d:%d\n", i, distance[i]);
	}
	printf("\n");
}


void print_adj(matGraph* graph)
{
	const int row = graph->n;
	const int col = graph->n;
	printf("\n");
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			if (graph->adj_mat[i][j] == INT_MAX / 4)
				printf("%4s", "-");
			else
				printf("%4d", graph->adj_mat[i][j]);
		}
		printf("\n");
	}
}
int A[MAX_VERTICES][MAX_VERTICES];
void floyd(matGraph* graph)
{
	int i, j, k;
	int n = graph->n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A[i][j] = graph->adj_mat[i][j]; // weight 복사
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%4d", A[i][j]);
		printf("\n");
	}
}

void topo_sort(listGraph *graph)
{
	int i;
	Stack s;
	GraphNode *node;

	int *in_degree = (int*)malloc(graph->n * sizeof(int));
	for (i = 0; i < graph->n; i++)
		in_degree[i] = 0;
	for (i = 0; i < graph->n; i++)
	{
		GraphNode *node = graph->adj_list[i];
		while (node != NULL)
		{
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	stack_init(&s);
	for (i = 0; i < graph->n; i++)
	{
		if (in_degree[i] == 0)
			stack_push(&s, i);
	}
	while (!stack_is_empty(&s))
	{
		int w;
		w = stack_pop(&s);
		printf("%d ", w);
		node = graph->adj_list[w];
		while (node != NULL)
		{
			int u = node->vertex;
			in_degree[u]--;
			if (in_degree[u] == 0)
				stack_push(&s, u);
			node = node->link;
		}
	}
	free(in_degree);
}
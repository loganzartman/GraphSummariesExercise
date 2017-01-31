#ifndef GRAPH_GUARD
#define GRAPH_GUARD

typedef struct ListStruct {
	int value;
	int *size;
	struct ListStruct *next;
} List;

typedef struct NodeStruct {
	int id;
	List *edges;
} Node;

typedef struct GraphStruct {
	int num_nodes;
	int scratch;
	struct NodeStruct *nodes;
} Graph;

Graph* graph_create(int num_nodes);
void graph_reset(Graph *graph);
void graph_connect(Graph *graph, int from, int to);
void graph_bfs(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depthLimit);
void graph_bfs_helper(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depth_limit, int depth, List *visited);

List* list_create();
int list_add(List *list, int value);
int list_contains(List *list, int value);
void list_destroy(List *list);

#endif
#ifndef GRAPH_GUARD
#define GRAPH_GUARD

typedef struct ListStruct {
	int value;
	struct ListStruct *next;
} List;

typedef struct NodeStruct {
	int id;
	List *edges;
} Node;

typedef struct GraphStruct {
	int num_nodes;
	int scratch;
	struct NodeStruct **nodes;
} Graph;

void graph_init(Graph *graph, int num_nodes);
void graph_reset(Graph *graph);
void graph_connect(Graph *graph, int from, int to);
void graph_bfs(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depthLimit);

List* list_create(int value);
int list_add(List *list, int value);
int list_contains(List *list, int value);

#endif
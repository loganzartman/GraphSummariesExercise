#ifndef GRAPH_GUARD
#define GRAPH_GUARD

typedef struct GraphStruct {
	int scratch;
	int *nodes;
	int **edges;
} Graph;

void graph_init(Graph *graph);
void graph_reset(Graph *graph);
void graph_connect(Graph *graph, int from, int to);
void graph_bfs(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depthLimit);

#endif
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

/**
 * Allocates and initializes a new graph.
 * Returns a pointer to the graph.
 * @param  num_nodes the number of nodes in this graph
 * @return           pointer to a new graph
 */
Graph* graph_create(int num_nodes);

/**
 * Resets scratch variables in a graph.
 * @param graph the graph to reset
 */
void graph_reset(Graph *graph);

/**
 * Creates a directed edge from one node to another.
 * @param graph the graph
 * @param from  start node
 * @param to    destination node
 */
void graph_connect(Graph *graph, int from, int to);

/**
 * Perform a breadth-first search of a graph, with optional depth limit.
 * Calls a callback function at each node.
 * @param graph      the graph
 * @param from       start node
 * @param searchFunc callback that is passed the graph and the current node
 * @param depthLimit maximum search depth
 */
void graph_bfs(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depthLimit);

/**
 * Recursive function called by graph_bfs
 */
void graph_bfs_helper(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depth_limit, int depth, List *visited);

/**
 * Frees resources associated with a graph.
 * @param graph the graph
 */
void graph_destroy(Graph *graph);

/**
 * Allocates and initializes a new List.
 * Returns a pointer to the list.
 */
List* list_create();

/**
 * Adds an element to a list.
 * Returns whether the add was successful.
 * @param list  the list
 * @param value the value to add
 */
int list_add(List *list, int value, int disallow_duplicates);

/**
 * Adds an element to a list, but aborts if the element is already present.
 * Returns whether the add was successful.
 * @param list  the list
 * @param value the value to add
 */
int set_add(List *list, int value);

/**
 * Determines whether a value is present in the List.
 * @param  list    the list
 * @param  value   the value to find
 * @return         whether the list contains the value
 */
int list_contains(List *list, int value);

/**
 * Frees resources associated with a List.
 * @param list the list
 */
void list_destroy(List *list);

/**
 * Prints a formatted representation of the List to standard out.
 * @param list the list
 */
void list_print(List *list);

#endif
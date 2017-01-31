#include <stdio.h>
#include "summaries.h"
#include "graph.h"

int main(int argc, char const *argv[]) {
	int cases;
	scanf("%d", &cases);

	List *test = list_create();
	list_add(test, 1);
	list_add(test, 3);
	printf("TEST: %d %d\n", list_contains(test, 1), list_contains(test, 2));

	//iterate over test cases
	for (int c=0; c<cases; c++) {
		//read test parameters
		int nodes, edges, start, dist;
		scanf("%d %d %d %d", &nodes, &edges, &start, &dist);

		Graph *graph = graph_create(nodes);

		//parse edges
		for (int e=0; e<edges; e++) {
			int from, to;
			scanf("%d %d", &from, &to);

			graph_connect(graph, from, to);
		}

		//count connected components
		graph_reset(graph);
		int cc = count_connected_components(graph);

		//do a breadth-first search of limited depth that just counts nodes
		graph_reset(graph);
		void (*searchFunc)(Graph *graph, int node);
		searchFunc = &count_reachable_helper;
		graph_bfs(graph, start, searchFunc, dist);
		int reachable = graph->scratch;

		//print results
		printf("%d %d\n", cc, reachable);
	}

	return 0;
}

void count_reachable_helper(Graph *graph, int node) {
	graph->scratch++;
}

List *found_nodes;
int count_connected_components(Graph *graph) {
	//reset found nodes
	list_destroy(found_nodes);
	found_nodes = list_create();

	//prep
	int num_nodes = graph->num_nodes;
	int components = 0;

	//a function pointer to use for BFS
	void (*searchFunc)(Graph *graph, int node);
	searchFunc = &count_connected_helper;

	while (*(found_nodes->size) < num_nodes) {
		for (int i=0; i<num_nodes; i++) {
			if (!list_contains(found_nodes, i)) {
				graph_bfs(graph, i, searchFunc, -1);
				components++;
			}
		}
	}

	return components;
}

void count_connected_helper(Graph *graph, int node) {
	list_add(found_nodes, node);
}
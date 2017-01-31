#include <stdio.h>
#include "summaries.h"
#include "graph.h"

int main(int argc, char const *argv[]) {
	int cases;
	scanf("%d", &cases);

	List *test = list_create(0);
	list_add(test, 1);
	list_add(test, 3);
	printf("TEST: %d %d\n", list_contains(test, 1), list_contains(test, 2));

	//iterate over test cases
	for (int c=0; c<cases; c++) {
		//read test parameters
		int nodes, edges, start, dist;
		scanf("%d %d %d %d", &nodes, &edges, &start, &dist);

		Graph graph;
		graph_init(&graph, nodes);

		//parse edges
		for (int e=0; e<edges; e++) {
			int from, to;
			scanf("%d %d", &from, &to);

			graph_connect(&graph, from, to);
		}

		//count connected components
		int cc = count_connected_components(&graph);

		//do a breadth-first search of limited depth that just counts nodes
		void (*searchFunc)(Graph *graph, int node);
		searchFunc = &count_reachable;
		graph_bfs(&graph, start, searchFunc, dist);
		int reachable = graph.scratch;

		//print results
		printf("Testing lol\n");
	}

	return 0;
}

void count_reachable(Graph *graph, int node) {
	//this is dumb but it could totally do something cooler
	graph->scratch++;
}

int count_connected_components(Graph *graph) {
	return 0;
}
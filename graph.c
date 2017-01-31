#include <stdlib.h>
#include "graph.h"

void graph_init(Graph *graph, int num_nodes) {
	graph->num_nodes = num_nodes;
	graph_reset(graph);
}

void graph_reset(Graph *graph) {
	graph->scratch = 0;
}

void graph_connect(Graph *graph, int from, int to) {

}

void graph_bfs(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depthLimit) {

}

List* list_create(int value) {
	List *list;
	list = malloc(sizeof(List));
	list->value = value; //shh is ok
	return list;
}

int list_add(List *list, int value) {
	while (list != NULL) {
		//value present case
		if (list->value == value)
			return 0;

		//not at end case
		if (list->next != NULL) {
			list = list->next;
			continue;
		}

		//add case
		List *next = list_create(value);
		list->next = next;
		return 1;
	}
	return 0;
}

int list_contains(List *list, int value) {
	while (list != NULL) {
		//value present case
		if (list->value == value)
			return 1;

		//not at end case
		if (list->next != NULL)
			list = list->next;
		else
			return 0;
	}
	return 0;
}
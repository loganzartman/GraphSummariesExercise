#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void graph_init(Graph *graph, int num_nodes) {
	graph->num_nodes = num_nodes;

	//initialize nodes
	graph->nodes = malloc(sizeof(Node) * num_nodes);
	for (int i=0; i<num_nodes; i++) {
		graph->nodes[i].id = i;
		graph->nodes[i].edges = list_create(); //shh is ok
	}

	graph_reset(graph);
}

void graph_reset(Graph *graph) {
	graph->scratch = 0;
}

void graph_connect(Graph *graph, int from, int to) {
	List *list = graph->nodes[from].edges;
	list_add(list, to);
}

void graph_bfs(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depthLimit) {

}

List* list_create() {
	//allocate space for a new list
	List *list;
	list = malloc(sizeof(List));

	//set its size to 0
	list->size = malloc(sizeof(int));
	*(list->size) = 0;

	//set its initial value
	list->value = 0;
	return list;
}

int list_add(List *list, int value) {
	while (list != NULL) {
		//list empty case
		if (*(list->size) == 0) {
			list->value = value;
			(*(list->size))++;
			return 1;
		}

		//value present case
		if (list->value == value)
			return 0;

		//not at end case
		if (list->next != NULL) {
			list = list->next;
			continue;
		}

		//add case
		List *next = list_create();
		next->value = value; //assign value
		next->size = list->size; //copy size pointer
		list->next = next; //assign this as the next element
		(*(list->size))++; //increment size value
		return 1;
	}
	return 0;
}

int list_contains(List *list, int value) {
	while (list != NULL) {
		//list empty case
		if (*(list->size) == 0)
			return 0;

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

void list_destroy(List *list) {
	while (list != NULL) {
		List *next = list->next;
		free(list);
		list = next;
	}
}
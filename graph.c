#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

Graph* graph_create(int num_nodes) {
	Graph *graph = calloc(sizeof(Graph), 1);
	graph->num_nodes = num_nodes;

	//initialize nodes
	graph->nodes = calloc(sizeof(Node), num_nodes);
	for (int i=0; i<num_nodes; i++) {
		graph->nodes[i].id = i;
		graph->nodes[i].edges = list_create();
	}

	graph_reset(graph);
	return graph;
}

void graph_reset(Graph *graph) {
	graph->scratch = 0;
}

void graph_connect(Graph *graph, int from, int to) {
	List *list = graph->nodes[from].edges;
	list_add(list, to);
}

void graph_bfs(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depth_limit) {
	List *visited = list_create();
	// list_add(visited, from);
	(*searchFunc)(graph, from);
	graph_bfs_helper(graph, from, searchFunc, depth_limit, 0, visited);
	list_destroy(visited);
}

void graph_bfs_helper(Graph *graph, int from, void (*searchFunc)(Graph *graph, int node), int depth_limit, int depth, List *visited) {
	if ((depth_limit >= 0 && depth > depth_limit) || list_contains(visited, from))
		return;
	list_add(visited, from);

	//iterate over edges and apply function
	List *edge = graph->nodes[from].edges;
	while (edge != NULL) {
		if (*(edge->size) == 0)
			break;
		(*searchFunc)(graph, edge->value);
		edge = edge->next;
	}

	//visit edges
	edge = graph->nodes[from].edges;
	while (edge != NULL) {
		if (*(edge->size) == 0)
			break;
		graph_bfs_helper(graph, edge->value, searchFunc, depth_limit, depth+1, visited);
		edge = edge->next;
	}
}

List* list_create() {
	//allocate space for a new list
	List *list;
	list = calloc(sizeof(List), 1);

	//set its size to 0
	list->size = calloc(sizeof(int), 1);
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

void list_print(List *list) {
	printf("[");
	while (list != NULL) {
		//list empty case
		if (*(list->size) == 0)
			break;

		printf("%d", list->value);

		//not at end case
		if (list->next != NULL) {
			list = list->next;
			printf(", ");
		}
		else
			break;
	}
	printf("]\n");
}

void list_destroy(List *list) {
	while (list != NULL) {
		List *next = list->next;
		free(list);
		list = next;
	}
}
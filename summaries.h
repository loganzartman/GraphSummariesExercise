#ifndef SUMMARIES_GUARD
#define SUMMARIES_GUARD

#include "graph.h"

int main(int argc, char const *argv[]);
void count_reachable_helper(Graph *graph, int node);
int count_connected_components(Graph *graph);
void count_connected_helper(Graph *graph, int node);

#endif
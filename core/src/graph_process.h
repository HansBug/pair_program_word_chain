//
// Created by admin on 2019/3/11.
//

#ifndef CORE_GRAPH_PROCESS_H
#define CORE_GRAPH_PROCESS_H

#include <climits>
#include <vector>

const int MAXN = 2010;
const int NO_EDGE = INT_MAX;


#define SUCCESS (0)
#define NO_PATH_ERROR (-1)
#define NODE_INDEX_EXCEED_ERROR (-2)

// clear graph data
int clear_graph();

// set edge weight
int set_edge(int u, int v, int weight);

// get edge weight
int get_edge(int u, int v, int &weight);

// check if has edge
bool has_edge(int u, int v);

// set undirected edge weight
int set_undirected_edge(int u, int v, int weight);

// floyd shortest path
int floyd(int n);

// get path from graph
int get_path_from_graph(int source, int target, std::vector<int> *&path);

// get dist from graph
int get_dist_from_graph(int source, int target, int &weight);

// check if has route in graph
bool has_route_in_graph(int source, int target);

#endif //CORE_GRAPH_PROCESS_H

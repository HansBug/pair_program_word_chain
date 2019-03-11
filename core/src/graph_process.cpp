//
// Created by admin on 2019/3/11.
//

#include "graph_process.h"
#include <cstring>
#include <iostream>

int graph[MAXN][MAXN];  // graph
int dist[MAXN][MAXN];  // distance
int route[MAXN][MAXN];  // route

// clear up dist graph
int clear_dist() {
    std::memset(dist, 0, sizeof(dist));
    std::memset(route, 0, sizeof(route));
    return SUCCESS;
}

// initialize dist graph
int init_dist(int n) {
    int ret = clear_dist();
    if (ret) {
        return ret;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
                route[i][j] = i;
            } else if (graph[i][j] == NO_EDGE) {
                dist[i][j] = NO_EDGE;
                route[i][j] = 0;
            } else {
                dist[i][j] = graph[i][j];
                route[i][j] = j;
            }
        }
    }
    return SUCCESS;
}

// clear graph data
int clear_graph() {
    std::memset(graph, 0, sizeof(graph));
    return SUCCESS;
}

// check the range of index
bool check_range(int index) {
    return index < MAXN && index > 0;
}

// set edge weight
int set_edge(int u, int v, int weight) {
    if (!check_range(u) || !check_range(v)) {
        return NODE_INDEX_EXCEED_ERROR;
    }
    graph[u][v] = weight;
    return SUCCESS;
}

// get edge weight
int get_edge(int u, int v, int &weight) {
    if (!check_range(u) || !check_range(v)) {
        return NODE_INDEX_EXCEED_ERROR;
    }
    weight = graph[u][v];
    return SUCCESS;
}

// check if has edge
bool has_edge(int u, int v) {
    int weight;
    int ret = get_edge(u, v, weight);
    return !ret && weight != NO_EDGE;
}

// set undirected edge weight
int set_undirected_edge(int u, int v, int weight) {
    if (!check_range(u) || !check_range(v)) {
        return NODE_INDEX_EXCEED_ERROR;
    }
    int ret;
    ret = set_edge(u, v, weight);
    if (!ret) {
        ret = set_edge(v, u, weight);
        return ret;
    } else {
        return ret;
    }
}

// floyd shortest path
int floyd(int n) {
    int ret = init_dist(n);
    if (ret) {
        return ret;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][k] == NO_EDGE) continue;
            for (int j = 1; j <= n; j++) {
                if (dist[k][j] == NO_EDGE) continue;
                if ((dist[i][j] == NO_EDGE) || (dist[i][j] > dist[i][k] + dist[k][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    route[i][j] = route[i][k];
                }
            }
        }
    }
    return SUCCESS;
}

// get path from graph
int get_path_from_graph(int source, int target, std::vector<int> *&path) {
    std::vector<int> result{source};
    int current = source;
    while (current != target) {
        int next = route[current][target];
        if (!next) {
            path = nullptr;
            return NO_PATH_ERROR;
        }
        result.insert(result.end(), next);
        current = next;
    }
    path = new std::vector<int>(result);
    return SUCCESS;
}

// get dist from graph
int get_dist_from_graph(int source, int target, int &weight) {
    if (!check_range(source) || !check_range(target)) {
        return NODE_INDEX_EXCEED_ERROR;
    }
    weight = dist[source][target];
    return SUCCESS;
}

// check if has route in graph
bool has_route_in_graph(int source, int target) {
    int weight;
    int ret = get_dist_from_graph(source, target, weight);
    return !ret && weight != NO_EDGE;
}
//
// Created by admin on 2019/3/11.
//

#ifndef CORE_GRAPH_PROCESS_H
#define CORE_GRAPH_PROCESS_H

#include <climits>
#include <vector>
#include <cstring>

const int NO_EDGE = INT_MAX;

template<int N>
class Graph {
private:
    int **graph;
    int **dist;
    int **route;

    // clear graph
    void clear_graph() {
        std::memset(graph, 0, sizeof(graph));
    }

    // clear distance
    void clear_dist() {
        memset(dist, 0, sizeof(dist));
        memset(route, 0, sizeof(route));
    }

    // initialize result
    void init_dist() {
        clear_dist();
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
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
    }

    // check if range is valid
    bool check_range(int index) {
        return index >= 1 && index <= N;
    }

public:
    // constructor
    Graph() {
        graph = new int *[N + 1];
        for (int i = 0; i <= N; i++) {
            graph[i] = new int[N + 1];
        }

        dist = new int *[N + 1];
        for (int i = 0; i <= N; i++) {
            dist[i] = new int[N + 1];
        }

        route = new int *[N + 1];
        for (int i = 0; i <= N; i++) {
            route[i] = new int[N + 1];
        }
        clear();
    }

    // destructor
    ~Graph() {
        for (int i = 0; i < N + 1; i++) {
            delete[] graph[i];
            delete[] dist[i];
            delete[] route[i];
        }
        delete[] graph;
        delete[] dist;
        delete[] route;
    }

    // clear all data
    void clear() {
        clear_graph();
        clear_dist();
    }

    // set edge
    bool set_edge_weight(int u, int v, int weight) {
        if (!check_range(u) || !check_range(v)) return false;
        graph[u][v] = weight;
        return true;
    }

    // set undirected edge
    bool set_undirected_edge_weight(int u, int v, int weight) {
        if (!check_range(u) || !check_range(v)) return false;
        set_edge_weight(u, v, weight);
        set_edge_weight(v, u, weight);
        return true;
    }

    // get edge's weight
    int get_edge_weight(int u, int v) {
        if (!check_range(u) || !check_range(v)) return NO_EDGE;
        return graph[u][v];
    }

    // calculate shortest path with floyd algorithm
    void floyd() {
        init_dist();
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                if (dist[i][k] == NO_EDGE) continue;
                for (int j = 1; j <= N; j++) {
                    if (dist[k][j] == NO_EDGE) continue;
                    if ((dist[i][j] == NO_EDGE) || (dist[i][j] > dist[i][k] + dist[k][j])) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        route[i][j] = route[i][k];
                    }
                }
            }
        }
    }

    // get distance from u to v
    int get_distance(int source, int target) {
        if (!check_range(source) || !check_range(target)) return NO_EDGE;
        return dist[source][target];
    }

    // get full route from u to v
    std::vector<int> get_route(int source, int target) {
        std::vector<int> result{source};
        int current = source;
        while (current != target) {
            int next = route[current][target];
            if (next == 0) {
                return std::vector<int>(); // no route found
            } else {
                result.insert(result.end(), next);
                current = next;
            }
        }
        return result;  // route found
    }
};

#endif //CORE_GRAPH_PROCESS_H

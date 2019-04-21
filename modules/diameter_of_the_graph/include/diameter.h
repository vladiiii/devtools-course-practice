// Copyright 2019 Korobeinikov Aleksey

#ifndef MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIAMETER_H_
#define MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIAMETER_H_

#include <vector>


class graph {
 private:
    std::vector<std::vector<int>> v;
    int n;  // count of vertex
    int **dist;
 public:
    ~graph();
    graph(const std::vector<std::vector<int>> &, int _n);
    graph(int *** dist, int _n);
    graph(const graph&);
    int diameter_of_tree(void);
    int diameter_of_graph(void);
    void print_dist();
 private:
    void floid(void);
    void bfs(int x);
};
#endif  // MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIAMETER_H_

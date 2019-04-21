// Copyright 2019 Korobeinikov Aleksey

#include <queue>
#include <iostream>
#include "include/diameter.h"

#define inf 1000000000

graph::graph(const std::vector<std::vector<int>>& vv, int _n) {
    n = _n;
    v = vv;
    dist = new int*[v.size()];
    n = v.size();
    for (int i = 0; i < n; ++i) {
        dist[i] = new int[n];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = -1;
}

graph::graph(int **&temp, int _n) {
    dist = temp;
    n = _n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] > 0 && dist[i][j] != INT_MAX) v[i].push_back(j);
        }
}

void graph::floid(void) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && ((dist[i][j] == 0) || (dist[i][j] == -1)))
                dist[i][j] = inf;
        }
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
}

void graph::bfs(int x) {
    std::queue <int> q;
    q.push(x);
    dist[x][x] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int y : v[t])
            if (dist[x][y] == -1) {
                q.push(y);
                dist[x][y] = dist[x][t] + 1;
            }
    }
}

void graph::print_dist() {
    // std::ostringstream cout;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << dist[i][j] << " ";
        std::cout << '\n';
    }
}

int graph::diameter_of_tree(void) {
    int v1 = 0;
    bfs(v1);
    int v2 = 0;
    for (int i = 0; i < n; ++i)
        if (dist[v1][i] > dist[v1][v2]) v2 = i;
    bfs(v2);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (dist[v2][i] > dist[v2][ans]) ans = i;
    print_dist();
    return dist[v2][ans];
}

int graph::diameter_of_graph(void) {
    floid();
    int ans = -2;
    print_dist();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            ans = std::max(ans, dist[i][j]);
        }
    return ans;
}

graph::graph(const graph& g) {
    n = g.n;
    v.resize(n);
    dist = new int*[n];
    for (int i = 0; i < n; ++i) dist[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) dist[i][j] = g.dist[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < g.v[i].size(); ++j) v[i].push_back(g.v[i][j]);
}

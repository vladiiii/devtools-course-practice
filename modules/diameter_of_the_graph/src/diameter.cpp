// Copyright 2019 Korobeinikov Aleksey

#include <queue>
#include <climits>
#include <algorithm>
#include <vector>
#include <iostream>

#include "include/diameter.h"

Graph::Graph(std::vector<std::vector<int>>&& vv, int _n) {
    count_ = _n;
    v_ = vv;
    dist_ = new int*[v_.size()];
    count_ = v_.size();
    for (int i = 0; i < count_; ++i) {
        dist_[i] = new int[count_];
    }
    for (int i = 0; i < count_; ++i)
        for (int j = 0; j < count_; ++j)
            dist_[i][j] = -1;
}

Graph::Graph() {
    count_ = 10;
    dist_ = new int*[count_];
    for (int i = 0; i < count_; ++i) {
        dist_[i] = new int[count_];
    }
    for (int i = 0; i < count_; ++i)
        for (int j = 0; j < count_; ++j)
            dist_[i][j] = 0;
    v_.resize(count_);
}

Graph::Graph(int ***temp, int _n) {
    dist_ = *temp;
    count_ = _n;
    v_.resize(count_);
    for (int i = 0; i < count_; ++i)
        for (int j = 0; j < count_; ++j) {
            if (dist_[i][j] > 0 && dist_[i][j] != INT_MAX) v_[i].push_back(j);
        }
}

Graph::~Graph() {
    for (int i = 0; i < count_; ++i) delete[] dist_[i];
    delete[] dist_;
}
void Graph::floid(void) {
    for (int i = 0; i < count_; ++i) {
        for (int j = 0; j < count_; ++j) {
            if (i != j && ((dist_[i][j] == 0) || (dist_[i][j] == -1)))
                dist_[i][j] = INT16_MAX;
        }
    }
    for (int k = 0; k < count_; ++k)
        for (int i = 0; i < count_; ++i)
            for (int j = 0; j < count_; ++j)
                dist_[i][j] = std::min(dist_[i][j], dist_[i][k] + dist_[k][j]);
}

void Graph::bfs(int x) {
    std::queue <int> q;
    q.push(x);
    dist_[x][x] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int y : v_[t])
            if (dist_[x][y] == -1) {
                q.push(y);
                dist_[x][y] = dist_[x][t] + 1;
            }
    }
}

void Graph::print_dist() {
    for (int i = 0; i < count_; ++i) {
        for (int j = 0; j < count_; ++j)
            std::cout << dist_[i][j] << " ";
        std::cout << '\n';
    }
}

int Graph::diameter_of_tree(void) {
    int v1 = 0;
    bfs(v1);
    int v2 = 0;
    for (int i = 0; i < count_; ++i)
        if (dist_[v1][i] > dist_[v1][v2]) v2 = i;
    bfs(v2);
    int ans = 0;
    for (int i = 0; i < count_; ++i)
        if (dist_[v2][i] > dist_[v2][ans]) ans = i;
    print_dist();
    return dist_[v2][ans];
}

int Graph::diameter_of_Graph(void) {
    floid();
    int ans = -2;
    print_dist();
    for (int i = 0; i < count_; ++i)
        for (int j = 0; j < count_; ++j) {
            ans = std::max(ans, dist_[i][j]);
        }
    return ans;
}

Graph::Graph(const Graph& g) {
    count_ = g.count_;
    v_.resize(count_);
    dist_ = new int*[count_];
    for (int i = 0; i < count_; ++i) dist_[i] = new int[count_];
    for (int i = 0; i < count_; ++i)
        for (int j = 0; j < count_; ++j) dist_[i][j] = g.dist_[i][j];
    for (int i = 0; i < count_; ++i)
        for (unsigned int j = 0; j < g.v_[i].size(); ++j)
            v_[i].push_back(g.v_[i][j]);
}

Graph& Graph::operator=(const Graph& g) {
    count_ = g.count_;
    for (int i = 0; i < count_; ++i)
        for (int j = 0; j < count_; ++j) dist_[i][j] = g.dist_[i][j];
    v_ = g.v_;
    return *this;
}

// Copyright 2019 Soluyanov Alexsey

#include <vector>

#include <iostream>

#ifndef MODULES_DHEAP_INCLUDE_DHEAP_H_
#define MODULES_DHEAP_INCLUDE_DHEAP_H_

class dHeap {
 private:
    int d;
    std::vector<int> weight;

    int Parent(int node);
    int Left_child(int node);
    int Min_child(int node);
    int Right_child(int node);
    void Swap(int child, int parent);
    void Diving(int node);
    void Emersion(int node);
    void Decrease_weight(int node, int w);
    void Make();

 public:
    explicit dHeap(int _d = 2);
    dHeap(int _d, std::vector<int> _w);
    void Insert(int w);
    void Delete(int node);
    void Delete_min();
    void print();
    int get_d();
    std::vector<int> get_weight();
    int get_parent(int i);
    int get_left_child(int i);
    int get_right_child(int i);
    int get_min_child(int i);
};

#endif  // MODULES_DHEAP_INCLUDE_DHEAP_H_

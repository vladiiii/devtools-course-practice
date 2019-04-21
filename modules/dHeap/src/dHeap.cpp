#include "include/dHeap.h"
#include <algorithm>


dHeap::dHeap(unsigned int _d) : d(_d) {
    weight = vector<int>();
}

dHeap::dHeap(unsigned int _d, vector<int> _w) : d(_d), weight(_w) {
    Make();
}

int dHeap::Parent(int node) {
    if (node % d == 0) {
        return (node / d) - 1;
    }
    return node / d;
}

int dHeap::Left_child(int node) {
    int leftch = node * d + 1;
    if (leftch > weight.size() - 1) {
        return -1;
    }
    return leftch;
}

int dHeap::Right_child(int node) {
    int leftch = Left_child(node);
    if (leftch == -1) {
        return -1;
    }
    return min(leftch + d - 1, weight.size() - 1);
}

int dHeap::Min_child(int node) {
    int leftch = Left_child(node);
    if (leftch == -1) {
        return -1;
    }
    int minch = leftch;
    int rightch = Right_child(node);
    for (int i = 0; i <= rightch - leftch; i++) {
        if (weight[minch + i] < weight[minch]) {
            minch = minch + i;
        }
    }
    return minch;
}

void dHeap::Swap(int child, int parent) {
    int temp = weight[child];
    weight[child] = weight[parent];
    weight[parent] = temp;
}

void dHeap::Diving(int node) {
    int parent = node;
    int minch = Min_child(node);
    while (minch != -1 && weight[parent] > weight[minch]) {
        Swap(minch, parent);
        parent = minch;
        minch = Min_child(parent);
    }
}

void dHeap::Emersion(int node) {
    int child = node;
    int prnt = Parent(node);
    while (prnt != -1 && weight[child] < weight[prnt]) {
        Swap(child, prnt);
        child = prnt;
        prnt = Parent(child);
    }
}

void dHeap::Insert(int w) {
    weight.push_back(w);
    Emersion(weight.size() - 1);
}

void dHeap::Delete_min() {
    Swap(0, weight.size());
    weight.pop_back();
    Diving(0);
}

void dHeap::Delete(int node) {
    Decrease_weight(node, INT16_MAX);
    Delete_min();
}

void dHeap::Decrease_weight(int node, int w) {
    weight[node] -= w;
    Emersion(node);
}

void dHeap::Make() {
    for (int i = weight.size() - 1; i >= 0; i--) {
        Diving(i);
    }
}

void dHeap::print() {
    for (int i = 0; i < weight.size(); i++) {
        cout << weight[i] << " ";
    }
    cout << endl;
}

int dHeap::get_d() {
    return d;
}

vector<int> dHeap::get_weight() {
    return weight;
}

int dHeap::get_left_child(int i) {
    return Left_child(i);
}

int dHeap::get_right_child(int i) {
    return Right_child(i);
}

int dHeap::get_parent(int i) {
    return Parent(i);
}

int dHeap::get_min_child(int i) {
    return Min_child(i);
}
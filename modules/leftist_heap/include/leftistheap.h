// Copyright 2019 Koroleva Daria

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_LEFTISTHEAP_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_LEFTISTHEAP_H_

#include <iostream>

using TDatType = int;

class Node {
    TDatType value;
    Node* left;
    Node* right;
    int dist;

    Node(TDatType _value, Node* _left = nullptr,
        Node* _right = nullptr, int _dist = 0):
        value(_value), left(_left), right(_right), dist(_dist) {}
    friend class LeftistHeap;
};

class LeftistHeap {
 private:
    Node* root;
 public:
    LeftistHeap() :root(nullptr) {}
    ~LeftistHeap();
    bool IsEmpty();
    void Insert(TDatType _value);
    void Merge(LeftistHeap* lh);
    TDatType& FindMin();
    void DeleteMin();
 private:
    void DeleteNode(Node* _node);
    Node* MergeLeft(Node* h1, Node* h2);
    Node* Merge(Node* h1, Node* h2);
    void SwapChildren(Node * t);
};

#endif  // MODULES_LEFTIST_HEAP_INCLUDE_LEFTISTHEAP_H_

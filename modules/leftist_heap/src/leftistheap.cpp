// Copyright 2019 Daria Koroleva
#include "include/leftistheap.h"

LeftistHeap::~LeftistHeap() {
    DeleteNode(this->root);
}

void LeftistHeap::DeleteNode(Node* _node) {
    if (_node != nullptr) {
        DeleteNode(_node->left);
        DeleteNode(_node->right);
        delete _node;
        _node = nullptr;
    }
}

bool LeftistHeap::IsEmpty() {
    return root == NULL;
}

void LeftistHeap::Insert(TDatType _value) {
    root = Merge(new Node(_value), root);
}

TDatType& LeftistHeap::FindMin() {
    return root->value;
}

void LeftistHeap::DeleteMin() {
    Node* oldroot = root;
    root = Merge(root->left, root->right);
    delete oldroot;
}

void LeftistHeap::Merge(LeftistHeap* lh) {
    if (this == lh)
        return;
    root = Merge(root, lh->root);
    lh->root = NULL;
}

Node* LeftistHeap::Merge(Node* n1, Node* n2) {
    if (n1 == NULL)
        return n2;
    if (n2 == NULL)
        return n1;
    if (n1->value < n2->value)
        return MergeLeft(n1, n2);
    else
        return MergeLeft(n2, n1);
}

Node* LeftistHeap::MergeLeft(Node* n1, Node* n2) {
    if (n1->left == NULL) {
        n1->left = n2;
    } else {
        n1->right = Merge(n1->right, n2);
        if (n1->left->dist < n1->right->dist) {
            SwapChildren(n1);
        }
        n1->dist = n1->right->dist + 1;
    }
    return n1;
}

void LeftistHeap::SwapChildren(Node* t) {
    Node* tmp = t->left;
    t->left = t->right;
    t->right = tmp;
}

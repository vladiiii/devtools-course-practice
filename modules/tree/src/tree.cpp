//Copyright 2019 Konnov Sergey

#include "tree.h"


Tree::Node::Node() {
    data = 0;
    left = right = nullptr;
}

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    DelAll(root);
}

void Tree::Add(int data) {
    root = AddNode(root, data);
}

void Tree::Del(int data) {
    DelNode(root, data);
}

int Tree::Search(int data) {
    return SearchNode(root, data);
}

void Tree::Clear() {
    DelAll(root);
}

Tree::Node* Tree::AddNode(Node * root, int data) {
    if(root == nullptr) {
        root = new Node;
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if(root->data > data)
        root->left = AddNode(root->left, data);
    else if(root->data < data)
        root->right = AddNode(root->right, data);
    else
        root->count++;
    return root;
}

Tree::Node* Tree::DelNode(Node* root, int data) {
    Node *p, *v;
    if(root == nullptr)
        return nullptr;
    if(data < root->data)
        root->left = DelNode(root->left, data);
    else if(data > root->data)
        root->right = DelNode(root->right, data);
    else {
        p = root;
        if(root->right == nullptr)
            root = root->left;
        else if(root->left == nullptr)
            root = root->right;
        else {
            v = root->left;
            if(v->right != nullptr) {
                while(v->right->right != nullptr)
                    v = v->right;
                root->data = v->right->data;
                root->count = v->right->count;
                p=v->right;
                v->right = v->right->left;
            }
            else {
                root->data = v->data;
                root->count = v->count;
                p = v;
                root->left = root->left->left;
            }
        }
        delete p;
    }
    return root;
}

int Tree::SearchNode(Node* node, int data) {
    if(root == nullptr)
        return false;
    else if(root->data > data)
        return SearchNode(root->left, data);
    else if(root->data < data)
        return SearchNode(root->right, data);
    else
        return root->count;
}

void Tree::DelAll(Node* root)
{
    if(root->left != nullptr)
        DelAll(root->left);
    if(root->right != nullptr)
        DelAll(root->right);
    delete root;
}

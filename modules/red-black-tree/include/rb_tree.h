// Copyright 2019 Timakin Nikita

#ifndef MODULES_RED_BLACK_TREE_INCLUDE_RB_TREE_H_
#define MODULES_RED_BLACK_TREE_INCLUDE_RB_TREE_H_

#include <vector>
#include <stack>

#include <iostream>

#define RED true
#define BLACK false

struct Node {
    int value;
    Node *left;
    Node *right;
    Node *parent;
    bool color;

    Node(int _value = 0, Node *_left = nullptr, Node *_right = nullptr,
         Node *_parent = nullptr, bool _color = BLACK);
    Node(const Node& node);

    Node& operator=(const Node& node);

    bool operator==(const Node& node);
    bool operator!=(const Node& node);

    friend std::ostream& operator<<(std::ostream& out, const Node& node);
};

class RBTree {
    Node *NIL;
    Node *root;
    Node *current;

    unsigned nodes_number;
    unsigned counter;

    std::stack<Node*> stack;

    void insert_fixup(Node *node);
    void transplant(Node *u, Node *v);
    void remove_fixup(Node *node);

    Node* minimum(Node * const node);

    void left_rotate(Node *x);
    void right_rotate(Node *x);

 public:
    RBTree();
    explicit RBTree(Node *node);
    explicit RBTree(const std::vector<int>& vec);

    RBTree(const RBTree& tree);  // Don't use! It added because of syntax errors

    Node* get_root() const;
    Node* get_current() const;

    bool find(const int value);
    void insert(Node *node);
    void remove(const int value);

    void begin();
    bool end() const;
    void next();
};

#endif  // MODULES_RED_BLACK_TREE_INCLUDE_RB_TREE_H_

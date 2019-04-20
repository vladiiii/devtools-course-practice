// Copyright 2019 Konnov Sergey

#ifndef MODULES_TREE_INCLUDE_TREE_H_
#define MODULES_TREE_INCLUDE_TREE_H_

class tree
{
private:
    struct Node
    {
        int data;
        Node* left, * right;
    }; // отдельная верщина дерева
    Node* root; //const? корень дерева
    Node* AddNode (Node*, int);
    Node* DelNode (Node*, int);
    int SearchNode(Node*, int);
public:
    tree();
    ~tree();
    void Add(int data); // добавить элемент
    void Del(int data); // убрать элемент
    int Search(int data); // поиск элемента
};
//все вершины справа - >=, слева - <

#endif

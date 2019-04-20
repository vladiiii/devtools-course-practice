// Copyright 2019 Konnov Sergey

#ifndef MODULES_TREE_INCLUDE_TREE_H_
#define MODULES_TREE_INCLUDE_TREE_H_

class Tree
{
private:
    struct Node
    {
        int data;
        int count;
        Node* left, * right;
        Node();
    }; // отдельная верщина дерева
    Node* root; // корень дерева
    Node* AddNode (Node*, int);
    Node* DelNode (Node*, int);
    int SearchNode(Node*, int);
    void DelAll(Node*);
public:
    Tree();
    ~Tree();
    void Add(int); // добавить элемент
    void Del(int); // убрать элемент
    int Search(int); // поиск элемента
    void Clear();
};


#endif

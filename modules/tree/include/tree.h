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
    Node* AddNode (Node*, int, int num = 1);
    Node* DelNode (Node*, int);
    Node* CopyNode(Node*, Node*);
    int SearchNode(Node*, int);
    void DelAll(Node*);
public:
    Tree(); // конструктор по умолчанию
    Tree(const Tree&); // конструктор копирования
    bool IsEmpty() const; // проверка, есть ли элементы в дереве
    ~Tree();
    void Add(int); // добавить элемент
    void Del(int); // убрать элемент
    int Search(int); // поиск элемента
    Tree& operator=(const Tree&); // оператор присваивания
    void Clear(); // очистить дерево
};


#endif

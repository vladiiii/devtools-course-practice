// Copyright 2019 Konnov Sergey

#ifndef MODULES_TREE_INCLUDE_TREE_H_
#define MODULES_TREE_INCLUDE_TREE_H_

class Tree {
 private:
    struct Node {
        int data;
        int count;
        Node* left, * right;
        Node();
    };  // отдельная верщина дерева
    Node* root;  // корень дерева
    Node* AddNode(Node* node, int data, int count = 1);
    Node* DelNode(Node* node, int data);
    Node* CopyNode(Node* node, Node* copyroot);
    int SearchNode(Node* node, int data);
    void DelAll(Node* node);
 public:
    Tree();  // конструктор по умолчанию
    Tree(const Tree& t);  // конструктор копирования
    bool IsEmpty() const;  // проверка, есть ли элементы в дереве
    ~Tree();
    void Add(int data);  // добавить элемент
    void Del(int data);  // убрать элемент
    int Search(int data);  // поиск элемента
    Tree& operator=(const Tree& t); // оператор присваивания
    void Clear();  // очистить дерево
};


#endif  // MODULES_TREE_INCLUDE_TREE_H_

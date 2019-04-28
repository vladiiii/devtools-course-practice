// Copyright 2019 Ivan Blagin

#ifndef MODULES_DICTIONARY_INCLUDE_DICTIONARY_H_
#define MODULES_DICTIONARY_INCLUDE_DICTIONARY_H_

#include <string>
using std::string;
using std::pair;
using Word = pair<string, int64_t>;

static string pool = 
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789";

char GetRandomChar();
string GetRandomString(int sizeWord);

struct Node {
    Word data_;
    Node* left_;
    Node* right_;
    int height_;
};
class Dictionary {
 private:
    Node* Insert(const Word& x, Node* t);
    Node* SingleRightRotate(Node* t);
    Node* SingleLeftRotate(Node* t);
    Node* DoubleLeftRotate(Node* t);
    Node* DoubleRightRotate(Node* t);
    Node* FindMin(Node* t);
    Node* Remove(const Word& x, Node* t);
    int Height(Node* t);
    Node* root_;
 public:
    Dictionary();
    Word Find(const string& x);
    void Insert(const Word& x);
    void Remove(const Word& x);
    Word GetRoot() const;
};

#endif  // MODULES_DICTIONARY_INCLUDE_DICTIONARY_H_

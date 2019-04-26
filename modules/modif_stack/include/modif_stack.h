// Copyright 2019 Karasev Anton

#ifndef MODULES_MODIF_STACK_INCLUDE_MODIF_STACK_H_
#define MODULES_MODIF_STACK_INCLUDE_MODIF_STACK_H_

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <utility>

class ModifStack {
 private:
    std::vector<std::pair<int, int>> stack_;

 public:
    explicit ModifStack(std::vector<int> temp);
    ModifStack(const ModifStack &src) = default;
    ~ModifStack() = default;

    bool Empty();
    int Size();

    std::pair<int, int> Top();
    void Push(int number);
    void Pop();
    std::vector<std::pair<int, int>> ShowReverseStack();
};

#endif  // MODULES_MODIF_STACK_INCLUDE_MODIF_STACK_H_

// Copyright 2019 Karasev Anton

#include "include/modif_stack.h"

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

ModifStack::ModifStack(std::vector<int> temp) {
    if (temp.size() != 0) {
        int size_temp = temp.size();
        std::pair<int, int> tmp = std::make_pair(temp[0], temp[0]);
        this->stack_.push_back(tmp);

        for (int i = 1; i < size_temp; i++) {
            tmp = std::make_pair(temp[i], temp[i]);
            if (temp[i] > this->stack_[i-1].second) {
               tmp.second = this->stack_[i-1].second;
            }
            this->stack_.push_back(tmp);
        }
     }
}

bool ModifStack::Empty() {
     return this->stack_.empty();
}


int ModifStack::Size() {
    return this->stack_.size();
}


std::pair<int, int> ModifStack::Top() {
    std::pair<int, int> res = std::make_pair(-1, 0);

    if (this->Size() != 0) {
        res = this->stack_.back();
    }
    return res;
}


void ModifStack::Push(int number) {
    std::pair<int, int> res = std::make_pair(number, number);
    res.second = std::min(number, this->Top().second);
    this->stack_.push_back(res);
}


void ModifStack::Pop() {
    if (this->Size() != 0) {
         this->stack_.pop_back();
    }
}


std::vector<std::pair<int, int>> ModifStack::ShowReverseStack() {
    std::vector<std::pair<int, int>> res(this->stack_);

    std::reverse(res.begin(), res.end());

    return res;
}

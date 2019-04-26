// Copyright 2019 Kruglov Yegor

#pragma once
#include <stack>
#include <string>

#ifndef MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_
#define MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_

class StringCalculator{
 private:
    std::string infix, postfix;
    std::stack<char> charStack;
    std::stack<double> doubleStack;

 public:
    void set_infix(const std::string str);
    void set_postfix(const std::string str);
    void fill_stacks(int n);
    std::string get_infix();
    std::string get_postfix();

    bool check();
    int priority(const char& el);
    void to_postfix();
    double calculate();
};

#endif  // MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_

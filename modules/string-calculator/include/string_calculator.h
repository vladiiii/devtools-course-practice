// Copyright 2019 Kruglov Yegor

#pragma once
#include <stack>
#include <string>

#ifndef MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_
#define MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_

using namespace std;

class StringCalculator 
{
private:

    string infix, postfix;
    stack<char> charStack;
    stack<double> doubleStack;

public:
    void set_infix(const string str);
    string get_infix();
    string get_postfix();

    bool check();
    int priority(const char& el);
    void to_postfix();
    double calculate();
};

#endif // MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_

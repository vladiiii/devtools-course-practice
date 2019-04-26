// Copyright 2019 Kruglov Yegor

#include "include/string_calculator.h"

#include <iostream>
#include <math.h>

using namespace std;

void StringCalculator::set_infix(const string str)
{
    infix = str;
}

string StringCalculator::get_infix()
{
    return infix;
}

string StringCalculator::get_postfix()
{
    return postfix;
}

bool StringCalculator::check()
{
    while (!charStack.empty())
    {
        charStack.pop();
    }
    int sizeOfInfix = static_cast<int>(infix.size());
    for (int i = 0; i < sizeOfInfix; i++)
    {
        switch (infix[i])
        {
            case '(':
            {
                charStack.push(infix[i]);
                break;
            }
            case ')':
            {
                if (charStack.empty())
                    return false;
                else
                {
                    charStack.pop();
                    break;
                }
            }
            case '+':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix[i - 1] == '-' || infix[i - 1] == '+' || infix[i - 1] == '*' ||
                    infix[i - 1] == '/' || infix[i - 1] == '^')
                    return false;
                break;
            }
            case '-':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix[i - 1] == '-' || infix[i - 1] == '+' || infix[i - 1] == '*' ||
                    infix[i - 1] == '/' || infix[i - 1] == '^')
                    return false;
                break;
            }
            case '*':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix[i - 1] == '-' || infix[i - 1] == '+' || infix[i - 1] == '*' ||
                    infix[i - 1] == '/' || infix[i - 1] == '^')
                    return false;
                break;
            }
            case '/':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix[i - 1] == '-' || infix[i - 1] == '+' || infix[i - 1] == '*' ||
                    infix[i - 1] == '/' || infix[i - 1] == '^')
                    return false;
                break;
            }
            case '^':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix[i - 1] == '-' || infix[i - 1] == '+' || infix[i - 1] == '*' ||
                    infix[i - 1] == '/' || infix[i - 1] == '^')
                    return false;
                break;
            }
        }
    }
    if (charStack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int StringCalculator::priority(const char& el)
{
    switch (el)
    {
        case '(':
        {
            return 0;
        }
        case '+':
        {
            return 1;
        }
        case '-':
        {
            return 1;
        }
        case '*':
        {
            return 2;
        }
        case '/':
        {
            return 2;
        }
        case '^':
        {
            return 3;
        }
    }
    return -1;
}

void StringCalculator::to_postfix()
{
    if (check())
    {
        while (!charStack.empty())
        {
            charStack.pop();
        }
        postfix.clear();

        string tmp = '(' + infix + ')';
        int sizeOfTmp = static_cast<int>(tmp.size());
        for (int i = 0; i < sizeOfTmp; i++)
        {
            if (tmp[i] == '(')
            {
                charStack.push(tmp[i]);
            }
            if ((tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] == '.'))
            {
                postfix += tmp[i];
            }
            if (tmp[i] == ')')
            {
                char el = charStack.top();
                charStack.pop();
                while (el != '(')
                {
                    postfix += el;
                    el = charStack.top();
                    charStack.pop();
                }
            }
            if ((tmp[i] == '+') || (tmp[i] == '-') || (tmp[i] == '*') || 
                (tmp[i] == '/') || (tmp[i] == '^'))
            {
                postfix += " ";
                while (priority(tmp[i]) <= priority(charStack.top()))
                {
                    postfix += charStack.top();
                    charStack.pop();
                }
                charStack.push(tmp[i]);
            }
        }
    }
    else
    {
        throw string("Incorrect data");
    }
}

double StringCalculator::calculate()
{
    while (!doubleStack.empty())
    {
        doubleStack.pop();
    }
    int sizeOfPostfix = static_cast<int>(postfix.size());
    for (int i = 0; i < sizeOfPostfix; i++)
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || 
            postfix[i] == '/' || postfix[i] == '^')
        {
            double res, op1, op2 = doubleStack.top();
            doubleStack.pop();
            if (doubleStack.empty()) 
            {
                throw string("Error - Incorrect Data");
            }
            op1 = doubleStack.top();
            doubleStack.pop();
            switch (postfix[i])
            {
                case '+':
                {
                    res = op1 + op2;
                    break;
                }
                case '-':
                {
                    res = op1 - op2;
                    break;
                }
                case '*':
                {
                    res = op1 * op2;
                    break;
                }
                case '/':
                {
                    if(op2 == 0)
                    {
                        throw string("Error - division by zero");
                    }
                    res = op1 / op2;
                    break;
                }
                case '^':
                {
                    res = pow(op1, op2);
                    break;
                }
            }
            doubleStack.push(res);
        }
        if ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.')
        {
            char *tmp;
            double res;
            res = strtod(&postfix[i], &tmp);
            int j = tmp - &postfix[i];
            i += j - 1;
            doubleStack.push(res);
        }
    }
    return doubleStack.top();
}

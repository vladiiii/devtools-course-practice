// Copyright 2019 Malkin Danil

#include "include\polynoms_calculator.h"
#include "include\polynom.h"

#include <regex>
#include <iostream>

std::string PolynomsCalculator::Info() {
    std::string res = "Please,enter the expression in the following format: \"*first polynom* *second polynom* *operation*\".\n";
    res+= "Available operations: +,-,*.\n";
    return res;
};

Monom PolynomsCalculator::createMonom(std::string& str) {
    double coeff = 1;
    std::map<char, double> vars;
    std::size_t res = 0;
    std::size_t curr = res;

    while ((isdigit(str[curr]) || str[curr] == '-' || str[curr] == '+' || str[curr] == '.') && (curr < str.length())) {
        curr++;
    }
    if (curr > 0) {
        coeff = std::stod(str.substr(res, curr));
    }
    str.erase(res, curr);
    res = str.find('^');;
    curr = res;
    while (res != std::string::npos) {
        curr++;
        if (isdigit(str[curr]) || str[curr] == '-' || str[curr] == '+') {
            while (isdigit(str[curr])) {
                curr++;
            }
            vars.insert({ str[res - 1],std::stod(str.substr(res + 1, curr - (res + 1))) });
            str.erase(res, curr - res);
            res = str.find('^');
            curr = res;
        }
    }
    return Monom(coeff, vars);
}

bool PolynomsCalculator::checkCorrectPolynoms(std::string& str) {
    const std::regex reg_str("([+,-]?(([0-9]+.[0-9]+)?([a-z]\\^-?[0-9]+|[a-z])+|([0-9]+.[0-9]+)?))+");
    return std::regex_match(str, reg_str);
};

bool PolynomsCalculator::checkOperation(std::string& str) {
    if (str == "+" || str == "-" || str == "*") {
        return true;
    }
    return false;
};

std::vector<Monom> PolynomsCalculator::parsePolynom( const std::string& str) {

    std::vector<Monom> resm;
    std::string str1 = str.substr(0, str.length());
    std::size_t res = 0;
    std::size_t curr = res;

    while (curr != str1.length()) {
        if ((str1[curr] == '-' || str1[curr] == '+') && (isalpha(str1[curr - 1]) || isdigit(str1[curr - 1]))) {
            resm.push_back(createMonom(str1.substr(res, curr - res)));
            res = curr;
        }
        curr++;
    }
    resm.push_back(createMonom(str1.substr(res, str1.length() - res)));
    return resm;
};

std::string PolynomsCalculator::preprocessing(std::string& str) {
    std::string str1 = str.substr(0, str.length());

    for (int i = 0; i < str1.length() - 1; i++) {
        if (isalpha(str1[i]) && (isalpha(str1[i + 1]) || str1[i + 1] == '+' || str1[i + 1] == '-')) {
            str1.insert(i+1, "^1");
        }
    }
    if (isalpha(str1[str1.length() - 1])) {
        str1+="^1";
    }
    return str1;
};

std::string PolynomsCalculator::calculate(std::string& arg1, std::string& arg2, std::string& operation) {
    Polynom pol1(parsePolynom(preprocessing(arg1)));
    Polynom pol2(parsePolynom(preprocessing(arg2)));
    std::string op = operation;

    if (op == "+") {
        return (pol1 + pol2).ToString();
    }
    if (op == "-") {
        return (pol1 - pol2).ToString();
    }
    if (op == "*") {
        return (pol1 * pol2).ToString();
    }
    return "";
}

std::string PolynomsCalculator::operator()(int argc, const char** argv) {
    Arguments arg;
    Polynom pol1;
    Polynom pol2;

    std::cout<<Info();
    arg.arg1 = argv[0];
    arg.arg2 = argv[1];
    arg.operation = argv[2];
   
    if (checkCorrectPolynoms(arg.arg1) && checkCorrectPolynoms(arg.arg2) && checkOperation(arg.operation)) {
        return calculate(arg.arg1, arg.arg2, arg.operation);
    }else {
        return "Incorrect input.";
    }
};


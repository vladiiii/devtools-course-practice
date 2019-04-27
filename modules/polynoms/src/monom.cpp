// Copyright 2019 Malkin Danil

#include <sstream>
#include <set>
#include <cmath>
#include <string>
#include <map>

#include "include/monom.h"

using std::set;
using std::stringstream;
using std::map;

Monom::Monom() : coefficient(1.0) {
}

Monom::Monom(double c) : coefficient(c) {
}

Monom::Monom(const Monom & rhs) :
    variables(rhs.variables),
    coefficient(rhs.coefficient) {
}

Monom::Monom(double c, map<char, double> vars) : variables(vars),
coefficient(c) {
}

Monom & Monom::operator=(const Monom & z) {
    variables = z.variables;
    coefficient = z.coefficient;
    return *this;
}

string Monom::ToString() {
    stringstream ss;
    ss << coefficient;
    for (auto& v : variables) {
        if (v.second != 0.0) {
            ss << v.first;
            ss << '^';
            ss << v.second;
        }
    }
    return ss.str();
}

bool Monom::operator==(const Monom & rhs) const {
    if (std::abs(coefficient - rhs.coefficient) != 0) return false;
    return EqualsVariabels(rhs);
}

bool Monom::operator!=(const Monom & rhs) const {
    return !(*this == rhs);
}

Monom Monom::operator+(const Monom & rhs) {
    Monom tmp(*this);
    if (EqualsVariabels(rhs)) {
        tmp.coefficient += rhs.coefficient;
    }
    return tmp;
}

Monom Monom::operator-(const Monom & rhs) {
    Monom tmp(*this);
    if (EqualsVariabels(rhs)) {
        tmp.coefficient -= rhs.coefficient;
    }
    return tmp;
}

Monom Monom::operator*(const Monom & rhs) {
    Monom ret(*this);
    ret.coefficient *= rhs.coefficient;
    for (auto& var : rhs.variables) {
        auto rv = ret.variables.find(var.first);
        if (rv == ret.variables.end()) {
            ret.variables.insert(var);
        } else {
            ret.variables[var.first] += var.second;
        }
    }
    return ret;
}

Monom Monom::operator/(const Monom & rhs) {
    if (rhs.coefficient == 0.0)
        throw string("Can't divide by zero");
    Monom ret(*this);
    ret.coefficient /= rhs.coefficient;
    for (auto& var : rhs.variables) {
        auto rv = ret.variables.find(var.first);
        if (rv == ret.variables.end()) {
            auto tmp = var;
            tmp.second *= -1;
            ret.variables.insert(tmp);
        } else {
            ret.variables[var.first] -= var.second;
            if (ret.variables[var.first] == 0.0) {
                auto it = ret.variables.find(var.first);
                ret.variables.erase(it);
            }
        }
    }
    return ret;
}

bool Monom::EqualsVariabels(const Monom& r) const {
    for (auto& var : variables) {
        auto rv = r.variables.find(var.first);
        if (rv == r.variables.end() || (*rv).second != var.second) {
            return false;
        }
    }
    return true;
}

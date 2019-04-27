// Copyright 2019 Malkin Danil

#include <string>
#include <sstream>
#include <cmath>
#include <set>
#include <vector>
#include <map>

#include "include/monom.h"
#include "include/polynom.h"

using std::stringstream;

Polynom::Polynom() : monoms() {
}

Polynom::Polynom(double coff) {
    if (coff != 0.0) monoms.emplace_back(Monom(coff));
}

Polynom::Polynom(const Polynom & rhs) : monoms(rhs.monoms) {
}
Polynom::Polynom(const vector<Monom> & buf) : monoms(buf) {
}
Polynom::Polynom(const Monom & buf) : monoms({ buf }) {
}

Polynom & Polynom::operator=(const Polynom & z) {
    monoms = z.monoms;
    return *this;
}

void Polynom::AddMonom(const Monom & m) {
    for (auto& mm : monoms) {
        if (mm.variables == m.variables) {
            mm.coefficient += m.coefficient;
            return;
        }
    }
    monoms.push_back(m);
}

string Polynom::ToString() {
    stringstream ss;
    for (size_t i = 0; i < monoms.size() - 1; ++i)
        ss << "(" << monoms[i].ToString() << ") + ";
    if (monoms.size() > 0)
        ss << "(" << monoms[monoms.size() - 1].ToString() << ")";
    return ss.str();
}

bool Polynom::operator==(const Polynom & rhs) const {
    if (monoms.size() != rhs.monoms.size())
        return false;
    for (size_t i = 0; i < monoms.size(); ++i) {
        bool cont = false;
        for (size_t j = 0; j < rhs.monoms.size(); j++)
            if (monoms[i] == rhs.monoms[j]) {
                cont = true;
                break;
            }
        if (!cont) return false;
    }
    return true;
}

bool Polynom::operator!=(const Polynom & rhs) const {
    return !(*this == rhs);
}

Polynom Polynom::operator+(const Polynom & rhs) {
    Polynom tmp(*this);
    for (size_t j = 0; j < rhs.monoms.size(); j++) {
        int ind = Contains(tmp.monoms, rhs.monoms[j]);
        if (ind > -1)
            tmp.monoms[ind] = (tmp.monoms[ind] + rhs.monoms[j]);
        else
            tmp.monoms.push_back(rhs.monoms[j]);
    }
    return tmp;
}

Polynom Polynom::operator-(const Polynom & rhs) {
    Polynom tmp(*this);
    for (size_t j = 0; j < rhs.monoms.size(); j++) {
        int ind = Contains(tmp.monoms, rhs.monoms[j]);
        if (ind > -1) {
            auto t = (tmp.monoms[ind] - rhs.monoms[j]);
            if (t.coefficient != 0.0)
                tmp.monoms[ind] = t;
            else
                tmp.monoms.erase(tmp.monoms.begin() + ind);
        } else {
            tmp.monoms.push_back(Monom(-1.0) * rhs.monoms[j]);
        }
    }
    return tmp;
}

Polynom Polynom::operator*(const Polynom & rhs) {
    Polynom tmp;
    for (size_t i = 0; i < monoms.size(); i++) {
        for (size_t j = 0; j < rhs.monoms.size(); j++) {
            Monom t = monoms[i] * rhs.monoms[j];
            if (t.coefficient != 0.0)
                tmp.monoms.emplace_back(t);
        }
    }
    return tmp;
}

Polynom Polynom::operator/(const Monom & m) {
    Polynom tmp;
    for (size_t i = 0; i < monoms.size(); i++) {
        Monom t = monoms[i] / m;
        if (!std::isnan(t.coefficient))
            tmp.monoms.emplace_back(t);
    }
    return tmp;
}

double Polynom::CalculateResult(const map<char, double>& in_params) {
    double res = 0.0;
    for (const auto& m : monoms) {
        double tmp = m.coefficient;
        for (const auto& in_var : in_params) {
            auto m_var = m.variables.find(in_var.first);
            if (m_var != m.variables.end()) {
                tmp *= std::pow(in_var.second, (*m_var).second);
            }
        }
        res += tmp;
    }
    return res;
}

int Polynom::Contains(const vector<Monom>& vec, const Monom & m) const {
    for (size_t i = 0; i < vec.size(); i++)
        if (vec[i].variables == m.variables) return i;
    return -1;
}

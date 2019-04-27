// Copyright 2019 Yakovlev Pavel

#include <cmath>

#include "include/numeric_integrate.h"

NumericIntegrate::NumericIntegrate() {
    a = 0.0;
    b = 1.0;
}

NumericIntegrate::NumericIntegrate(double _a, double _b) {
    if (_a < _b) {
        a = _a;
        b = _b;
    } else {
        b = _a;
        a = _b;
    }
}

double NumericIntegrate::functionValue(double x) const {
    double res = 0.0;
    if (x < 0) {
        res = -sqrt(-x);
    } else {
        res = sqrt(x);
    }
    return res;
}

void NumericIntegrate::Set_a(double _a) {
    if (_a <= b) {
        a = _a;
    } else {
        a = b;
        b = _a;
    }
}

void NumericIntegrate::Set_b(double _b) {
    if (_b >= a) {
        b = _b;
    } else {
        b = a;
        a = _b;
    }
}

void NumericIntegrate::Set_Section(double _a, double _b) {
    if (_a < _b) {
        a = _a;
        b = _b;
    } else {
        b = _a;
        a = _b;
    }
}

double NumericIntegrate::Get_a() const {
    return a;
}

double NumericIntegrate::Get_b() const {
    return b;
}

double NumericIntegrate::Rectangle_Method(int n) {
    double h = (b-a)/n;
    double res = 0.0;
    if (a == b) return 0.0;
    for (int i = 0; i < n; i++) {
        double middle = ((a+i*h)+(a+(i+1)*h))/2.0;
        res += functionValue(middle)*h;
    }
    return res;
}

double NumericIntegrate::Trapezium_Method(int n) {
    double h = (b-a)/n;
    double res = 0.0;
    if (a == b) return 0.0;

    for (int i = 0; i < n; i++) {
        res += (functionValue(a+i*h) + functionValue(a+(i+1)*h))*h/2.0;
    }
    return res;
}

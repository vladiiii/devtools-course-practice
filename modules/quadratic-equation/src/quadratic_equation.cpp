// Copyright 2019 Utkin Konstantin

#include "include/quadratic_equation.h"

#include <iostream>
#include <cmath>

double QuadraticEquation::Discriminant() const {
    return coef_b * coef_b - 4 * coef_a * coef_c;
}

QuadraticEquation::QuadraticEquation(double a, double b, double c):
    coef_a(a), coef_b(b), coef_c(c) {
    if (a == 0.0 && b == 0.0)
        throw "It is not a quadratic equation";
}

double QuadraticEquation::GetX1() const {
    double x;
    double d = Discriminant();

    if (d < 0.0)
        throw "No real solutions";

    if (coef_a == 0.0)
        x = -coef_c / coef_b;
    else
        x = (-coef_b + sqrt(d)) / (2 * coef_a);
    return x;
}

double QuadraticEquation::GetX2() const {
    double x;
    double d = Discriminant();

    if (d < 0.0)
        throw "No real solutions";

    if (coef_a == 0.0)
        x = -coef_c / coef_b;
    else
        x = (-coef_b - sqrt(d)) / (2 * coef_a);
    return x;
}

std::ostream& operator<<(std::ostream &out,
    const QuadraticEquation qe) {
    out << qe.coef_a << "*x^2 + " <<
        qe.coef_b << "*x + " << qe.coef_c <<
            " = 0" << std::endl;
    return out;
}

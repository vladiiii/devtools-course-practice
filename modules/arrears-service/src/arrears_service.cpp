// Copyright 2019 Sadikov Artem

#include "include/arrears_service.h"

#include <cmath>
#include <string>

ArrearService::ArrearService(const double d, const double e,
                             const int i, const int g, 
                             const int t) : debt(d), procent(i),
                             rate(g), time(t) {
    express = ExpressPay(t, i);
    yearpay = debt / Fond(i, t);
}

ArrearService::ArrearService(const ArrearService& obj) {
    debt = obj.debt;
    procent = obj.procent;
    express = obj.express;
    rate = obj.rate;
    time = obj.time;
}

double ArrearService::ExpressPay(int time, int proc) {
    if (proc <= 0)
        throw std::string("No procent for express");
    if (time <= 0)
        throw std::string("No time for express");

    double result;

    result = debt * (pow((1 + (double)rate * 0.01), time) / Fond(proc, time));

    return result;
}

double ArrearService::YearPayVal(int proc, int time, double prog) {
    if (proc <= 0)
        throw std::string("No procent for year pay");
    if (time <= 0)
        throw std::string("No time for year pay");
    if (prog == 0)
        throw std::string("No progression to calculate year pay");

    double result;
    double val1, val2;

    val1 = 1 / Fond(proc, time);
    val2 = (pow(1 + (double)proc * 0.01, time) - (1 + time * proc)) / pow(proc, 2);
    
    result = val1 * (debt - prog * val2);

    return result;
}

double ArrearService::Fond(int proc, int t) {
    if (proc <= 0)
        throw std::string("Invalid procent");
    if (time <= 0)
        throw std::string("Invalid time");
    
    double result;

    result = (pow(1 + (double)proc * 0.01, t) - 1) / ((double)proc * 0.01);

    return result;
}

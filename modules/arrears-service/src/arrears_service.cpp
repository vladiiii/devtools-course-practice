// Copyright 2019 Sadikov Artem

#include "include/arrears_service.h"

#define _USE_MATH_DEFINES_
#include <cmath>
#include <string>

ArrearService::ArrearService() : debt(0), rate(0), yearpay(0) {
    capital = nullptr;
}

ArrearService::ArrearService(const double d, const double r,
                             const double y, const int t) {
    debt = d;
    rate = r;
    yearpay = y;
    time = t;
    capital = new double[time];
    capital[0] = yearpay;

    for (int i = 1; i < time; i++)
        capital[i] = capital[i - 1] + yearpay;
}

ArrearService::ArrearService(const ArrearService& obj) {
    debt = obj.debt;
    rate = obj.rate;
    yearpay = obj.yearpay;
    time = obj.time;

    if (capital)
        delete capital;

    capital = new double[time];
    for (int i = 0; i < time; i++)
        capital[i] = obj.capital[i];
}

ArrearService::~ArrearService() {
    delete capital;
}

double ArrearService::ExpressPay(int time, int proc) {
    if (time == 0)
        throw std::string("No time for express");

    if (this->time < time)
        throw std::string("Invalid time");

    if (proc == 0)
        return 0.0;

    double express;

    yearpay = debt/(capital[time] * (proc / 100));

    express = debt * rate + yearpay;

    return express;
}

double ArrearService::YearPayVal(int proc, int time, double prog) {
    if (time == 0)
        throw std::string("No time for year pay");

    if (this->time < time)
        throw std::string("Invalid time");

    if (proc == 0)
        throw std::string("Invalid procent");

    double yearP = 0.0;
    double val1, val2, val3;

    val1 = 1.0 / capital[time];
    val2 = prog * pow((1 + proc / 100), time) - (1 + time  * (proc / 100));
    val3 = proc * proc;
    yearP = val1 * ((debt - val2) / val3);

    return yearP;
}

double ArrearService::SumYears(int proc, int time, double prog) {
    if (time == 0)
        throw std::string("No time to calculate sum");

    if (this->time < time)
        throw std::string("Invalid time");

    if (proc == 0)
        throw std::string("Invalid procent");

    double val1, val2, val3;
    double summer;

    val1 = yearpay * capital[time];
    val2 = prog * pow((1 + proc / 100), time) - (1 + time  * (proc / 100));
    val3 = proc * proc;
    summer = val1 + (val2 / val3);

    return summer;
}

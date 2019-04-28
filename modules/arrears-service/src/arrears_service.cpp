// Copyright 2019 Sadikov Artem

#include "include/arrears_service.h"

#include <cmath>
#include <iostream>
#include <string>

ArrearService::ArrearService(const double d, const int i, 
                             const int g, const int t) : debt(d), procent(i),
                             rate(g), time(t) {
    if (procent <= 0)
        throw std::string("Invalid procent");
    if (time <= 0)
        throw std::string("Invalid time");

    SetExpress();
    yearpay = debt / Fond();
}

ArrearService::ArrearService(const ArrearService& obj) {
    debt = obj.debt;
    procent = obj.procent;
    express = obj.express;
    rate = obj.rate;
    time = obj.time;
}

double ArrearService::ExpressPay() {
    return debt * (rate * 0.01) + debt / Fond();
}

double ArrearService::YearPayVal(double prog) {
    if (prog == 0)
        throw std::string("No progression to calculate year pay");

    double result;
    double val1, val2;

    val1 = 1.0 / Fond();
    val2 = (pow(1 + procent * 0.01, time) - (1 + time * (procent * 0.01))) / pow(procent * 0.01, 2);
    
    result = val1 * (debt - prog * val2);

    return result;
}

double ArrearService::Fond() {
    double result;

    result = (pow(1 + procent * 0.01, time) - 1) / (procent * 0.01);

    return result;
}

void ArrearService::SetYearPay(double prog) {
    yearpay = YearPayVal(prog);
}

void ArrearService::SetDebt(const double d) {
    debt = d;
}

void ArrearService::SetProcent(const int i) {
    procent = i;
}

void ArrearService::SetRate(const int g) {
    rate = g;
}

void ArrearService::SetTime(const int t) {
    time = t;
}

void ArrearService::SetExpress() {
    express = ExpressPay();
}

double ArrearService::GetExpress() {
    return express;
}

double ArrearService::GetDebt() {
    return debt;
}

double ArrearService::GetYearPay() {
    return yearpay;
}

int ArrearService::GetProcent() {
    return procent;
}

int ArrearService::GetTime() {
    return time;
}

int ArrearService::GetRate() {
    return rate;
}

// Copyright 2019 Kudrin Matvey

#include<vector>
#include<cmath>
#include<algorithm>

using std::vector;

struct bond {
    double price;
    double nominal_price;
    vector<int> months;
    int year;
    double percentage;
};

struct payment {
    double value;
    int month;
    int year;
};

#ifndef MODULES_BOND_CALCULATOR_INCLUDE_BOND_CALCULATOR_H_
#define MODULES_BOND_CALCULATOR_INCLUDE_BOND_CALCULATOR_H_


class bond_calculator {
 public:
    bond_calculator() = default;
    bond_calculator(bond_calculator&&) = default;

    vector<payment> CalculatePayments(const bond &paper, int current_month,
            int current_year);

    payment CalculateTotalIncome(const bond &paper, int current_month,
            int current_year);

    double CalculateYearlyInternalIncome(const bond paper, int current_year);
    double CalculateRelativeIncome(const bond &paper, int current_month,
            int current_year);
};

#endif  // MODULES_BOND_CALCULATOR_INCLUDE_BOND_CALCULATOR_H_

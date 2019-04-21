// Copyright 2019 Kudrin Matvey

#include <include/bond_calculator.h>
#include <vector>


vector<payment> bond_calculator::CalculatePayments(const bond &paper,
        int current_month, int current_year) {
    std::vector<payment> payments;
    int year = current_year;
    double coupon = paper.percentage / paper.months.size();
    if (paper.months.back() >= current_month) {
        int month = current_month;
        while (month < 12) {
            if (std::find(paper.months.begin(),
                    paper.months.end(), month) != paper.months.end()) {
                payments.push_back(payment{ coupon, month, year });
            }
            month++;
        }
    }
    year++;
    for (; year <= paper.year; year++) {
        for (unsigned int i = 0; i < paper.months.size(); i++) {
            payments.push_back(payment{ coupon, paper.months.at(i), year });
        }
    }
    payments.push_back(payment{paper.nominal_price, paper.months.back(), year});
    return payments;
}


payment bond_calculator::CalculateTotalIncome(const bond &paper,
        int current_month, int current_year) {
    payment total;
    total.value = 0;
    std::vector<payment> calculated_payment =
            CalculatePayments(paper, current_month, current_year);
    for (unsigned int i = 0; i < calculated_payment.size(); i++) {
        total.value += calculated_payment.at(i).value;
    }
    total.month = calculated_payment.back().month;
    total.year = calculated_payment.back().year;
    return total;
}


double bond_calculator::CalculateYearlyInternalIncome(bond paper,
        int current_year) {
    paper.year = current_year;

    std::vector<payment> calculated_payment =
            CalculatePayments(paper, 0, current_year);
    double internal_yearly_income = 0.0;
    for (unsigned int i = 0; i < paper.months.size(); i++) {
        internal_yearly_income += calculated_payment.at(i).value
                / pow((1 + paper.percentage), paper.months.at(i));
    }
    return internal_yearly_income;
}


double bond_calculator::CalculateRelativeIncome(const bond &paper,
        int current_month, int current_year) {
    payment total =
            CalculateTotalIncome(paper, current_month, current_year);
    return total.value - paper.price
    / (total.year - current_year + (total.month - current_month) / 12);
}

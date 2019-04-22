// Copyright 2019 Vorobev Pavel

#include <gtest/gtest.h>

#include "../mortgage-calculator/include/mortgagecalculator.h"

TEST(MortgageCalculatorTest, CanCalculatePayment) {
    MortgageCalculator calc;
    double payment = calc.CalculatePayments(10000, 0, 12, 10);

    EXPECT_EQ(879, static_cast<int>(payment));
}

TEST(MortgageCalculatorTest, CanCalculateOverpayment) {
    MortgageCalculator calc;
    double overpayment = calc.CalculateLoanOverpayment(1000, 12, 10000);

    EXPECT_EQ(2000, static_cast<int>(overpayment));
}

TEST(MortgageCalculatorTest, CanReturnMonthlyPayment) {
    MortgageCalculator calc;
    double payment = calc.GetCalculatedMonthlyPayment();

    EXPECT_EQ(0.0, payment);
}

TEST(MortgageCalculatorTest, CanReturnNotNullPayment) {
    MortgageCalculator calc;
    double payment = calc.CalculatePayments(1000, 100, 10, 15);

    EXPECT_EQ(calc.GetCalculatedMonthlyPayment(), payment);
}

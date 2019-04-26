// Copyright 2019 Ryabova Alyona

#ifndef MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_
#define MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_

class CalculatePrice {
 private:
    int basket_[5];
    double DiscountCalculate(const int book);

 public:
    CalculatePrice(int b1, int b2, int b3, int b4, int b5);

    double TotalSum();
};

#endif  // MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_

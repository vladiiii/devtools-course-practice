// Copyright 2017 Ryabova Alyona

#ifndef MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_
#define MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_

class CalculatePrice {
 private:
    int basket[5];
    double DiscountCalculate(const int book);

 public:
    CalculatePrice(int *b, int size);

    double TotalSum();
};

#endif  // MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_

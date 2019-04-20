// Copyright 2017 Ryabova Alyona

#ifndef MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_
#define MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_

class CalculatePrice {
 private:
    int basket[5];
    double discount_calculate(const int book);

 public:
    CalculatePrice(int *b, int size);

    double total_sum();
};

#endif  // MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_H_
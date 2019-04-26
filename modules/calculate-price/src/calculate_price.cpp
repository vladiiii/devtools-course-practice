// Copyright 2017 Ryabova Alyona

#include "include/calculate_price.h"

#include <stdio.h>
#include <string>

CalculatePrice::CalculatePrice(int b1, int b2, int b3, int b4, int b5) {
    if ((b1 < 0) || (b2 < 0) || (b3 < 0) || (b4 < 0) || (b5 < 0))
        throw std::string("Mustn't be contain negative numbers");
    basket[0] = b1;
    basket[1] = b2;
    basket[2] = b3;
    basket[3] = b4;
    basket[4] = b5;
}

double CalculatePrice::DiscountCalculate(const int book) {
    double sum = 0.0;

    switch (book) {
        case 1:
            sum = 8; break;
        case 2:
            sum = 15.2; break;
        case 3:
            sum = 21.6; break;
        case 4:
            sum = 25.6; break;
        case 5:
            sum = 30.0; break;
    }

    return sum;
}

double CalculatePrice::TotalSum() {
    double sum = 0.0;
    int shop_basket[5];

    for (int i = 0; i < 5; i++) {
        shop_basket[i] = basket[i];
    }

    int books = shop_basket[0] + shop_basket[1] +
        shop_basket[2] + shop_basket[3] + shop_basket[4];

    while (books) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (shop_basket[i]) {
            books--;
            shop_basket[i]--;
            count++;
        }
    }
    sum += DiscountCalculate(count);
    }

    return sum;
}

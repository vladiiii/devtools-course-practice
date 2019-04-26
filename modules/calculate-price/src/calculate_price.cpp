// Copyright 2019 Ryabova Alyona

#include "include/calculate_price.h"

#include <stdio.h>
#include <string>

CalculatePrice::CalculatePrice(int b1, int b2, int b3, int b4, int b5) {
    if ((b1 < 0) || (b2 < 0) || (b3 < 0) || (b4 < 0) || (b5 < 0))
        throw std::string("Mustn't be contain negative numbers");
    basket_[0] = b1;
    basket_[1] = b2;
    basket_[2] = b3;
    basket_[3] = b4;
    basket_[4] = b5;
}

double CalculatePrice::DiscountCalculate(const int book) {
    double sum = 0.0;
    double price = 8.0;

    switch (book) {
        case 1:
            sum = price; break;
        case 2:
            sum = price * 2 * 0.95; break;
        case 3:
            sum = price * 3 * 0.9; break;
        case 4:
            sum = price * 4 * 0.8; break;
        case 5:
            sum = price * 5 * 0.75; break;
    }

    return sum;
}

double CalculatePrice::TotalSum() {
    double sum = 0.0;
    int shop_basket[5];

    for (int i = 0; i < 5; i++) {
        shop_basket[i] = basket_[i];
    }

    int books = 0;

    for (int i = 0; i < 5; i++) {
        books += shop_basket[i];
    }

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

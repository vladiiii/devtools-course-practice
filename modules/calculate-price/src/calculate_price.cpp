// Copyright 2017 Ryabova Alyona

#include "include/calculate_price.h"

#include <stdio.h>
#include <string>

CalculatePrice::CalculatePrice(int *b, int size) {
    if (size != 5) throw std::string("Size must be determined!");
    for (int i = 0; i < 5; i++) {
        if (b[i] < 0)
            throw std::string("Mustn't be contain negative numbers");
        basket[i] = b[i];
    }
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

    int count;

    for (int i = 0; i < 5; i++) {
        while (shop_basket[i] != 0) {
            shop_basket[i]--;
            count = 1;
            for (int j = 0; j < 5; j++)
                if ((shop_basket[j] > 0) && (i != j)) {
                    count++;
                    shop_basket[j]--;
                }
                sum += DiscountCalculate(count);
        }
    }

    return sum;
}

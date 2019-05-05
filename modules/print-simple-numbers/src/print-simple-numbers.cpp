// Copyright 2019 by Zolotareva Olesya

#include <iostream>

#include "include/print-simple-numbers.h"

int SimpleNumbers::Check(int n) {
if (n < 1) {
    return -1;
} else {
    if (n == 1) {
        return 0;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return 0; }
        return n;
        }
    }
}
int SimpleNumbers::SizeOfArray(int a, int b) {
if ((b <= 1) || (a < 1) || (a >= b)) {
       return 0;
} else {
int size = 0;
    for (int i = a; i <= b; i++) {
        int tmp = 0;
        tmp = Check(i);
        if (tmp !=0)
            size = size + 1;
        }
return size;
    }
}
void SimpleNumbers::Print(int a, int b) {
int size = SizeOfArray(a, b);
if (size == 0) {
        std::cout << "error";
} else {
for (int i = a; i <= b; i++) {
        int tmp = 0;
        tmp = Check(i);
        if (tmp != 0 )
            std::cout << tmp << " ";
        }
}
}

// Copyright 2019 Vikhrev Ivan

#include "include/lcd_digits.h"

const std::string LCDDigits::zero[3] = {"._.",
                                        "|.|",
                                        "|_|"};

const std::string LCDDigits::one[3] = {"...",
                                       "..|",
                                       "..|"};

const std::string LCDDigits::two[3] = {"._.",
                                       "._|",
                                       "|_."};

std::string LCDDigits::decompose(const int& n) {
    int num = n;
    std::string number = "";
    do {
        number += std::to_string(num % 10);
        num /= 10;
    } while (num > 0);
    std::reverse(number.begin(), number.end());
    return number;
}

std::string LCDDigits::lcd_str(const std::string& s) {
    std::string lcd_n = "";
    int j = 0;
    int line = 0;
    for (int line = 0; line < 3; line++) {
        for (int i = 0; i < s.length(); i++) {
            switch (s[i])
            {
            case '0':
                lcd_n += zero[line];
                break;
            case '1':
                lcd_n += one[line];
                break;
            case '2':
                lcd_n += two[line];
                break;
            }
            lcd_n += " ";
        }
        lcd_n += "\n";
    }
    return lcd_n;
}

std::string LCDDigits::lcd(const int& n) {
    std::string number = decompose(n);
    return lcd_str(number);
}

std::string LCDDigits::lcd(const std::string& s) {
    return lcd_str(s);
}
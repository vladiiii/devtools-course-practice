// Copyright 2019 Vikhrev Ivan
#include <string>
#include <algorithm>
#include "include/lcd_digits.h"

const std::string LCDDigits::point[3] = { " ",
                                          " ",
                                          "."};

const std::string LCDDigits::colon[3] = {" ",
                                         ".",
                                         "." };

const std::string LCDDigits::zero[3] = {" _ ",
                                        "| |",
                                        "|_|"};

const std::string LCDDigits::one[3] = {" ",
                                       "|",
                                       "|"};

const std::string LCDDigits::two[3] = {" _ ",
                                       " _|",
                                       "|_ "};

const std::string LCDDigits::three[3] = {" _ ",
                                         " _|",
                                         " _|"};

const std::string LCDDigits::four[3] = {"   ",
                                        "|_|",
                                        "  |"};

const std::string LCDDigits::five[3] = {" _ ",
                                        "|_ ",
                                        " _|"};

const std::string LCDDigits::six[3] = {" _ ",
                                       "|_ ",
                                       "|_|"};

const std::string LCDDigits::seven[3] = {" _ ",
                                         "|  ",
                                         "|  "};

const std::string LCDDigits::eight[3] = {" _ ",
                                         "|_|",
                                         "|_|"};

const std::string LCDDigits::nine[3] = { " _ ",
                                         "|_|",
                                         " _|"};

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
    for (unsigned int line = 0; line < 3; line++) {
        for (unsigned int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '0':
                    lcd_n += zero[line];
                    break;
                case '1':
                    lcd_n += one[line];
                    break;
                case '2':
                    lcd_n += two[line];
                    break;
                case '3':
                    lcd_n += three[line];
                    break;
                case '4':
                    lcd_n += four[line];
                    break;
                case '5':
                    lcd_n += five[line];
                    break;
                case '6':
                    lcd_n += six[line];
                    break;
                case '7':
                    lcd_n += seven[line];
                    break;
                case '8':
                    lcd_n += eight[line];
                    break;
                case '9':
                    lcd_n += nine[line];
                    break;
                case ':':
                    lcd_n += colon[line];
                    break;
                case '.':
                    lcd_n += point[line];
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

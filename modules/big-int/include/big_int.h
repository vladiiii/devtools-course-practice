// Copyright 2019 Muravev Denis

#ifndef MODULES_BIG_INT_INCLUDE_BIG_INT_H_
#define MODULES_BIG_INT_INCLUDE_BIG_INT_H_

#include <string>
#include <stdint.h>
#define BIGINT_MAX 1000000000
#define MYINT64 int_fast64_t
#define MYUINT64 uint_fast64_t

class big_int {
 private:
    int size;
    int size_mem;
    char sign;
    int * mem;

    int realSize();
    void removingZeros();

 public:
    explicit big_int(MYINT64 bi = 0, int _sizeMem = 1);
    big_int(const big_int & bi);
    explicit big_int(const std::string & st);
    ~big_int();

    big_int & operator = (const big_int & bi);
    big_int & operator = (const MYINT64 & bi);

    big_int operator + (big_int bi);
    big_int operator - (big_int bi);
    big_int operator * (big_int bi);
    big_int operator / (big_int bi);
    big_int operator % (big_int bi);

    char operator < (big_int bi);
    char operator > (big_int bi);
    char operator <= (big_int bi);
    char operator >= (big_int bi);
    char operator == (big_int bi);
    char operator != (big_int bi);

    int & operator[] (int k);
    int getSize();
    int getSign();

    std::string BigIntToString();
    MYINT64 BigIntToInt();
};

#endif  // MODULES_BIG_INT_INCLUDE_BIG_INT_H_

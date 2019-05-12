// Copyright 2019 Guseva Catherine

#ifndef MODULES_RANGE_INCLUDE_RANGE_H_
#define MODULES_RANGE_INCLUDE_RANGE_H_

#include <array>

class Range {
 private:
     std::array<int, 4> interval_;

 public:
     explicit Range(std::string str);
     Range(const Range& obj);

     bool IntegerRangeContains(int* arr, int size);
     void GetAllPoints();
     bool ContainsRange(std::string str);
     void EndPoints();
     bool OverlapsRange(std::string str);

     bool operator==(const Range obj) const;
     bool operator!=(const Range obj) const;

     void SetFirst(int val);
     void SetSecond(int val);
     int GetFirst();
     int GetSecond();
};

#endif  // MODULES_RANGE_INCLUDE_RANGE_H_

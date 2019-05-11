// Copyright 2019 Guseva Catherine

#ifndef MODULES_RANGE_INCLUDE_RANGE_H_
#define MODULES_RANGE_INCLUDE_RANGE_H_

class Range {
 private:
     int interval_[4];

 public:
     explicit Range(const char *str);
     Range(const Range& obj);

     bool IntegerRangeContains(int* arr, int size);
     void GetAllPoints();
     bool ContainsRange(const char *str);
     void EndPoints();
     bool OverlapsRange(const char *str);

     bool operator==(const Range obj) const;
     bool operator!=(const Range obj) const;

     void SetFirst(int val);
     void SetSecond(int val);
     int GetFirst();
     int GetSecond();
};

#endif  // MODULES_RANGE_INCLUDE_RANGE_H_

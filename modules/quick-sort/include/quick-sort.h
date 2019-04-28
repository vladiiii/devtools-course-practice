// Copyright 2019 Gaydaychuk Yury

#ifndef MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_
#define MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_

class QuickSort {
 public:
    bool checkIncreasing(const int *pArr, const int size);
    void sort(int *pArr, int size);
 private:
    void swap(int* a, int* b);
    int partition (int *arr, int low, int high);
    void boundedSort(int *arr, int low, int high);
};

#endif // MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_

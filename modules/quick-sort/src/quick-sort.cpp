// Copyright 2019 Gaydaychuk Yury

#include "include/quick-sort.h"

#include <stdbool.h>

bool QuickSort::checkIncreasing(const int *pArr, const int size) {
    for (int i = 0; i < size - 1; i++) {
        if (pArr[i] > pArr[i + 1]) {
            return false;
        }
    }
    return true;
}

void QuickSort::mySort(int *pArr, int size){
    boundedSort(pArr, 0, size - 1);
}

void QuickSort::my_swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int QuickSort::partition (int *arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        {
            i++;
            my_swap(&arr[i], &arr[j]); 
        }
    } 
    my_swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

void QuickSort::boundedSort(int *arr, int low, int high){
    if (low < high) 
    {
        int pi = partition(arr, low, high); 
        boundedSort(arr, low, pi - 1); 
        boundedSort(arr, pi + 1, high); 
    } 
}



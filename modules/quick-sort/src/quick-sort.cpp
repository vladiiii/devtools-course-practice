// Copyright 2019 Gaydaychuk Yury

#include "include/quick-sort.h"

#include <stdbool.h>

bool QuickSort::checkIncreasing(const int *pArr, const int size){
    for(int i = 0; i < size - 1; i++){
        if(pArr[i] > pArr[i + 1]){
            return false;
        }
    }
	return true;
}

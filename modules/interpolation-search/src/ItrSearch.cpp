// Copyright 2019 Perov Dima

#include "include/ItrSearch.h"

ItrSearch::ItrSearch(int* myPtrSortedData, unsigned mySizeSortedData) {
    ptrSortedData  = myPtrSortedData;
    sizeSortedData = mySizeSortedData;
}

ItrSearch::ItrSearch() {
    ptrSortedData = nullptr;
    sizeSortedData  = 0;
}

ItrSearch::~ItrSearch() {
    ptrSortedData = nullptr;
}

int64_t ItrSearch::GetFindIndex() {
    return findIndex;
}

unsigned ItrSearch::GetSizeData() {
    return sizeSortedData;
}

int* ItrSearch::GetPtrData() {
    return ptrSortedData;
}

void ItrSearch::SetSortedData(int* myPtrSortedData, unsigned mySizeSortedData) {
    ptrSortedData  = myPtrSortedData;
    sizeSortedData = mySizeSortedData;
}

int64_t ItrSearch::Search(int toFind, unsigned myLeft, unsigned myRight) {
    unsigned left = myLeft;

    if (myRight == 0)
        myRight = sizeSortedData - 1;

    unsigned right = myRight;

    while (ptrSortedData[left] < toFind && ptrSortedData[right] > toFind) {
        unsigned mid = left + ((toFind - ptrSortedData[left]) *
        (right - left)) / (ptrSortedData[right] - ptrSortedData[left]);

        if (ptrSortedData[mid] < toFind) {
            left = mid + 1;
        } else if (ptrSortedData[mid] > toFind) {
            right = mid - 1;
        } else {
            findIndex = mid;
            return findIndex;
        }
    }

    if (ptrSortedData[left] == toFind) {
        findIndex = left;
        return findIndex;
    }
    if (ptrSortedData[right] == toFind) {
        findIndex = right;
        return findIndex;
    }

    findIndex = -1;
    return findIndex;  // Not found
}

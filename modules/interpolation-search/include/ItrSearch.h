// Copyright 2019 Perov Dima

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_ITRSEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_ITRSEARCH_H_

#include<string>

class ItrSearch {
 protected:
    int* ptrData;
    unsigned sizeData;
    int64_t findIndex;

 public:
    ItrSearch(int* myPtrSortedData, unsigned mySizeData);
    ItrSearch();
    ~ItrSearch();
    int64_t GetFindIndex();
    unsigned GetSizeData();
    int* GetPtrData();
    void SetSortedData(int* myPtrData, unsigned mySizeData);
    int64_t Search(int toFind, unsigned myLeft = 0, unsigned myRight = 0);
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_ITRSEARCH_H_"

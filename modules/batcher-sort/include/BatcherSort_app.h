// Copyright 2019 Kondrina Tatyana

#ifndef MODULES_BATCHER_SORT_INCLUDE_BATCHERSORT_APP_H_
#define MODULES_BATCHER_SORT_INCLUDE_BATCHERSORT_APP_H_

#include <string>
#include "include/BatcherSort.h"

class BatcherSortApp {
 private:
    std::string message_;
    void Info(const char* appname, const char* message = "");
    bool CheckArguments(int argc, const char** argv);

 public:
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_BATCHER_SORT_INCLUDE_BATCHERSORT_APP_H_

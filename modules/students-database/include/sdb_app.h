// Copyright 2019 Kudrin Matvey

#include <string>

#ifndef DEVTOOLS_SDB_APP_H
#define DEVTOOLS_SDB_APP_H

class SdbApp {
 public:
    SdbApp();
    std::string operator()(int argc, const char** argv);
    std::string Help(const char* appname);

 private:
    std::string message_;
};

#endif  // MODULES_STUDENTS_DATABASE_INCLUDE_SDB_APP_H_

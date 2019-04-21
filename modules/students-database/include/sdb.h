// Copyright 2019 Kutovoi Vadim

#include <unordered_map>
#include <vector>
#include <ctime>
#include <string>


struct student {
    std::string first_name;
    std::vector<int> marks;
};


#ifndef MODULES_STUDENTS_DATABASE_INCLUDE_SDB_H_
#define MODULES_STUDENTS_DATABASE_INCLUDE_SDB_H_

using uint = unsigned int;

class Sdb {
 public:
     Sdb() = default;
     Sdb(Sdb&&) = default;

     bool AddStudent(std::string&, std::string&);
     bool RemoveStudent(std::string&);
     bool AddMark(std::string&, uint&);

     float GetAvgMark(std::string&);

     uint GetNumberOfStudents();
     uint GetNumberOfGoodStudents();
     uint GetNumberOfBadStudents();

 private:
     std::unordered_map<std::string, student> table_;

     bool CheckStdExist(std::string&);
};

#endif // MODULES_STUDENTS_DATABASE_INCLUDE_SDB_H_

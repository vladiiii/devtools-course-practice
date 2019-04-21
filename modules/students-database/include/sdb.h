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

     inline bool AddStudent(std::string&, std::string&);
     inline bool RemoveStudent(std::string&);
     inline bool AddMark(std::string&, uint&);

     inline float GetAvgMark(std::string&);

     inline uint GetNumberOfStudents();
     inline uint GetNumberOfGoodStudents();
     inline uint GetNumberOfBadStudents();

 private:
     uint size_ = 0;

     std::unordered_map<std::string, student> table;

     bool CheckStdExist(std::string&);
};

#endif // MODULES_STUDENTS_DATABASE_INCLUDE_SDB_H_

// Copyright 2019 Kutovoi Vadim

#include "include/sdb.h"

bool Sdb::CheckStdExist(std::string& last_name) {
    auto rec = table.find(last_name);

    return !(rec == table.end());
}

bool Sdb::AddStudent(std::string& first_name, std::string& last_name) {
    student st = { first_name };

    return table.insert(std::make_pair(last_name, st)).second;
}

bool Sdb::RemoveStudent(std::string& last_name) {
    auto rec = table.find(last_name);

    if (rec == table.end())
        return false;
    else {
        table.erase(rec);
        return true;
    }
}

bool Sdb::AddMark(std::string& last_name, uint& mark) {
    auto rec = table.find(last_name);

    if (rec == table.end())
        return false;
    else {
        rec->second.marks.push_back(mark);

        return true;
    }
}

float Sdb::GetAvgMark(std::string& last_name) {
    auto rec = table.find(last_name);

    if (rec == table.end())
        return -1;
    else {
        uint num_marks = 0, mark_sum = 0;

        for (auto it = rec->second.marks.begin(); it != rec->second.marks.end(); ++it) {
            mark_sum += *it;
            num_marks++;
        }

        return mark_sum / static_cast<float>(num_marks);
    }
}

uint Sdb::GetNumberOfStudents() {
    return table.size();
}

uint Sdb::GetNumberOfGoodStudents() {
    uint st_count = 0;
    float avg_mark = 0;

    for (auto it : table) {
        std::string last_name = it.first;
        avg_mark = GetAvgMark(last_name);

        if (avg_mark > 3)
            st_count++;
    }

    return st_count;
}

uint Sdb::GetNumberOfBadStudents() {
    uint st_count = 0;
    float avg_mark = 0;

    for (auto it : table) {
        std::string last_name = it.first;
        avg_mark = GetAvgMark(last_name);

        if (avg_mark < 4)
            st_count++;
    }
    
    return st_count;
}
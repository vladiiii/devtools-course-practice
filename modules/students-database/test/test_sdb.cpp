// Copyright 2019 Kutovoi Vadim

#include <gtest/gtest.h>

#include "include/sdb.h"


TEST(StudentDataBaseTest,
    Can_Add_Record) {
    // Arrange
    Sdb db;
    std::string first_name = "Alan", last_name = "Turing";

    // Act & Assert 

    ASSERT_TRUE(db.AddStudent(first_name, last_name));
}

TEST(StudentDataBaseTest,
    Cant_Add_Existing_Record) {
    // Arrange

    Sdb db;
    std::string first_name = "Alan", last_name = "Turing";
    db.AddStudent(first_name, last_name);
    
    // Act & Assert 

    ASSERT_FALSE(db.AddStudent(first_name, last_name));
}

TEST(StudentDataBaseTest,
    Can_Remove_Record) {
    // Arrange

    Sdb db;
    std::string first_name = "Alan", last_name = "Turing";
    db.AddStudent(first_name, last_name);

    // Act & Assert

    EXPECT_TRUE(db.RemoveStudent(last_name));
}

TEST(StudentDataBaseTest,
    Cant_Remove_Non_Existing_Record) {
    // Arrange

    Sdb db;
    std::string first_name = "Alan", last_name = "Turing";

    db.AddStudent(first_name, last_name);

    last_name = "Cormen";

    
    
    EXPECT_FALSE(db.RemoveStudent(last_name));
}

TEST(StudentDataBaseTest,
    Can_Add_Mark) {
    // Arrange

    Sdb db;
    uint mark = 5;
    std::string first_name = "Alan", last_name = "Turing";

    db.AddStudent(first_name, last_name);

    // Act & Assert

    EXPECT_TRUE(db.AddMark(last_name, mark));
}

TEST(StudentDataBaseTest,
    Can_Get_Avg_Mark) {
    // Arrange

    Sdb db;

    uint mark = 5;
    std::string first_name = "Alan", last_name = "Turing";

    db.AddStudent(first_name, last_name);
    
    db.AddMark(last_name, mark);

    mark = 3;
    db.AddMark(last_name, mark);

    mark = 4;
    db.AddMark(last_name, mark);

    // Act & Assert

    EXPECT_EQ(db.GetAvgMark(last_name), 4);
}

TEST(StudentDataBaseTest,
    Can_Get_Num_Of_Records) {
    // Arrange

    Sdb db;

    std::string first_name = "Alan", last_name = "Turing";

    db.AddStudent(first_name, last_name);

    last_name = "Cormen";
    first_name = "Thomas";

    db.AddStudent(first_name, last_name);

    // Act & Assert

    EXPECT_EQ(db.GetNumberOfStudents(), 2);
}

TEST(StudentDataBaseTest,
    Can_Get_Number_Of_Good_Students) {
    // Arrange

    Sdb db;

    uint mark = 5;
    std::string first_name = "Alan", last_name = "Turing";

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, mark);

    last_name = "Cormen";
    first_name = "Thomas";
    mark = 4;

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, mark);

    last_name = "Zuckerberg";
    first_name = "Mark";
    mark = 3;

    // Act & Assert

    EXPECT_EQ(db.GetNumberOfGoodStudents(), 2);
}

TEST(StudentDataBaseTest,
    Can_Get_Number_Of_Bad_Students) {
    // Arrange

    Sdb db;

    uint mark = 5;
    std::string first_name = "Alan", last_name = "Turing";

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, mark);

    last_name = "Cormen";
    first_name = "Thomas";
    mark = 4;

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, mark);

    last_name = "Zuckerberg";
    first_name = "Mark";
    mark = 3;

    db.AddStudent(first_name, last_name);
    db.AddMark(last_name, mark);

    // Act & Assert

    EXPECT_EQ(db.GetNumberOfBadStudents(), 1);
}

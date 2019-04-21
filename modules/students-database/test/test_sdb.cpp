// Copyright 2019 Kutovoi Vadim

#include <gtest/gtest.h>

#include "include/sdb.h"


TEST(StudentDataBaseTest,
    Can_Find_Existing_Record) {
    // Arrange
    
    // Act
    
    // Assert
}

TEST(StudentDataBaseTest,
    Cant_Find_Non_Existing_Record) {
    // Arrange

    // Act

    // Assert
}

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

    // Act

    // Assert
}

TEST(StudentDataBaseTest,
    Cant_Remove_Non_Existing_Record) {
    // Arrange

    // Act

    // Assert
}

TEST(StudentDataBaseTest,
    Can_Get_Avg_Mark) {
    // Arrange

    // Act

    // Assert
}

TEST(StudentDataBaseTest,
    Can_Get_Num_Of_Records) {
    // Arrange

    // Act

    // Assert
}

TEST(StudentDataBaseTest,
    Can_Get_Number_Of_Good_Students) {
    // Arrange

    // Act

    // Assert
}

TEST(StudentDataBaseTest,
    Can_Get_Number_Of_Bad_Students) {
    // Arrange

    // Act

    // Assert
}

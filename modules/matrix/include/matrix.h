// Copyright 2019 Trykin Alexander

#ifndef MODULES_MATRIX_INCLUDE_MATRIX_H_
#define MODULES_MATRIX_INCLUDE_MATRIX_H_

#include <initializer_list>

class Matrix {
 private:
    int rows_;
    int cols_;
    double **matrix_;

 public:
    Matrix();
    explicit Matrix(const int rows, const int cols);
    Matrix(std::initializer_list<std::initializer_list<double>> list);
    Matrix(const Matrix &src);

    ~Matrix();

    const int getRows() const;
    const int getCols() const;

    double& operator()(int i, int j);
    const double& operator()(int i, int j) const;

    Matrix& operator=(const Matrix &src);

    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs);
    friend Matrix operator-(const Matrix &lhs, const Matrix &rhs);
    friend Matrix operator*(const Matrix &lhs, const Matrix &rhs);

    Matrix& operator+=(const Matrix &src);
    Matrix& operator-=(const Matrix &src);
    Matrix& operator*=(const Matrix &src);

    bool operator==(const Matrix &src) const;

    Matrix transpose();
    Matrix inverse();
    double minor(int row, int col);
    double det();
};

#endif  // MODULES_MATRIX_INCLUDE_MATRIX_H_

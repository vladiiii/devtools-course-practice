// Copyright 2019 Trykin Alexander

#include "include/matrix.h"

#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

Matrix::Matrix() :
    rows_(0), cols_(0) {
    matrix_ = nullptr;
}

Matrix::Matrix(const int rows, const int cols) :
        rows_(rows), cols_(cols) {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
        matrix_[i] = new double[cols_];
        std::fill(matrix_[i], matrix_[i] + cols_, 0.0);
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) {
    rows_ = list.size();
    cols_ = list.begin()->size();

    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
        matrix_[i] = new double[cols_];
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            matrix_[i][j] = *((list.begin() + i)->begin() + j);
        }
    }
}

Matrix::Matrix(const Matrix &src) :
        rows_(src.rows_), cols_(src.cols_) {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
        matrix_[i] = new double[cols_];
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            matrix_[i][j] = src.matrix_[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows_; ++i) {
        delete[] matrix_[i];
    }

    delete[] matrix_;
}

const int Matrix::getRows() const {
    return rows_;
}

const int Matrix::getCols() const {
    return cols_;
}

double& Matrix::operator()(int i, int j) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::string("OutOfRangeException");
    } else {
        return matrix_[i][j];
    }
}

const double& Matrix::operator()(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::string("OutOfRangeException");
    } else {
        return matrix_[i][j];
    }
}

Matrix &Matrix::operator=(const Matrix &src) {
    if (rows_ != src.rows_ || cols_ != src.cols_) {
        rows_ = src.rows_;
        cols_ = src.cols_;
        matrix_ = new double*[rows_];

        for (int i = 0; i < rows_; ++i) {
            matrix_[i] = new double[cols_];
        }
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            matrix_[i][j] = src.matrix_[i][j];
        }
    }

    return *this;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.rows_ != rhs.rows_ || lhs.cols_ != rhs.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        Matrix res(lhs.rows_, lhs.cols_);

        for (int i = 0; i < res.rows_; ++i) {
            for (int j = 0; j < res.cols_; ++j) {
                res.matrix_[i][j] = lhs.matrix_[i][j] + rhs.matrix_[i][j];
            }
        }

        return res;
    }
}

Matrix operator-(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.rows_ != rhs.rows_ || lhs.cols_ != rhs.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        Matrix res(lhs.rows_, lhs.cols_);

        for (int i = 0; i < res.rows_; ++i) {
            for (int j = 0; j < res.cols_; ++j) {
                res.matrix_[i][j] = lhs.matrix_[i][j] - rhs.matrix_[i][j];
            }
        }

        return res;
    }
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.cols_ != rhs.rows_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        Matrix res(lhs.rows_, rhs.cols_);

        for (int i = 0; i < res.rows_; ++i) {
            for (int j = 0; j < res.cols_; ++j) {
                for (int k = 0; k < lhs.cols_; ++k) {
                    res.matrix_[i][j] += lhs.matrix_[i][k] * rhs.matrix_[k][j];
                }
            }
        }

        return res;
    }
}

Matrix &Matrix::operator+=(const Matrix &src) {
    if (rows_ != src.rows_ || cols_ != src.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                matrix_[i][j] += src.matrix_[i][j];
            }
        }

        return *this;
    }
}

Matrix &Matrix::operator-=(const Matrix &src) {
    if (rows_ != src.rows_ || cols_ != src.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                matrix_[i][j] -= src.matrix_[i][j];
            }
        }

        return *this;
    }
}

Matrix &Matrix::operator*=(const Matrix &src) {
    return *this = *this * src;
}

bool Matrix::operator==(const Matrix &src) const {
    if (rows_ != src.rows_ || cols_ != src.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (matrix_[i][j] != src.matrix_[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
}

Matrix Matrix::Transpose() {
    Matrix res(cols_, rows_);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            res.matrix_[j][i] = matrix_[i][j];
        }
    }

    return res;
}

Matrix Matrix::Inverse() {
    if (rows_ != cols_) {
        throw std::string("NotSquareMatrixException");
    } else {
        double det = this->Det();
        if (det == 0) {
            throw std::string("NullDeterminantException");
        }

        int size = rows_;
        Matrix extra_minors(size, size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                extra_minors.matrix_[i][j] =
                        std::pow(-1, i + j) * this->Minor(i, j) / det;
            }
        }

        return extra_minors.Transpose();
    }
}

double Matrix::Minor(int row, int col) {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
        throw std::string("OutOfRangeException");
    } else if (rows_ != cols_) {
        throw std::string("NotSquareMatrixException");
    } else {
        int size = rows_;
        Matrix res(size - 1, size - 1);

        int offset_rows = 0, offset_cols = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (i == row) {
                offset_rows = 1;
            }

            for (int j = 0; j < size - 1; ++j) {
                if (j == col) {
                    offset_cols = 1;
                }

                res.matrix_[i][j] = matrix_[i + offset_rows][j + offset_cols];
            }

            offset_cols = 0;
        }

        return res.Det();
    }
}

double Matrix::Det() {
    if (rows_ != cols_) {
        throw std::string("NotSquareMatrixException");
    } else {
        int size = rows_;
        std::vector<int> numbers_of_index(size);
        for (int i = 0; i < size; ++i) {
            numbers_of_index[i] = i;
        }

        auto inv_count = [](std::vector<int> &numbers_of_index) -> int {
            int count = 0;
            for (int i = 0; i < numbers_of_index.size() - 1; i++) {
                for (int j = i + 1; j < numbers_of_index.size(); j++) {
                    if (numbers_of_index[i] > numbers_of_index[j]) {
                        count++;
                    }
                }
            }

            return count;
        };

        double det = 0.0;
        do {
            double local_sum = 1.0;
            for (int i = 0; i < size; i++) {
                local_sum *= matrix_[numbers_of_index[i]][i];
            }

            local_sum *= std::pow(-1, inv_count(numbers_of_index));
            det += local_sum;
        } while (std::next_permutation(numbers_of_index.begin(),
                numbers_of_index.end()));

        return det;
    }
}

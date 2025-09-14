#include "matrix.h"
#include <cstdlib>
#include <chrono>

Matrix::Matrix(const int n) : size(n) {
    data = new int*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void Matrix::fill_random() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = std::rand() % 100 + 1;
        }
    }
}

int* Matrix::operator[](const int index) {
    return data[index];
}

const int* Matrix::operator[](const int index) const {
    return data[index];
}

int Matrix::get_size() const {
    return size; 
}

long long multiply_matrices(const Matrix& a, const Matrix& b, Matrix& c) {
    const auto start = std::chrono::high_resolution_clock::now();

    const int size = a.get_size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int sum = 0;
            for (int r = 0; r < size; ++r) {
                sum += a[i][r] * b[r][j];
            }
            c[i][j] = sum;
        }
    }

    const auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}
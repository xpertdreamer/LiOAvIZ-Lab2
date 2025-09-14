#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int size;
    int** data;

public:
    explicit Matrix(int n);
    ~Matrix();

    Matrix(const Matrix&) = delete;
    Matrix& operator=(const Matrix&) = delete;

    constexpr static int sizes[] = {100, 200, 300, 400, 1000, 2000, 3000};

    void fillRandom() const;
    int* operator[](int index);
    const int* operator[](int index) const;
    [[nodiscard]] int getSize() const;
};

long long multiplyMatrices(const Matrix& a, const Matrix& b, Matrix& c);

#endif
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int size;
    int** data;

public:
    explicit Matrix(int n);
    ~Matrix();

    /* That was made for memory safety;
     * Just copying ban for class Matrix
     *
     * oblepixa */
    Matrix(const Matrix&) = delete;
    Matrix& operator=(const Matrix&) = delete;

    constexpr static int sizes[] = {100, 200, 300, 400, 1000, 2000, 4000, 10000, 50000};

    void fill_random() const;
    /* Operator overload for index access
     *
     * oblepixa */
    int* operator[](int index);
    const int* operator[](int index) const;
    [[nodiscard]] int get_size() const;
};

long long multiply_matrices(const Matrix& a, const Matrix& b, Matrix& c);

#endif
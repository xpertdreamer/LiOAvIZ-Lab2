#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "matrix.h"

int main() {
    std::srand(std::time(nullptr));

    std::cout << "ТЕСТИРОВАНИЕ ВРЕМЕНИ УМНОЖЕНИЯ МАТРИЦ" << std::endl;
    std::cout << "======================================" << std::endl;

    for (const int size : Matrix::sizes) {
        std::cout << "\nМатрица " << size << "x" << size << ":" << std::endl;
        std::cout << "-------------------" << std::endl;

        Matrix a(size);
        Matrix b(size);
        Matrix c(size);

        a.fillRandom();
        b.fillRandom();

        const long long timeMicro = multiplyMatrices(a, b, c);
        const double timeSec = static_cast<double>(timeMicro) / 1000000.0;

        std::cout << "Время умножения: "
                  << std::fixed << std::setprecision(6) << timeSec
                  << " сек" << std::endl;
    }

    return 0;
}
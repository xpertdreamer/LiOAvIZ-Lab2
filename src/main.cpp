#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "matrix.h"
#include "sorts.h"
#include <vector>

// O(n^3)

int main() {
    std::srand(std::time(nullptr));
    Sorter sorter;

    std::cout << "ТЕСТИРОВАНИЕ ВРЕМЕНИ УМНОЖЕНИЯ МАТРИЦ" << std::endl;
    std::cout << "======================================" << std::endl;

    for (const int size : Matrix::sizes) {
        std::cout << "\nМатрица " << size << "x" << size << ":" << std::endl;
        std::cout << "-------------------" << std::endl;

        Matrix a(size);
        Matrix b(size);
        Matrix c(size);

        a.fill_random();
        b.fill_random();

        const long long timeMicro = multiply_matrices(a, b, c);
        const double timeSec = static_cast<double>(timeMicro) / 1000000.0;

        std::cout << "Время умножения: "
                  << std::fixed << std::setprecision(6) << timeSec
                  << " сек" << std::endl;
    }

    std::cout << "СРАВНЕНИЕ АЛГОРИТМОВ СОРТИРОВКИ" << std::endl;
    std::cout << "======================================" << std::endl;

    for (const int size : Matrix::sizes) {
        // Test arrays
        const int* randomArray = sorter.create_random_array(size);
        const int* ascendingArray = sorter.create_ascending_array(size);
        const int* descendingArray = sorter.create_descending_array(size);
        const int* mixedArray = sorter.create_mixed_array(size);

        std::vector<const int*> arrays = {randomArray, ascendingArray, descendingArray, mixedArray};
        std::vector<std::string> types = {"Случайный", "Возрастающий", "Убывающий", "Смешанный"};

        for (int test = 0; test < 4; ++test) {
            std::cout << test + 1 << ". " << types.at(test) << " массив:" << std::endl;

            // Shell sort
            const auto temp1 = sorter.copy_array(arrays.at(test), size);
            auto start = std::chrono::high_resolution_clock::now();
            sorter.shell_sort(temp1, size);
            auto end = std::chrono::high_resolution_clock::now();
            const double shellTime = std::chrono::duration<double>(end - start).count();
            std::cout << "Shell sort: " << shellTime << " s"<< std::endl;
            delete[] temp1;

            // Quick sort
        }

        // Free memory
        delete[] randomArray;
        delete[] ascendingArray;
        delete[] descendingArray;
        delete[] mixedArray;
    }

    return 0;
}
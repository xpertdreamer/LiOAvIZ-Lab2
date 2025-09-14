#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "matrix.h"
#include "sorts.h"
#include <vector>
#include <algorithm>

#ifdef _WIN32
    #include "windows.h"
#endif

// O(n^3)

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::srand(std::time(nullptr));

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
        const int* randomArray = Sorter::create_random_array(size);
        const int* ascendingArray = Sorter::create_ascending_array(size);
        const int* descendingArray = Sorter::create_descending_array(size);
        const int* mixedArray = Sorter::create_mixed_array(size);

        std::vector arrays = {randomArray, ascendingArray, descendingArray, mixedArray};
        std::vector<std::string> types = {"Случайный", "Возрастающий", "Убывающий", "Смешанный"};

        for (int test = 0; test < 4; ++test) {
            std::cout << test + 1 << ". " << types.at(test) << " массив (" << size << " элементов):" << std::endl;

            // Shell sort
            const auto temp1 = Sorter::copy_array(arrays.at(test), size);
            auto start = std::chrono::high_resolution_clock::now();
            Sorter::shell_sort(temp1, size);
            auto end = std::chrono::high_resolution_clock::now();
            const double shellTime = std::chrono::duration<double>(end - start).count();
            std::cout << "\tShell sort: "
            << std::fixed << std::setprecision(6) << shellTime << " s"<< std::endl;
            delete[] temp1;

            // Quick sort
            const auto temp2 = Sorter::copy_array(arrays.at(test), size);
            start = std::chrono::high_resolution_clock::now();
            Sorter::quick_sort(temp2, 0, size - 1);
            end = std::chrono::high_resolution_clock::now();
            const double quickTime = std::chrono::duration<double>(end - start).count();
            std::cout << "\tQuick sort: "
            << std::fixed << std::setprecision(6) << quickTime << " s"<< std::endl;
            delete[] temp2;

            // C++ qs
            const auto temp3 = Sorter::copy_array(arrays.at(test), size);
            start = std::chrono::high_resolution_clock::now();
            std::qsort(temp3, size, sizeof(int), Sorter::compare);
            end = std::chrono::high_resolution_clock::now();
            const double quickTime2 = std::chrono::duration<double>(end - start).count();
            std::cout << "\tC++ quick sort: "
            << std::fixed << std::setprecision(6) << quickTime2 << " s"<< std::endl;
            delete[] temp3;
        }

        std::cout << "-------------------------------------" << std::endl;

        // Free memory
        delete[] randomArray;
        delete[] ascendingArray;
        delete[] descendingArray;
        delete[] mixedArray;
    }

    return 0;
}

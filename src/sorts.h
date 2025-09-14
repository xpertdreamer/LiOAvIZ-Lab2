//
// Created by oblepixa on 9/14/25.
//

#ifndef SORTS_H
#define SORTS_H

class Sorter {
public:
    // Shell sort for dynamic array
    static void shell_sort(int* items, int n);
    // Quick sort for dynamic array
    // Call this function with qs(items, 0, count-1);
    static void quick_sort(int* items, int left, int right);

    // Comparator for std::qsort
    static int compare(const void* a, const void* b) {
        return *(int*)a - *(int*)b;
    }

    static int* create_random_array(int size);
    static int* create_ascending_array(int size);
    static int* create_descending_array(int size);
    static int* create_mixed_array(int size);
    static int* copy_array(const int* source, int size);
};

#endif //SORTS_H

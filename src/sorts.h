//
// Created by oblepixa on 9/14/25.
//

#ifndef SORTS_H
#define SORTS_H

class Sorter {
public:
    // Shell sort for dynamic array
    void shell_sort(int* items, int n);
    // Quick sort for dynamic array
    // Call this function with qs(items, 0, count-1);
    void quick_sort(int* items, int left, int right);

    int* create_random_array(int size);
    int* create_ascending_array(int size);
    int* create_descending_array(int size);
    int* create_mixed_array(int size);
    int* copy_array(const int* source, int size);
};

#endif //SORTS_H

//
// Created by oblepixa on 9/14/25.
//
#include "sorts.h"

#include <cstdlib>

void Sorter::shell_sort(int *items, const int n) {
    int i, j, gap, k;
    int x, a[5] = {9, 5, 3, 2, 1};
    for (k = 0; k < 5; ++k) {
        gap = a[k];
        for (i = gap; i < n; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void Sorter::quick_sort(int *items, const int left, const int right) {
    int i, j;
    int x, y;

    i = left;
    j = right;

    // The choice of a comparer
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) quick_sort(items, left, j);
    if (i < right) quick_sort(items, i, right);
}

int *Sorter::create_random_array(int size) {
    const auto arr = new int[size];
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 1000 + 1;
    return arr;
}


int *Sorter::create_ascending_array(int size) {
    const auto arr = new int[size];
    for (int i = 0; i < size; ++i)
        arr[i] = i;
    return arr;
}

int *Sorter::create_descending_array(int size) {
    const auto arr = new int[size];
    for (int i = 0; i < size; ++i)
        arr[i] = size - i;
    return arr;
}

int *Sorter::create_mixed_array(int size) {
    const auto arr = new int[size];
    const int half = size / 2;
    for (int i = 0; i < size; ++i) {
        if (i < half) arr[i] = i;
        else arr[i] = size - i + half;
    }
    return arr;
}

int *Sorter::copy_array(const int *source, int size) {
    const auto copy = new int[size];
    for (int i = 0; i < size; ++i) copy[i] = source[i];
    return copy;
}








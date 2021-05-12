#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "../swap.h"

#define _quicksort(T) quicksort$_##T##_$
#define quicksort(T) _quicksort(T)

#define _quicksort_ipl(T) void quicksort(T)(T *arr, int lo, int hi) {\
    int i, last;\
    if (lo >= hi) {\
        return;\
    }\
    swap(T)(arr + lo, arr + (lo + hi) / 2);\
    last = lo;\
    for (i = lo + 1; i <= hi; i++) {\
        if (arr[i] < arr[lo]) {\
            swap(T)(arr + (++last), arr + i);\
        }\
    }\
    swap(T)(arr + lo, arr + last);\
    quicksort(T)(arr, lo, last - 1);\
    quicksort(T)(arr, last + 1, hi);\
}
#define quicksort_ipl(T) _quicksort_ipl(T)

#endif

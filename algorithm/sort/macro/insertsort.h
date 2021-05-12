#ifndef INSERT_SORT_H
#define INSERT_SORT_H

#include "../../swap.h"
#include <stddef.h>

#define _insertsort(T) insertsort$_##T##_$
#define insertsort(T) _insertsort(T)

#define _insertsort_ipl(T) void insertsort(T)(T *arr, size_t len) {\
    size_t i, j;\
    T v;\
    for (i = len - 1; i > 0; i--) {\
        if (arr[i - 1] > arr[i]) {\
            swap(T)(arr + i - 1, arr + i);\
        }\
    }\
    for (i = 2; i < len; i++) {\
        j = i;\
        v = arr[i];\
        while (v < arr[j - 1]) {\
            arr[j] = arr[j - 1];\
            j--;\
        }\
        arr[j] = v;\
    }\
}
#define insertsort_ipl(T) _insertsort_ipl(T)

#endif

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "../../swap.h"
#include <stddef.h>
#define size_t size_t

#define _bubblesort(T) bubblesort$_##T##_$
#define bubblesort(T) _bubblesort(T)

#define _bubblesort_ipl(T) void bubblesort(T)(T *arr, size_t len) {\
    size_t i, j;\
    for (i = 0; i < len - 1; i++) {\
        for (j = len - 1; j > i; j--) {\
            if (arr[j - 1] > arr[j]) {\
                swap(T)(arr + j - 1, arr + j);\
            }\
        }\
    }\
}
#define bubblesort_ipl(T) _bubblesort_ipl(T)

#endif

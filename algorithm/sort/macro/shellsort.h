#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "../../swap.h"
#include <stddef.h>
#define size_t size_t

#define _shellsort(T) shellsort$_##T##_$
#define shellsort(T) _shellsort(T)

#define _shellsort_ipl(T) void shellsort(T)(T *arr, size_t len) {\
    size_t i, j, h;\
    T v;\
    for (h = 1; h <= (len - 2) / 9; h = 3 * h + 1) {}\
    while (h > 0) {\
        for (i = h; i < len; i++) {\
            j = i;\
            v = arr[i];\
            while (j >= h && v < arr[j - h]) {\
                arr[j] = arr[j - h];\
                j -= h;\
            }\
            arr[j] = v;\
        }\
        h /= 3;\
    }\
}
#define shellsort_ipl(T) _shellsort_ipl(T)

#endif

#ifndef SELECT_SORT_H
#define SELECT_SORT_H

#include "../../swap.h"
#include <stddef.h>

#define _selectsort(T) selectsort$_##T##_$
#define selectsort(T) _selectsort(T)

#define _selectsort_ipl(T) void selectsort(T)(T *arr, size_t len) {\
    size_t i, j, min;\
    for (i = 0; i < len - 1; i++) {\
        min = i;\
        for (j = i + 1; j < len; j++) {\
            if (arr[j] < arr[min]) {\
                min = j;\
            }\
        }\
        swap(T)(arr + i, arr + min);\
    }\
}
#define selectsort_ipl(T) _selectsort_ipl(T)

#endif

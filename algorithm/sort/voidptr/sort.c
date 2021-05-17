#include "sort.h"
#include <stdlib.h>
#include <string.h>

void sort(void *beg, void *end, bool (*cmpless)(const void *a, const void *b)) {
    quicksort(beg, 0, end - beg - 1, end - beg, cmpless);
}

void quicksort(void *base, long lo, long hi, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    long i, last;
    if (lo >= hi) {
        return;
    }
    swap(base + lo, base + (lo + hi) / 2, size);
    last = lo;
    for (i = lo + 1; i <= hi; i++) {
        if ((*cmpless)(base + i, base + lo)) {
            swap(base + (++last), base + i, size);
        }
    }
    swap(base + lo, base + last, size);
    quicksort(base, lo, last - 1, size, cmpless);
    quicksort(base, last + 1, hi, size, cmpless);
}

void bubblesort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    size_t i, j;
    for (i = 0; i < arrsize - 1; i++) {
        for (j = arrsize - 1; j > i; j--) {
            if (!(*cmpless)(base + j -1, base + j)) {
                swap(base + j - 1, base + j, size);
            }
        }
    }
}

void selectsort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    size_t i, j, min;
    for (i = 0; i < arrsize - 1; i++) {
        min = i;
        for (j = i + 1; j < arrsize; j++) {
            if ((*cmpless)(base + j, base + min)) {
                min = j;
            }
        }
        swap(base + i, base + min, size);
    }
}

void insertsort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    size_t i, j;
    void *v = malloc(size);
    for (i = arrsize - 1; i > 0; i--) {
        if (!(*cmpless)(base + i - 1, base + i)) {
            swap(base + i - 1, base + i, size);
        }
    }
    for (i = 2; i < arrsize; i++) {
        j = i;
        memcpy(v, base + i, size);
        while ((*cmpless)(v, base + j - 1)) {
            memcpy(base + j, base + j - 1, size);
            j--;
        }
        memcpy(base + j, v, size);
    }
    free(v);
}

void shellsort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    size_t i, j, h;
    void *v = malloc(size);
    for (h = 1; h <= (arrsize - 2) / 9; h = 3 * h + 1) {}
    while (h > 0) {
        for (i = h; i < arrsize; i++) {
            j = i;
            memcpy(v, base + i, size);
            while (j >= h && (*cmpless)(v, base + j - h)) {
                memcpy(base + j, base + j - h, size);
                j -= h;
            }
            memcpy(base + j, v, size);
        }
        h /= 3;
    }
    free(v);
}

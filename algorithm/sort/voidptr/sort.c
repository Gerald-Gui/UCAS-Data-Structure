#include "sort.h"
#include <stdlib.h>
#include <string.h>

void sort(void *beg, void *end, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    //quicksort(beg, 0, end - beg - 1, end - beg, cmpless);
    quicksort(beg, beg - end, size, cmpless);
}

void quicksort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    typedef struct { size_t lo, hi; } pair;

    if (arrsize == 0) { return; }
    size_t sp, left, right;
    void *mid = malloc(size);
    pair tmp, *stk = malloc(arrsize * sizeof(pair));
    sp = 0;
    stk[sp++] = (pair){0, arrsize - 1};
    while (sp != 0) {
        tmp = stk[--sp];
        if (tmp.lo >= tmp.hi) { continue; }
        memcpy(mid, (char*)base + size * (tmp.lo + tmp.hi) / 2, size);
        left = tmp.lo;
        right = tmp.hi;
        do {
            while ((*cmpless)((char*)base + size * left, mid)) { left++; }
            while ((*cmpless)(mid, (char*)base + size * right)) { right--; }
            if (left <= right) {
                swap((char*)base + left * size, (char*)base + right * size, size);
                left++;
                right = right == 0 ? left - 1 : right - 1;
            }
        } while (left <= right);
        if (tmp.lo < right) { stk[sp++] = (pair){tmp.lo, right}; }
        if (left < tmp.hi) { stk[sp++] = (pair){left, tmp.hi}; }
    }
    free(mid);
    free(stk);
}

/* recursive edition from The C Programming Language
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
*/

void bubblesort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    size_t i, j;
    for (i = 0; i < arrsize - 1; i++) {
        for (j = arrsize - 1; j > i; j--) {
            if (!(*cmpless)((char*)base + size * (j - 1), (char*)base + size * j)) {
                swap((char*)base + size * (j - 1), (char*)base + size * j, size);
            }
        }
    }
}

void selectsort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    size_t i, j, min;
    for (i = 0; i < arrsize - 1; i++) {
        min = i;
        for (j = i + 1; j < arrsize; j++) {
            if ((*cmpless)((char*)base + size * j, (char*)base + size * min)) {
                min = j;
            }
        }
        swap((char*)base + size * i, (char*)base + size * min, size);
    }
}

void insertsort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b)) {
    size_t i, j;
    void *v = malloc(size);
    for (i = arrsize - 1; i > 0; i--) {
        if (!(*cmpless)((char*)base + size * (i - 1), (char*)base + i)) {
            swap((char*)base + size * (i - 1), (char*)base + size * i, size);
        }
    }
    for (i = 2; i < arrsize; i++) {
        j = i;
        memcpy(v, (char*)base + size * i, size);
        while ((*cmpless)(v, (char*)base + size * (j - 1))) {
            memcpy((char*)base + size * j, (char*)base + size * (j - 1), size);
            j--;
        }
        memcpy((char*)base + size * j, v, size);
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
            memcpy(v, (char*)base + size * i, size);
            while (j >= h && (*cmpless)(v, (char*)base + size * (j - h))) {
                memcpy((char*)base + size * j, (char*)base + size * (j - h), size);
                j -= h;
            }
            memcpy((char*)base + size * j, v, size);
        }
        h /= 3;
    }
    free(v);
}

#ifndef SORT_H
#define SORT_H

#include "../../swap_on_byte.h"
#include <stdbool.h>

void sort(void *beg, void *end, bool (*cmpless)(const void *a, const void *b));

void quicksort(void *base, long lo, long hi, size_t size, bool (*cmpless)(const void *a, const void *b));
void bubblesort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b));
void selectsort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b));
void insertsort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b));
void shellsort(void *base, size_t arrsize, size_t size, bool (*cmpless)(const void *a, const void *b));

#endif

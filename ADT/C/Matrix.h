#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

typedef int elem_t;
typedef struct {
    size_t r, c;
    elem_t **base;
} matrix_t;

matrix_t *InitMatrix(size_t m, size_t n, elem_t val);
matrix_t *DestroyMatrix(matrix_t *mtx);

#endif

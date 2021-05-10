#include <Matrix.h>
#include <stdlib.h>

matrix_t *InitMatrix(size_t m, size_t n) {
    matrix_t *mtx = malloc(sizeof(matrix_t));
    if (!mtx) {
        abort();
    }
    mtx->r = m;
    mtx->c = n;
    mtx->base = malloc(m * sizeof(elem_t*));
    if (!mtx->base) {
        abort();
    }
    for (size_t i = 0; i < m; i++) {
        mtx->base[i] = malloc(n * sizeof(elem_t));
        if (!mtx->base[i]) {
            abort();
        }
    }
    return mtx;
}

matrix_t *DestroyMatrix(matrix_t *mtx) {
    for (size_t i = 0; i < mtx->r; i++) {
        free(mtx->base[i]);
    }
    free(mtx->base);
    free(mtx);
    return NULL;
}

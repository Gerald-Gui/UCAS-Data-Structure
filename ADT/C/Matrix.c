#include <Matrix.h>
#include <stdlib.h>

matrix_t *InitMatrix(size_t m, size_t n, elem_t val) {
    matrix_t *mtx = malloc(sizeof(matrix_t));
    if (!mtx) {
        abort();
    }
    mtx->r = m;
    mtx->c = n;
    if ((mtx->base = malloc(m * sizeof(elem_t*))) == NULL) {
        abort();
    }
    for (size_t i = 0; i < m; i++) {
        if ((mtx->base[i] = malloc(n * sizeof(elem_t))) == NULL) {
            abort();
        }
    }
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            mtx->base[i][j] = val;
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

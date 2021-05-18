#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {IV, IA, DV, DA} OpType;

#define INIT_DIMENSIONS 100
#define MAXLEN 100

typedef struct {
    int *base;
    size_t len;
    size_t capa;
} SqList;
typedef struct {
    SqList **rows;
    size_t len;
    size_t capa;
} Matrix;

SqList *InitSqList(size_t length) {
    SqList *sl = malloc(sizeof(SqList));
    sl->len = length;
    sl->capa = length > INIT_DIMENSIONS ? length : INIT_DIMENSIONS;
    sl->base = malloc(sl->capa * sizeof(int));
    memset(sl->base, 0, sl->capa * sizeof(int));
    return sl;
}

Matrix *InitMatrix(size_t vtxamt) {
    Matrix *mtx = malloc(sizeof(Matrix));
    mtx->len = vtxamt;
    mtx->capa = vtxamt > INIT_DIMENSIONS ? vtxamt : INIT_DIMENSIONS;
    mtx->rows = malloc(mtx->capa * sizeof(SqList*));
    for (size_t i = 0; i < mtx->len; i++) {
        mtx->rows[i] = InitSqList(mtx->len);
    }
    return mtx;
}

OpType Decode(char *line, int *operand1, int *operand2) {
    char *token[3];
    token[0] = strtok(line, " ");
    token[1] = strtok(NULL, " ");
    token[2] = strtok(NULL, " ");
    if (token[0][1] == 'V') {
        *operand1 = atoi(token[1]);
        return token[0][0] == 'I' ? IV : DV;
    } else {
        *operand1 = atoi(token[1]);
        *operand2 = atoi(token[2]);
        return token[0][0] == 'I' ? IA : DA;
    }
}

void InsertVex(Matrix *mtx, int v) {
    if (v < 0 || v > mtx->len) {
        return;
    }
    for (size_t i = 0; i < mtx->len; i++) {
        if (mtx->rows[i]->len + 1 >= mtx->rows[i]->capa) {
            mtx->rows[i]->capa <<= 1;
            mtx->rows[i]->base = realloc(mtx->rows[i]->base, mtx->rows[i]->capa);
        }
        for (size_t j = mtx->rows[i]->len; j > v; j--) {
            mtx->rows[i]->base[j] = mtx->rows[i]->base[j - 1];
        }
        mtx->rows[i]->base[v] = 0;
        mtx->rows[i]->len++;
    }
    if (mtx->len + 1 >= mtx->capa) {
        mtx->capa <<= 1;
        mtx->rows = realloc(mtx->rows, mtx->capa);
    }
    for (size_t i = mtx->len; i > v; i--) {
        mtx->rows[i] = mtx->rows[i - 1];
    }
    mtx->len++;
    mtx->rows[v] = InitSqList(mtx->len);
}

void InsertArc(Matrix *mtx, int v, int w) {
    if (v < 0 || v >= mtx->len || w < 0 || w >= mtx->rows[0]->len) {
        return;
    }
    mtx->rows[v]->base[w] = mtx->rows[w]->base[v] = 1;
}

void DeleteVex(Matrix *mtx, int v) {
    if (v < 0 || v > mtx->len) {
        return;
    }
    for (size_t i = 0; i < mtx->len; i++) {
        for (size_t j = v; j < mtx->rows[i]->len; j++) {
            mtx->rows[i]->base[j - 1] = mtx->rows[i]->base[j];
        }
        mtx->rows[i]->len--;
    }
    for (size_t i = v; i < mtx->len; i++) {
        mtx->rows[i - 1] = mtx->rows[i];
    }
    mtx->len--;
}

void DeleteArc(Matrix *mtx, int v, int w) {
    if (v < 0 || v >= mtx->len || w < 0 || w >= mtx->rows[0]->len) {
        return;
    }
    mtx->rows[v]->base[w] = mtx->rows[w]->base[v] = 0;
}

void PrintMatrix(Matrix *mtx) {
    for (size_t i = 0; i < mtx->len; i++) {
        for (size_t j = 0; j < mtx->rows[i]->len; j++) {
            printf("%d%c", mtx->rows[i]->base[j], j == mtx->rows[i]->len - 1 ? '\n' : ' ');
        }
    }
}

int main() {
    Matrix *mtx;
    size_t vtxamt;
    scanf("%ld", &vtxamt);
    mtx = InitMatrix(vtxamt);
    for (size_t i = 0; i < mtx->len; i++) {
        for (size_t j = 0; j < mtx->rows[i]->len; j++) {
            scanf("%d", mtx->rows[i]->base + j);
        }
    }
    for (char c = getchar(); c != '\n'; c = getchar()) {}

    char line[MAXLEN];
    int para1, para2;
    OpType op;
    while (fgets(line, MAXLEN, stdin)) {
        op = Decode(line, &para1, &para2);
        switch (op) {
            case IV:
                InsertVex(mtx, para1);
                break;
            case IA:
                InsertArc(mtx, para1, para2);
                break;
            case DV:
                DeleteVex(mtx, para1);
                break;
            case DA:
                DeleteArc(mtx, para1, para2);
        }
    }
    PrintMatrix(mtx);
    return 0;
}

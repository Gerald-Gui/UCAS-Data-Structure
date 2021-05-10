#include "MGraph.h"
#include <stdlib.h>
#include <stdbool.h>

MGraph *InitGraph(size_t vexnum, GraphKind k) {
    MGraph *G = malloc(sizeof(MGraph));
    if (G == NULL) {
        abort();
    }
    G->vnum = vexnum;
    G->anum = 0;
    G->kind = k;
    G->vexs = malloc(G->vnum * sizeof(vex_t));
    if (G->vexs == NULL) {
        abort();
    }
    switch (G->kind) {
        case UDG:
        case DG:
            G->arcs = InitMatrix(G->vnum, G->vnum, 0);
            break;
        case UDN:
        case DN:
            G->arcs = InitMatrix(G->vnum, G->vnum, INFTY);
            for (size_t i = 0; i < G->vnum; i++) {
                G->arcs->base[i][i] = 0;
            }
            break;
    }
    return G;
}

MGraph *DestroyMGraph(MGraph *G) {
    G->arcs = DestroyMatrix(G->arcs);
    free(G->vexs);
    free(G);
    return NULL;
}

void InsertArc(MGraph *G, arc_t a) {
    if (a.head == a.tail) {
        return;
    }
    elem_t tar = G->kind == UDG || G->kind == DG ? 0 : INFTY;
    if (G->arcs->base[a.head][a.tail] == tar) {
        G->anum++;
    }
    switch (G->kind) {
        case UDG:
            G->arcs->base[a.tail][a.head] = 1;
        case DG:
            G->arcs->base[a.head][a.tail] = 1;
            break;
        case UDN:
            G->arcs->base[a.tail][a.head] = a.weight;
        case DN:
            G->arcs->base[a.head][a.tail] = a.weight;
            break;
    }
}

void DeleteArc(MGraph *G, arc_t a) {
    if (a.head == a.tail) {
        return;
    }
    elem_t tar = G->kind == UDG || G->kind == DG ? 0 : INFTY;
    if (G->arcs->base[a.head][a.tail] != tar) {
        G->anum--;
    }
    switch (G->kind) {
        case UDG:
        case UDN:
            G->arcs->base[a.tail][a.head] = tar;
        case DG:
        case DN:
            G->arcs->base[a.head][a.tail] = tar;
    }
}

size_t CountArc(arc_t *arr, MGraph *G) {
    size_t cnt = 0;
    bool is_undirected = G->kind == UDN || G->kind == UDG;
    if ((arr = malloc(G->anum * sizeof(arc_t))) == NULL) {
        abort();
    }
    for (size_t v = 0; v < G->vnum; v++) {
        for (size_t w = is_undirected ? v + 1 : 0; w < G->vnum; w++) {
            if (G->arcs->base[v][w] != is_undirected ? 0 : INFTY) {
                arr[cnt++] = (arc_t){v, w};
            }
        }
    }
    return cnt;
}

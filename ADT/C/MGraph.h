#ifndef M_GRAPH_H
#define M_GRAPH_H

#include "Matrix.h"

typedef enum {UDG, DG, UDN, DN} GraphKind;
typedef unsigned int vex_t;
typedef struct {
    elem_t head;
    elem_t tail;
    elem_t weight;
} arc_t;
typedef struct {
    size_t vnum, anum;
    GraphKind kind;
    vex_t *vexs;
    matrix_t *arcs;
} MGraph;

const int INFTY = 100000;

MGraph *InitGraph(size_t vexnum, GraphKind k);
MGraph *DestroyMGraph(MGraph *G);
void InsertArc(MGraph *G, arc_t a);
void DeleteArc(MGraph *G, arc_t a);
size_t CountArc(arc_t *arr, MGraph *G);

#endif

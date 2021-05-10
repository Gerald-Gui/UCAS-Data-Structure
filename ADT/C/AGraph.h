#ifndef A_GRAPH_H
#define A_GRAPH_H

#include "stddef.h"

typedef enum {UDG, DG, UDN, DN} GraphKind;
typedef char vtx_t;         //vertex info
typedef unsigned int arc_t; //arc info
typedef struct ListNode {
    size_t index;
    arc_t info;
    struct ListNode *nxt;
} ListNode;
typedef struct {
    vtx_t info;
    ListNode *nxt;
} VertexNode;

typedef struct {
    size_t vtx_amt;
    size_t arc_amt;
    GraphKind kind;
    VertexNode *vtxs;
} AGraph;

AGraph *InitAGraph(size_t vtxnum, GraphKind k);
AGraph *DestroyAGraph(AGraph *G);

// support funcs for LinkList
ListNode *NewListNode(size_t vtx, arc_t info, ListNode *nxt);

#endif

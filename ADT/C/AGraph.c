#include "AGraph.h"
#include <stdlib.h>

//graph ops

AGraph *InitAGraph(size_t vtxnum, GraphKind k) {
    AGraph *G = malloc(sizeof(AGraph));
    if (G == NULL) {
        abort();
    }
    G->vtx_amt = vtxnum;
    G->arc_amt = 0;
    G->kind = k;
    if ((G->vtxs = malloc(G->vtx_amt * sizeof(VertexNode))) == NULL) {
        abort();
    }
    for (size_t i = 0; i < G->vtx_amt; i++) {
        // G->vtxs[i].info;
        G->vtxs[i].nxt = NULL;
    }
}

AGraph *DestroyAGraph(AGraph *G) {
    ListNode *p = NULL;
    for (size_t i = 0; i < G->vtx_amt; i++) {
        p = G->vtxs[i].nxt;
        while (p != NULL) {
            G->vtxs[i].nxt = p->nxt;
            free(p);
            p = G->vtxs[i].nxt;
        }
    }
    free(G->vtxs);
    free(G);
    return NULL;
}

// head insertion
void InsertArc(AGraph *G, Arc a) {
    switch (G->kind) {
        case UDG:
            G->vtxs[a.tail].nxt = NewListNode(a.head, 1, G->vtxs[a.tail].nxt);
        case DG:
            G->vtxs[a.head].nxt = NewListNode(a.tail, 1, G->vtxs[a.head].nxt);
            break;
        case UDN:
            G->vtxs[a.tail].nxt = NewListNode(a.head, a.weight, G->vtxs[a.tail].nxt);
        case DN:
            G->vtxs[a.head].nxt = NewListNode(a.tail, a.weight, G->vtxs[a.head].nxt);
    }
    G->arc_amt++;
}

void DeleteArc(AGraph *G, Arc a) {
    switch (G->kind) {
        case UDG:
        case UDN:
            DeleteListNode(a.head, G->vtxs[a.tail].nxt);
        case DG:
        case DN:
            DeleteListNode(a.tail, G->vtxs[a.tail].nxt);
    }
    G->arc_amt--;
}

size_t CountArcs(Arc *arr, AGraph *G) {
    size_t cnt = 0;
    if ((arr = malloc(G->arc_amt * sizeof(Arc))) == NULL) {
        abort();
    }
    for (size_t v = 0; v < G->vtx_amt; v++) {
        for (ListNode *p = G->vtxs[v].nxt; p != NULL; p = p->nxt) {
            if ((G->kind == UDG || G->kind == UDN) && p->index > v) {
                arr[cnt++] = NewArc(v, p->index, p->info);
            } else if (G->kind == DG || G->kind == DN) {
                arr[cnt++] = NewArc(v, p->index, p->info);
            }
        }
    }
}

//
// ===========================================================
//
// support funcs
//
ListNode *NewListNode(size_t vtx, arc_t info, ListNode *nxt) {
    ListNode *p = malloc(sizeof(ListNode));
    if (p == NULL) {
        abort();
    }
    p->index = vtx;
    p->info  = info;
    p->nxt   = nxt;
    return p;
}

void DeleteListNode(size_t tar, ListNode *first) {
    ListNode *head = NewListNode(0, 0, first);
    ListNode *p = first, *pre = head;
    while (p->index != tar) {
        p = p->nxt;
        pre = pre->nxt;
    }
    pre->nxt = p->nxt;
    free(p);
    free(head);
}

inline Arc NewArc(size_t head, size_t tail, size_t weight) {
    return (Arc){head, tail, weight};
}

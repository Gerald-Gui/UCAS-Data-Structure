#include "AGraph.h"
#include <stdlib.h>

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

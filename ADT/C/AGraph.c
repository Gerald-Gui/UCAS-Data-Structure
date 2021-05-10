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

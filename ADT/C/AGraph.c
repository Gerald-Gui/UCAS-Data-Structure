#include "AGraph.h"
#include <stdlib.h>
#include <string.h>

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
    return cnt;
}

void DFSGraph(AGraph *G, bool (*visit)(vtx_t v)) {
    bool *visited = malloc(G->vtx_amt * sizeof(bool));
    if (visited == NULL) {
        abort();
    }
    memset(visited, 0, G->vtx_amt * sizeof(bool));
    for (size_t i = 0; i < G->vtx_amt; i++) {
        if (!visited[i]) {
            DFS(G, i, visited, visit);
        }
    }
    free(visited);
}

void DFS(AGraph *G, size_t x, bool *visited, bool (*visit)(vtx_t v)) {
    ListNode *p = G->vtxs[x].nxt;
    visited[x] = true;
    (*visit)(G->vtxs[x].info);
    while (p != NULL) {
        if (!visited[p->index]) {
            DFS(G, p->index, visited, visit);
        }
        p = p->nxt;
    }
}

void BFS(AGraph *G, bool (*func)(vtx_t v)) {
    size_t u;
    ListNode *p = NULL;
    Queue *que = InitQueue();
    bool *visited = malloc(G->vtx_amt * sizeof(bool));
    if (visited == NULL) {
        abort();
    }
    memset(visited, 0, G->vtx_amt * sizeof(bool));
    for (size_t v = 0; v < G->vtx_amt; v++) {
        if (!visited[v]) {
            visited[v] = true;
            (*func)(G->vtxs[v].info);
            EnQueue(que, v);
            while (!QueueIsEmpty(que)) {
                u = DeQueue(que);
                for (p = G->vtxs[u].nxt; p != NULL; p = p->nxt) {
                    if (!visited[p->index]) {
                        visited[p->index];
                        (*func)(G->vtxs[p->index].info);
                        EnQueue(que, p->index);
                    }
                }
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

QNode *NewQNode(size_t elem, QNode *ptr) {
    QNode *p = malloc(sizeof(QNode));
    if (p == NULL) {
        abort();
    }
    p->val = elem;
    p->nxt = ptr;
    return p;
}

Queue *InitQueue(void) {
    Queue *que = malloc(sizeof(Queue));
    if (que == NULL) {
        abort();
    }
    que->front = que->rear = NewQNode(0, NULL);
    return que;
}

void EnQueue(Queue *que, size_t elem) {
    QNode *p = NewQNode(elem, NULL);
    que->rear->nxt = p;
    que->rear = p;
}

size_t DeQueue(Queue *que) {
    size_t ret = que->front->nxt->val;
    QNode *p = que->front;
    que->front = p->nxt;
    free(p);
    return ret;
}

inline bool QueueIsEmpty(Queue *que) {
    return que->front == que->rear;
}

Queue *DestroyQueue(Queue *que) {
    QNode *p = que->front;
    while (!QueueIsEmpty(que)) {
        que->front = p->nxt;
        free(p);
        p = que->front;
    }
    free(p);
    free(que);
    return NULL;
}

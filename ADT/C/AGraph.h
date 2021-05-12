#ifndef A_GRAPH_H
#define A_GRAPH_H

#include <stddef.h>
#include <stdbool.h>

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
    size_t head;
    size_t tail;
    size_t weight;
} Arc;

typedef struct {
    size_t vtx_amt;
    size_t arc_amt;
    GraphKind kind;
    VertexNode *vtxs;
} AGraph;

AGraph *InitAGraph(size_t vtxnum, GraphKind k);
AGraph *DestroyAGraph(AGraph *G);
void InsertArc(AGraph *G, Arc a);
void DeleteArc(AGraph *G, Arc a);
size_t CountArcs(Arc *arr, AGraph *G);
void DFSGraph(AGraph *G, bool (*func)(vtx_t v));
void DFS(AGraph *G, size_t x, bool *visited, bool (*func)(vtx_t v));
void BFS(AGraph *G, bool (*func)(vtx_t v));

// support funcs for LinkList
ListNode *NewListNode(size_t vtx, arc_t info, ListNode *nxt);
void DeleteListNode(size_t tar, ListNode *first);
Arc NewArc(size_t head, size_t tail, size_t weight);
typedef struct QueueNode {
    size_t val;
    struct QueueNode *nxt;
} QNode;
typedef struct {
    QNode *front;
    QNode *rear;
} Queue;
QNode *NewQNode(size_t elem, QNode *ptr);
Queue *InitQueue(void);
void EnQueue(Queue *que, size_t elem);
size_t DeQueue(Queue *que);
bool QueueIsEmpty(Queue *que);
Queue *DestroyQueue(Queue *que);

#endif

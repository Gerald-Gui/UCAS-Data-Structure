#ifndef LINK_DEQUE_H
#define LINK_DEQUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef int elem_t;
typedef struct DuListNode {
    elem_t val;
    struct DuListNode *nxt;
    struct DuListNode *pre;
} DuListNode;
typedef struct {
    DuListNode *head;
} LinkDeque;

DuListNode *MakeDuListNode(elem_t e, DuListNode *next, DuListNode *prior);
DuListNode *MakeEmptyDuListNode(DuListNode *next, DuListNode *prior);

LinkDeque *InitLinkDeque();
LinkDeque *DestroyLinkDeque(LinkDeque *deq);
void ClearLinkDeque(LinkDeque *deq);
size_t LinkDequeSize(LinkDeque *deq);
bool IsLinkDequeEmpty(LinkDeque *deq);
void PushBack_L(LinkDeque *deq, elem_t e);
void PopBack_L(LinkDeque *deq);
void PushFront_L(LinkDeque *deq, elem_t e);
void PopFront_L(LinkDeque *deq);
elem_t *GetFront_L(LinkDeque *deq);
elem_t *GetBack_L(LinkDeque *deq);

#endif

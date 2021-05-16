#include "LinkDeque.h"

DuListNode *MakeDuListNode(elem_t e, DuListNode *next, DuListNode *prior) {
    DuListNode *p = malloc(sizeof(DuListNode));
    if (p == NULL) {
        abort();
    }
    p->val = e;
    p->nxt = next;
    p->pre = prior;
    return p;
}

DuListNode *MakeEmptyDuListNode(DuListNode *next, DuListNode *prior) {
    DuListNode *p = malloc(sizeof(DuListNode));
    if (p == NULL) {
        abort();
    }
    p->nxt = next;
    p->pre = prior;
    return p;
}


LinkDeque *InitLinkDeque() {
    LinkDeque *deq = malloc(sizeof(LinkDeque));
    if (deq == NULL) {
        abort();
    }
    deq->head = MakeEmptyDuListNode(NULL, NULL);
    deq->head->nxt = deq->head->pre = deq->head;
    return deq;
}

LinkDeque *DestroyLinkDeque(LinkDeque *deq) {
    if (deq == NULL) {
        return NULL;
    }
    if (deq->head == NULL) {
        free(deq);
        return NULL;
    }
    ClearLinkDeque(deq);
    free(deq->head);
    free(deq);
    return NULL;
}

void ClearLinkDeque(LinkDeque *deq) {
    while (!IsLinkDequeEmpty(deq)) {
        PopFront_L(deq);
    }
}

size_t LinkDequeSize(LinkDeque *deq) {
    size_t cnt = 0;
    DuListNode *p = deq->head->nxt;
    while (p != deq->head) {
        cnt++;
        p = p->nxt;
    }
    return cnt;
}

inline bool IsLinkDequeEmpty(LinkDeque *deq) {
    if (deq == NULL || deq->head == NULL) {
        return false;
    }
    return deq->head == deq->head->nxt;
}

void PushBack_L(LinkDeque *deq, elem_t e) {
    DuListNode *p = MakeDuListNode(e, deq->head->pre, deq->head);
    deq->head->pre->nxt = p;
    deq->head->pre = p;
}

void PopBack_L(LinkDeque *deq) {
    DuListNode *p = deq->head->pre;
    p->pre->nxt = deq->head;
    deq->head->pre = p->pre;
    free(p);
}

void PushFront_L(LinkDeque *deq, elem_t e) {
    DuListNode *p = MakeDuListNode(e, deq->head, deq->head->nxt);
    deq->head->nxt->pre = p;
    deq->head->nxt = p;
}

void PopFront_L(LinkDeque *deq) {
    DuListNode *p = deq->head->nxt;
    deq->head->nxt = p->nxt;
    p->nxt->pre = deq->head;
    free(p);
}

inline elem_t *GetFront_L(LinkDeque *deq) {
    if (deq == NULL || deq->head == NULL || deq->head->nxt == NULL) {
        return NULL;
    }
    return &deq->head->nxt->val;
}

inline elem_t *GetBack_L(LinkDeque *deq) {
    if (deq == NULL || deq->head == NULL || deq->head->pre == NULL) {
        return NULL;
    }
    return &deq->head->pre->val;
}


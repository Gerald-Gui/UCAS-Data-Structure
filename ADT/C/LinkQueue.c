#include <stdlib.h>
#include "LinkQueue.h"

Status InitQueue_L(LinkQueue * Q){
    Q->rear = Q->front = malloc(sizeof(ListNode));
}

Status DestroyQueue_L(LinkQueue * Q){
    ClearQueue_L(Q);
    free(Q->front);
    Q->front = Q->rear = NULL;
    return OK;
}

void ClearQueue_L(LinkQueue * Q){
    ElemType e;
    while(DeQueue_L(Q, &e))
        ;
}

inline Status IsQueueEmpty_L(LinkQueue Q){
    return Q.front == Q.rear;
}

int QueueLength_L(LinkQueue Q){
    ListNode * p = Q.front;
    int cnt;
    for(cnt = 0; p != Q.rear; p = p->nxt)
        cnt++;
    return cnt;
}

Status GetHead_L(LinkQueue Q, ElemType * e){
    if(IsQueueEmpty_L(Q))
        return ERROR;
    *e = Q.front->nxt->val;
    return OK;
}

Status EnQueue_L(LinkQueue * Q, ElemType e){
    Q->rear->nxt = malloc(sizeof(ListNode));
    if(Q->rear->nxt == NULL)
        exit(OVERFLOW);
    Q->rear = Q->rear->nxt;
    Q->rear->val = e;
    Q->rear->nxt = NULL;
    return OK;
}

Status DeQueue_L(LinkQueue * Q, ElemType * e){
    if(Q->front == Q->rear)
        return ERROR;
    *e = Q->front->nxt->val;
    ListNode * p = Q->front;
    Q->front = Q->front->nxt;
    free(p);
    p = NULL;
    return OK;
}

Status QueueTraverse_L(LinkQueue Q, Status (*visit)(ElemType e)){
    for(ListNode * p = Q.front->nxt; p != NULL; p = p->nxt)
        if(!(*visit)(p->val))
            return ERROR;
    return OK;
}

#include <stdlib.h>
#include "SqQueue.h"

Status InitQueue_Sq(SqQueue * Q){
    Q->data = malloc(MAX_QUEUE_SIZE * sizeof(ElemType));
    if(Q->data == NULL)
        exit(OVERFLOW);
    Q->front = Q->rear = 0;
    return OK;
}

Status DestroyQueue_Sq(SqQueue * Q){
    free(Q->data);
    Q->data = NULL;
    Q->front = Q->rear = 0;
    return OK;
}

void ClearQueue_Sq(SqQueue * Q){
    Q->front = Q->rear = 0;
}

inline Status IsQueueEmpty_Sq(SqQueue Q){
    return Q.front == Q.rear;
}

inline int QueueLength_Sq(SqQueue Q){
    return (Q.rear - Q.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Status GetHead_Sq(SqQueue Q, ElemType * e){
    if(IsQueueEmpty(Q))
        return ERROR;
    *e = Q.data[Q.front];
    return OK;
}

Status EnQueue_Sq(SqQueue * Q, ElemType e){
    if((Q->rear + 1) % MAX_QUEUE_SIZE == Q->front)
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
    return OK;
}

Status DeQueue_Sq(SqQueue * Q, ElemType * e){
    if(Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
    return OK;
}

Status QueueTraverse_Sq(SqQueue Q, Status (*visit)(ElemType e)){
    while(Q.front != Q.rear){
        if(!(*visit)(Q.data[Q.front]))
            return ERROR;
        Q.front++;
        Q.front %= MAX_QUEUE_SIZE;
    }
    return OK;
}

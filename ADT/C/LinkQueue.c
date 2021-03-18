#include <stdlib.h>

#define OK      1
#define ERROR   0
#define OVERFLOW    -1

typedef int Status;
typedef int ElemType;
typedef struct ListNode{
    ElemType val;
    struct ListNode * nxt;
} ListNode;
typedef struct LinkQueue{
    ListNode * front;
    ListNode * rear;
} LinkQueue;

//initialize an empty queue
Status InitQueue_L(LinkQueue * Q);
//destroy queue Q
Status DestroyQueue_L(LinkQueue * Q);
//set queue Q empty
void ClearQueue_L(LinkQueue * Q);
//judge whether queue Q is empty
inline Status IsQueueEmpty_L(LinkQueue Q);
//return the num of elems in queue Q
int QueueLength_L(LinkQueue Q);
//return the head elem of Q with e
Status GetHead_L(LinkQueue Q, ElemType * e);
//insert new elem e to tail of Q
Status EnQueue_L(LinkQueue * Q, ElemType e);
//delete head elem of Q and return it with e
Status DeQueue_L(LinkQueue * Q, ElemType * e);
//call func visit() from front to rear
Status QueueTraverse_L(LinkQueue Q, Status (*visit)(ElemType e));

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

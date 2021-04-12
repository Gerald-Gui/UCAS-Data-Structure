#ifndef _LINK_QUEUE_H
#define _LINK_QUEUE_H

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

#endif
#ifndef _SEQUENT_QUEUE_H
#define _SEQUENT_QUEUE_H

#define MAX_QUEUE_SIZE 100

#define OK      1
#define ERROR   0
#define OVERFLOW    -1

typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType * data;
    int front;
    int rear;
} SqQueue;

//initialize an empty queue
Status InitQueue_Sq(SqQueue * Q);
//destroy queue Q
Status DestroyQueue_Sq(SqQueue * Q);
//set queue Q empty
void ClearQueue_Sq(SqQueue * Q);
//judge whether queue Q is empty
inline Status IsQueueEmpty_Sq(SqQueue Q);
//return the num of elems in queue Q
inline int QueueLength_Sq(SqQueue Q);
//return the head elem of Q with e
Status GetHead_Sq(SqQueue Q, ElemType * e);
//insert new elem e to tail of Q
Status EnQueue_Sq(SqQueue * Q, ElemType e);
//delete head elem of Q and return it with e
Status DeQueue_Sq(SqQueue * Q, ElemType * e);
//call func visit() from front to rear
Status QueueTraverse_Sq(SqQueue Q, Status (*visit)(ElemType e));

#endif
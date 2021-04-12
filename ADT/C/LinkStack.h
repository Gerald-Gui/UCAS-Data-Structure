#ifndef _LINK_STACK_H
#define _LINK_STACK_H

#define OK      1
#define ERROR   0
#define OVERFLOW    -1

typedef int Status;
typedef int ElemType;
typedef struct ListNode{
    ElemType val;
    struct ListNode * nxt;
} ListNode;

typedef struct{
    ListNode * top;
    int len;
} LinkStack;

//initialize an empty stack
Status InitStack_L(LinkStack * S);
//judge whether stack S is empty
inline Status IsStackEmpty_L(LinkStack S);
//push elem into stack
Status Push_L(LinkStack * S, ElemType e);
//delete the top elem and return it with e if stack is not empty
Status Pop_L(LinkStack * S, ElemType * e);
//set stack S empty
void ClearStack_L(LinkStack * S);
//destroy stack S
Status DestroyStack_L(LinkStack * S);
//return the head elem with e if stack is not empty
Status GetTop_L(LinkStack S, ElemType * e);
//call func visit() from botton to top
Status StackTraverse_L(LinkStack S, Status (*visit)(ElemType e));

#endif
#include <stdlib.h>
#include "LinkStack.h"

Status InitStack_L(LinkStack * S){
    S->top = NULL;
    S->len = 0;
}

inline Status IsStackEmpty_L(LinkStack S){
    return S.top == NULL;
}

Status Push_L(LinkStack * S, ElemType e){
    ListNode * p = malloc(sizeof(ListNode));
    if(p == NULL)
        exit(OVERFLOW);
    p->val = e;
    p->nxt = S->top;
    S->top = p;
    S->len++;
    return OK;
}

Status Pop_L(LinkStack * S, ElemType * e){
    ListNode * p = S->top;
    if(IsStackEmpty(*S))
        return ERROR;
    *e = p->val;
    S->top = S->top->nxt;
    free(p);
    p = NULL;
    S->len--;
    return OK;
}

void ClearStack_L(LinkStack * S){
    ElemType e;
    while(Pop(S, &e))
        ;
}

Status DestroyStack_L(LinkStack * S){
    ClearStack(S);
}

Status GetTop_L(LinkStack S, ElemType * e){
    if(IsStackEmpty(S))
        return ERROR;
    *e = S.top->val;
    return OK;
}

Status StackTraverse_L(LinkStack S, Status (*visit)(ElemType e)){
    if(IsStackEmpty(S))
        return OK;
    LinkStack nxtS;
    nxtS.top = S.top->nxt;
    nxtS.len = S.len - 1;
    if(!StackTraverse(nxtS, visit))
        return ERROR;
    if(!(*visit)(S.top->val))
        return ERROR;
}
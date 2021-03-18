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

typedef struct{
    ListNode * top;
    int len;
} LinkStack;

//initialize an empty stack
Status InitStack(LinkStack * S){
    S->top = NULL;
    S->len = 0;
}

//judge whether stack S is empty
inline Status IsStackEmpty(LinkStack S){
    return S.top == NULL;
}

//push elem into stack
Status Push(LinkStack * S, ElemType e){
    ListNode * p = malloc(sizeof(ListNode));
    if(p == NULL)
        exit(OVERFLOW);
    p->val = e;
    p->nxt = S->top;
    S->top = p;
    S->len++;
    return OK;
}

//delete the top elem and return it with e if stack is not empty
Status Pop(LinkStack * S, ElemType * e){
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

//set stack S empty
void ClearStack(LinkStack * S){
    ElemType e;
    while(Pop(S, &e))
        ;
}

//destroy stack S
Status DestroyStack(LinkStack * S){
    ClearStack(S);
}

//return the head elem with e if stack is not empty
Status GetTop(LinkStack S, ElemType * e){
    if(IsStackEmpty(S))
        return ERROR;
    *e = S.top->val;
    return OK;
}

//call func visit() from botton to top
Status StackTraverse(LinkStack S, Status (*visit)(ElemType e)){
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
#include <stdlib.h>
#include "SqStack.h"

Status InitStack_Sq(SqStack * S){
    S->data = malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(S->data == NULL)
        exit(OVERFLOW);
    S->top = 0;
    S->size = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack_Sq(SqStack * S){
    free(S->data);
    S->data = NULL;
    S->top = S->size = 0;
    return OK;
}

void ClearStack_Sq(SqStack * S){
    S->top = 0;
}

inline Status IsStackEmpty_Sq(SqStack S){
    return S.top == 0;
}

Status GetTop_Sq(SqStack S, ElemType * e){
    if(IsStackEmpty(S))
        return ERROR;
    *e = S.data[S.top - 1];
    return OK;
}

Status Push_Sq(SqStack * S, ElemType e){
    if(S->top >= S->size){
        S->data = realloc(S->data, (S->size + STACKINCREMENT) * sizeof(ElemType));
        if(S->data == NULL)
            exit(OVERFLOW);
        S->top = S->size;
        S->size += STACKINCREMENT;
    }
    S->data[S->top++] = e;
    return OK;
}

Status Pop_Sq(SqStack * S, ElemType * e){
    if(IsStackEmpty(*S))
        return ERROR;
    *e = S->data[--S->top];
    return OK;
}

Status StackTraverse_Sq(SqStack S, Status (*visit)(ElemType e)){
    for(int i = 0; i < S.top; i++)
        if(!(*visit)(S.data[i]))
            return ERROR;
    return OK;
}
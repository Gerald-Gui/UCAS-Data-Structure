#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

#define OK      1
#define ERROR   0
#define OVERFLOW    -1

typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType * data;
    int top;
    int size;
} SqStack;

//initialize an empty stack
Status InitStack_Sq(SqStack * S){
    S->data = malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(S->data == NULL)
        exit(OVERFLOW);
    S->top = 0;
    S->size = STACK_INIT_SIZE;
    return OK;
}

//destroy stack S
Status DestroyStack_Sq(SqStack * S){
    free(S->data);
    S->data = NULL;
    S->top = S->size = 0;
    return OK;
}

//set stack S empty
void ClearStack_Sq(SqStack * S){
    S->top = 0;
}

//judge whether stack S is empty
inline Status IsStackEmpty_Sq(SqStack S){
    return S.top == 0;
}

//return the head elem with e if stack isn't empty
Status GetTop_Sq(SqStack S, ElemType * e){
    if(IsStackEmpty(S))
        return ERROR;
    *e = S.data[S.top - 1];
    return OK;
}

//push elem into stack
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

//delete the top elem and return it with e if stack is not empty
Status Pop_Sq(SqStack * S, ElemType * e){
    if(IsStackEmpty(*S))
        return ERROR;
    *e = S->data[--S->top];
    return OK;
}

//call func visit() from bottom to top
Status StackTraverse_Sq(SqStack S, Status (*visit)(ElemType e)){
    for(int i = 0; i < S.top; i++)
        if(!(*visit)(S.data[i]))
            return ERROR;
    return OK;
}
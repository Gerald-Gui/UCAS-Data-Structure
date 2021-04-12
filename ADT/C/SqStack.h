#ifndef _SEQUENT_STACK_H
#define _SEQUENT_STACK_H

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
Status InitStack_Sq(SqStack * S);
//destroy stack S
Status DestroyStack_Sq(SqStack * S);
//set stack S empty
void ClearStack_Sq(SqStack * S);
//judge whether stack S is empty
inline Status IsStackEmpty_Sq(SqStack S);
//return the head elem with e if stack isn't empty
Status GetTop_Sq(SqStack S, ElemType * e);
//push elem into stack
Status Push_Sq(SqStack * S, ElemType e);
//delete the top elem and return it with e if stack is not empty
Status Pop_Sq(SqStack * S, ElemType * e);
//call func visit() from bottom to top
Status StackTraverse_Sq(SqStack S, Status (*visit)(ElemType e));

#endif
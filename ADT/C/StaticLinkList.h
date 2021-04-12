#ifndef _STATIC_LINK_LIST_H
#define _STATIC_LINK_LIST_H

#define OK      1
#define ERROR   0
#define OVERFLOW    -1

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType data;
    int cur;
} SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList space);
void Free_SL(SLinkList space, int k);
int Malloc_SL(SLinkList space);
int LocateElem_SL(SLinkList S, ElemType e);

#endif
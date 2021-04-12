#include <stdio.h>
#include <stdlib.h>
#include "StaticLinkList.h"

void InitSpace_SL(SLinkList space){
    int i;
    for(i = 0; i < MAXSIZE - 1;)
        space[i].cur = ++i;
    space[i].cur = 0;
}

void Free_SL(SLinkList space, int k){
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int Malloc_SL(SLinkList space){
    int i = space[0].cur;
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

int LocateElem_SL(SLinkList S, ElemType e){
    int i = S[0].cur;
    while(i != 0 && S[i].data != e)
        i = S[i].cur;
    return i;
}

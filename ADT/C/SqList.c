#include <stdlib.h>

//--------Status macros--------
#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define INFEASIBLE  -1
#define OVERFLOW    -2

//------------Types------------
typedef int Status;
typedef int Elemtype;
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef struct{
    Elemtype * elem;
    int length;
    int listsize;
} SqList;


//--------Function List--------

    //initialize sequent list
Status InitList_Sq(SqList * L);
    //destroy list
Status DestroyList_Sq(SqList * L);
    //set the list empty
void ClearList_Sq(SqList * L);
    //judge whether the list is empty
Status ListEmpty_Sq(SqList * L);
    //return the length of the list
int ListLength_Sq(SqList * L);
    //use e to return the ith element of list
Status GetElem_Sq(SqList * L, int i, Elemtype * e);
    //return the order of the first element meet cmp()
int LocateElem_Sq(SqList * L, Elemtype e, int (*cmp)(Elemtype data, Elemtype e));
    //use prior to return the former element of cur
Status PriorElem_Sq(SqList * L, Elemtype cur, Elemtype * prior);
    //use next to return the latter element of cur
Status NextElem_Sq(SqList * L, Elemtype cur, Elemtype * next);
    //insert e before the ith element
Status ListIns_Sq(SqList * L, int i, Elemtype e);
    //delete the ith element and return it with e
Status ListDel_Sq(SqList * L, int i, Elemtype * e);
    //merge two descending SqList to a new descending SqList
void MergeList_Sq(SqList La, SqList Lb, SqList * Lc);

//----------Function-----------

Status InitList_Sq(SqList * L){
    L->elem = (Elemtype *)malloc(LIST_INIT_SIZE * sizeof(Elemtype));
    if(L->elem == NULL)
        exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

Status DestroyList_Sq(SqList * L){
    if(L->listsize == 0)
        return OK;
    free(L->elem);
    L->length = 0;
    L->listsize = 0;
    return OK;
}

void ClearList_Sq(SqList * L){
    L->length = 0;
}

Status ListEmpty_Sq(SqList * L){
    return L->length == 0;
}

int ListLength_Sq(SqList * L){
    return L->length;
}

Status GetElem_Sq(SqList * L, int i, Elemtype * e){
    if(i < 1 || i > L->length)
        return ERROR;
    *e = L->elem[i - 1];
    return OK;
}

int LocateElem_Sq(SqList * L, Elemtype e, int (*cmp)(Elemtype data, Elemtype e)){
    int cnt = 1;
    Elemtype * p = L->elem;
    while(cnt <= L->length && (*cmp)(*p++, e) != 0)
        cnt++;
    if(cnt <= L->length)
        return cnt;
    return 0;
}

Status PriorElem_Sq(SqList * L, Elemtype cur, Elemtype * prior){
    int i;
    for(i = 0; cur != L->elem[i] && i < L->length; i++)
        ;
    if(i == L->length || i == 0)
        return ERROR;
    *prior = L->elem[i - 1];
    return OK;
}

Status NextElem_Sq(SqList * L, Elemtype cur, Elemtype * next){
    int i;
    for(i = 0; cur != L->elem[i] && i < L->length; i++)
        ;
    if(i == L->length || i == L->length - 1)
        return ERROR;
    *next = L->elem[i + 1];
    return OK;
}

Status ListIns(SqList * L, int i, Elemtype e){
    if(i < 1 || i > L->length + 1)
        return ERROR;
    if(L->length >= L->listsize){
        Elemtype * newbase = realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(Elemtype));
        if(newbase == NULL)
            exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    Elemtype * q = &(L->elem[i - 1]);
    for(Elemtype * p = &(L->elem[L->length - 1]); p >= q; p--)
        *(p + 1) = *p;
    *q = e;
    L->length++;
    return OK;
}

Status ListDel(SqList * L, int i, Elemtype * e){
    if(i < 1 || i > L->length)
        return ERROR;
    Elemtype * p = &(L->elem[i - 1]);
    *e = *p;
    Elemtype * q = L->elem + L->length - 1;
    for(p++; p <= q; p++)
        *(p - 1) = *p;
    L->length--;
    return OK;
}

void MergeList_Sq(SqList La, SqList Lb, SqList * Lc){
    Elemtype * pa = La.elem, * pb = Lb.elem;
    Lc->listsize = Lc->length = La.length + Lb.length;
    Elemtype * pc = Lc->elem = malloc(Lc->listsize * sizeof(Elemtype));
    if(Lc->elem == NULL)
        exit(OVERFLOW);
    Elemtype * ta = La.elem + La.length - 1;
    Elemtype * tb = Lb.elem + Lb.length - 1;
    while(pa <= ta && pb <= tb)
        if(*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    while(pa <= ta)
        *pc++ = *pa++;
    while(pb <= tb)
        *pc++ = *pb++;
}

#ifndef _SEQUENT_LIST_H
#define _SEQUENT_LIST_H

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

#endif
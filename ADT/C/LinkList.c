#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

LinkNode * MakeNode(ElemType e){
    LinkNode * p = malloc(sizeof(LinkNode));
    if(p == NULL)
        exit(OVERFLOW);
    p->val = e;
    p->nxt = NULL;
    return p;
}

void FreeNode(LinkNode ** p){
    free(*p);
    *p = NULL;
}

Status InitList_L(LinkList * L){
    L->head = malloc(sizeof(LinkNode));
    if(L->head == NULL)
        exit(OVERFLOW);
    L->len = 0;
    L->head->nxt = NULL;
    return OK;
}

void HeadIns_L(LinkNode * head, LinkNode * s){
    s->nxt = head->nxt;
    head->nxt = s;
}

Status CreateList_L(LinkList * L, int n){
    int i;
    LinkNode * p = NULL;
    if(!InitList_L(L))
        return ERROR;
    for(i = n; i > 0; i--){
        p = malloc(sizeof(LinkNode));
        if(p == NULL)
            exit(OVERFLOW);
        scanf("%d", &p->val);
        HeadIns_L(L->head, p);
        L->len++;
    }
    //if build list in input order
    //p = L->head;
    //for(int i = 0; i < n; i++){
    //    p->nxt = malloc(sizeof(LinkNode));
    //    if(p->nxt == NULL)
    //        exit(OVERFLOW);
    //    scanf("%d", &p->nxt->val);
    //    p->nxt->nxt = NULL;
    //    p = p->nxt;
    //}
    return OK;
}

Status HeadDel_L(LinkNode * head, LinkNode ** q){
    if(head->nxt == NULL)
        return ERROR;
    *q = head->nxt;
    head->nxt = head->nxt->nxt;
    return OK;
}

Status ClearList_L(LinkList * L){
    LinkNode * p = NULL;
    while(HeadDel_L(L, &p))
        FreeNode(&p);
    L->len = 0;
    return OK;
}

Status DestroyList_L(LinkList * L){
    ClearList_L(L);
    FreeNode(&(L->head));
    free(L);
    L = NULL;
    return OK;
}

Status Append_L(LinkList L, LinkNode * s){
    LinkNode * p = L.head;
    while(p->nxt != NULL)
        p = p->nxt;
    p->nxt = s;
    return OK;
}

Status RemoveTail_L(LinkList * L, LinkNode ** q){
    if(L->len == 0)
        return ERROR;
    LinkNode * p = L->head;
    while(p->nxt->nxt != NULL)
        p = p->nxt;
    HeadDel_L(p, q);
    L->len--;
    return OK;
}

Status InsBefore_L(LinkList * L, LinkNode ** p, LinkNode * s){
    LinkNode * q = L->head;
    while(q->nxt != *p && q != NULL)
        q = q->nxt;
    if(q == NULL)
        return ERROR;
    HeadIns_L(q, s);
    *p = s;
    return OK;
}

LinkNode * GetLast_L(LinkList L){
    while(L.head->nxt != NULL)
        L.head = L.head->nxt;
    return L.head;
}

LinkNode * PriorPos_L(LinkList L, LinkNode * p){
    while(L.head->nxt != p && L.head->nxt != NULL)
        L.head = L.head->nxt;
    if(L.head->nxt != p)
        return NULL;
    return L.head;
}

Status LocatePos_L(LinkList L, int i, LinkNode ** p){
    int cnt = 0;
    while(L.head != NULL && cnt < i){
        L.head = L.head->nxt;
        cnt++;
    }
    if(L.head == NULL || cnt > i)
        return ERROR;
    *p = L.head;
    return OK;
}

LinkNode * LocateElem_L(LinkList L, ElemType e, Status (*cmp)(ElemType data, ElemType e)){
    if(L.len == 0)
        return NULL;
    while(!(*cmp)(L.head->nxt->val, e) && L.head->nxt != NULL)
        L.head = L.head->nxt;
    return L.head;
}

Status ListTraverse_L(LinkList L, Status (*visit)(ElemType data)){
    L.head = L.head->nxt;
    while(L.head != NULL){
        if(!(*visit)(L.head->val))
            return ERROR;
        L.head = L.head->nxt;
    }
    return OK;
}

Status ReTraverse_L(LinkNode * head, Status (*visit)(ElemType data)){
    if(head == NULL)
        return ERROR;
    ReTraverse_L(head->nxt, visit);
    (*visit)(head->val);
    return OK;
}

#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define ERROR   0
#define OVERFLOW    -2

typedef int ElemType;
typedef int Status;
typedef struct LinkNode{
    ElemType val;
    struct LinkNode * nxt;
} LinkNode;
typedef struct LinkList{
    LinkNode * head;
    int len;
} LinkList;

    //alloc memory for a node
LinkNode * MakeNode(ElemType e){
    LinkNode * p = malloc(sizeof(LinkNode));
    if(p == NULL)
        exit(OVERFLOW);
    p->val = e;
    p->nxt = NULL;
    return p;
}

    //free the memory of node pointed by p
void FreeNode(LinkNode ** p){
    free(*p);
    *p = NULL;
}

    //initialize an empty linked list
Status InitList_L(LinkList * L){
    L->head = malloc(sizeof(LinkNode));
    if(L->head == NULL)
        exit(OVERFLOW);
    L->len = 0;
    L->head->nxt = NULL;
    return OK;
}

    //insert a new node right after the head node
void HeadIns_L(LinkNode * head, LinkNode * s){
    s->nxt = head->nxt;
    head->nxt = s;
}

    //build a linked list with n elems reversely inputed
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

    //delete the first elem in link list
Status HeadDel_L(LinkNode * head, LinkNode ** q){
    if(head->nxt == NULL)
        return ERROR;
    *q = head->nxt;
    head->nxt = head->nxt->nxt;
    return OK;
}

    //set the link list empty
Status ClearList_L(LinkList * L){
    LinkNode * p = NULL;
    while(HeadDel_L(L, &p))
        FreeNode(&p);
    L->len = 0;
    return OK;
}

    //destroy link list and free memory
Status DestroyList_L(LinkList * L){
    ClearList_L(L);
    FreeNode(&(L->head));
    free(L);
    L = NULL;
    return OK;
}

    //link s to the tail of L
Status Append_L(LinkList L, LinkNode * s){
    LinkNode * p = L.head;
    while(p->nxt != NULL)
        p = p->nxt;
    p->nxt = s;
    return OK;
}

    //remove the tail node and return it with q
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

    //insert node s to the front of node p and point p to s
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

    //return a pointer to the tail node
LinkNode * GetLast_L(LinkList L){
    while(L.head->nxt != NULL)
        L.head = L.head->nxt;
    return L.head;
}

    //return a pointer to the prior node of p
LinkNode * PriorPos_L(LinkList L, LinkNode * p){
    while(L.head->nxt != p && L.head->nxt != NULL)
        L.head = L.head->nxt;
    if(L.head->nxt != p)
        return NULL;
    return L.head;
}

    //return the ith elem with p
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

    //return a pointer to the first elem meet cmp()
LinkNode * LocateElem_L(LinkList L, ElemType e, Status (*cmp)(ElemType data, ElemType e)){
    if(L.len == 0)
        return NULL;
    while(!(*cmp)(L.head->nxt->val, e) && L.head->nxt != NULL)
        L.head = L.head->nxt;
    return L.head;
}

    //traverse link list in natural order
Status ListTraverse_L(LinkList L, Status (*visit)(ElemType data)){
    L.head = L.head->nxt;
    while(L.head != NULL){
        if(!(*visit)(L.head->val))
            return ERROR;
        L.head = L.head->nxt;
    }
    return OK;
}

    //traverse link list in reverse order
Status ReTraverse_L(LinkNode * head, Status (*visit)(ElemType data)){
    if(head == NULL)
        return ERROR;
    ReTraverse_L(head->nxt, visit);
    (*visit)(head->val);
    return OK;
}

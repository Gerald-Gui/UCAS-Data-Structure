#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

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
LinkNode * MakeNode(ElemType e);
    //free the memory of node pointed by p
void FreeNode(LinkNode ** p);
    //initialize an empty linked list
Status InitList_L(LinkList * L);
    //insert a new node right after the head node
void HeadIns_L(LinkNode * head, LinkNode * s);
    //build a linked list with n elems reversely inputed
Status CreateList_L(LinkList * L, int n);
    //delete the first elem in link list
Status HeadDel_L(LinkNode * head, LinkNode ** q);
    //set the link list empty
Status ClearList_L(LinkList * L);
    //destroy link list and free memory
Status DestroyList_L(LinkList * L);
    //link s to the tail of L
Status Append_L(LinkList L, LinkNode * s);
    //remove the tail node and return it with q
Status RemoveTail_L(LinkList * L, LinkNode ** q);
    //insert node s to the front of node p and point p to s
Status InsBefore_L(LinkList * L, LinkNode ** p, LinkNode * s);
    //return a pointer to the tail node
LinkNode * GetLast_L(LinkList L);
    //return a pointer to the prior node of p
LinkNode * PriorPos_L(LinkList L, LinkNode * p);
    //return the ith elem with p
Status LocatePos_L(LinkList L, int i, LinkNode ** p);
    //return a pointer to the first elem meet cmp()
LinkNode * LocateElem_L(LinkList L, ElemType e, Status (*cmp)(ElemType data, ElemType e));
    //traverse link list in natural order
Status ListTraverse_L(LinkList L, Status (*visit)(ElemType data));
    //traverse link list in reverse order
Status ReTraverse_L(LinkNode * head, Status (*visit)(ElemType data));

#endif

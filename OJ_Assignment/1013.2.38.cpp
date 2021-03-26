#include <iostream>
#include <cstdio>
using namespace std;

typedef struct DuListNode{
    int val;
    DuListNode * pre;
    DuListNode * nxt;
    int freq;
    int seq;
} * DuLinkList;

void PrintDuLinkList(DuLinkList L){
    DuListNode * p = L->nxt;
    if(p == L){
        printf("NULL\n");
        return;
    }
    while(p != L){
        printf("%d ", p->val);
        p = p->nxt;
    }
    printf("\n");
}

DuListNode * LocateElem(DuLinkList L, int e){
    for(DuListNode * p = L->nxt; p != L; p = p->nxt)
        if(p->val == e){
            p->freq++;
            return p;
        }
    return nullptr;
}

void MoveDuListNdoe(DuLinkList L, DuListNode * p){
    DuListNode * q = p->pre;
    while(q != L){
        if(q->freq > p->freq)
            break;
        if(q->freq == p->freq && q->seq < p->seq)
            break;
        q = q->pre;
    }
    if(p != q){
        p->pre->nxt = p->nxt;
        p->nxt->pre = p->pre;
        DuListNode * q_nxt = q->nxt;
        q->nxt = p;
        q_nxt->pre = p;
        p->pre = q;
        p->nxt = q_nxt;
    }
}

int main(){
    int n;
    DuLinkList head = new DuListNode;
    head->nxt = head->pre = head;
    
    DuListNode * p = head;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        p->nxt = new DuListNode;
        p->nxt->nxt = head;
        p->nxt->pre = p;
        cin >> p->nxt->val;
        p->freq = p->seq = 0;
        p = p->nxt;
    }
    head->pre = p;

    int cnt = 1, tmp;
    while(cin >> tmp){
        p = LocateElem(head, tmp);
        if(p->seq == 0)
            p->seq = cnt++;
        MoveDuListNdoe(head, p);
    }
    
    PrintDuLinkList(head);

    return 0;
}
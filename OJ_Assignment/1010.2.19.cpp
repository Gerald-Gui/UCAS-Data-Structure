#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode * nxt;
} * LinkList;

void PrintLinkList(LinkList p){
    if(p->nxt == nullptr){
        printf("NULL\n");
        return;
    }
    p = p->nxt;
    while(p != nullptr){
        printf("%d ", p->val);
        p = p->nxt;
    }
    printf("\n");
}

LinkList BuildList(int & mink, int & maxk){
    LinkList L = new ListNode;
    L->nxt = nullptr;
    ListNode * p = L;
    int tmp, buf1, buf2;
    cin >> buf1;
    cin >> buf2;
    tmp = buf1;
    buf1 = buf2;
    while(cin >> buf2){
        p->nxt = new ListNode;
        p->nxt->nxt = nullptr;
        p->nxt->val = tmp;
        p = p->nxt;
        tmp = buf1;
        buf1 = buf2;
    }

    mink = tmp;
    maxk = buf1;
    return L;
}

void DeleteNode(LinkList L, int mink, int maxk){
    ListNode * p = L, * q = nullptr;
    while(p->nxt != nullptr){
        if(p->nxt->val > mink && p->nxt->val < maxk){
            q = p->nxt;
            p->nxt = q->nxt;
            delete q;
            q = nullptr;
        }else
            p = p->nxt;
    }
}

int main(){
    int mink, maxk;

    LinkList L = BuildList(mink, maxk);
    DeleteNode(L, mink, maxk);
    PrintLinkList(L);
    return 0;
}
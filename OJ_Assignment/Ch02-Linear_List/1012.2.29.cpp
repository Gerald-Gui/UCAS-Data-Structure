#include <cstdio>
#include <cctype>

typedef struct ListNode{
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
        printf("%c", p->val);
        if(p->nxt != nullptr)
            printf(",");
        p = p->nxt;
    }
    printf("\n");
}

void InitLinkList(LinkList & L){
    L = new ListNode;
    L->nxt = nullptr;
}

void LineToLinkList(LinkList h){
    ListNode * p = h;
    char c;
    while((c = getchar()) != '\n')
        if(c != ',' && !isspace(c)){
            p->nxt = new ListNode;
            p->nxt->nxt = nullptr;
            p->nxt->val = c;
            p = p->nxt;
        }
}

int main(){
    LinkList ha = nullptr, hb = nullptr, hc = nullptr;
    InitLinkList(ha);   InitLinkList(hb);   InitLinkList(hc);
    LineToLinkList(ha); LineToLinkList(hb); LineToLinkList(hc);

    ListNode * prev = ha;
    ListNode * pb = hb, * pc = hc;
    ListNode * p = nullptr;
    while(prev->nxt != nullptr && pb != nullptr && pc != nullptr){
        if(pb->val < pc->val)
            pb = pb->nxt;
        else if(pb->val > pc->val)
            pc = pc->nxt;
        else{
            while(prev->nxt != nullptr && prev->nxt->val < pb->val)
                prev = prev->nxt;
            while(prev->nxt != nullptr && prev->nxt->val == pb->val){
                p = prev->nxt;
                prev->nxt = p->nxt;
                delete p;
                p = nullptr;
            }
            if(prev->nxt != nullptr)
                pb = pb->nxt;
        }
    }

    PrintLinkList(ha);
    
    return 0;
}
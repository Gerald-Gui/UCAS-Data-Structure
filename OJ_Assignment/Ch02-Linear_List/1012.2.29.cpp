#include <cstdio>
#include <cctype>

typedef struct ListNode {
    int val;
    ListNode *nxt;
    
    ListNode(int e = 0, ListNode *ptr = nullptr) :
        val(e), nxt(ptr) {}
} *LinkList;

void PrintLinkList(LinkList p) {
    if (p->nxt == nullptr) {
        printf("NULL\n");
        return;
    }
    p = p->nxt;
    while (p != nullptr) {
        printf("%c", p->val);
        if (p->nxt != nullptr) {
            printf(",");
        }
        p = p->nxt;
    }
    putchar('\n');
}

void LineToLinkList(LinkList h) {
    ListNode *p = h;
    char c;
    while ((c = getchar()) != '\n') {
        if (c != ',' && !isspace(c)) {
            p->nxt = new ListNode(c);
            p = p->nxt;
        }
    }
}

int main(){
    LinkList ha = new ListNode;
    LinkList hb = new ListNode;
    LinkList hc = new ListNode;
    LineToLinkList(ha); LineToLinkList(hb); LineToLinkList(hc);

    ListNode *prev = ha;
    ListNode *pb = hb, *pc = hc;
    ListNode *p = nullptr;
    while (prev->nxt != nullptr && pb != nullptr && pc != nullptr) {
        if (pb->val < pc->val) {
            pb = pb->nxt;
        } else if(pb->val > pc->val) {
            pc = pc->nxt;
        } else {
            while (prev->nxt != nullptr && prev->nxt->val < pb->val) {
                prev = prev->nxt;
            }
            while (prev->nxt != nullptr && prev->nxt->val == pb->val) {
                p = prev->nxt;
                prev->nxt = p->nxt;
                delete p;
                p = nullptr;
            }
            if (prev->nxt != nullptr) {
                pb = pb->nxt;
            }
        }
    }

    PrintLinkList(ha);
    
    return 0;
}
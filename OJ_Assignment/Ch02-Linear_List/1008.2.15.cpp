#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *nxt;
} *LinkList;

void PrintLinkList(LinkList p){
    if (p->nxt == nullptr) {
        return;
    }
    p = p->nxt;
    while (p != nullptr) {
        printf("%d ", p->val);
        p = p->nxt;
    }
    putchar('\n');
}

int main() {
    int m, n;

    cin >> m >> n;

    LinkList ha = new ListNode;
    LinkList hb = new ListNode;
    ha->nxt = hb->nxt = nullptr;
    ListNode *p = nullptr;
    ListNode *ra = ha, *rb = hb;

    for (int i = 0; i < m; ++i) {
        p = new ListNode;
        p->nxt = nullptr;
        cin >> p->val;
        ra->nxt = p;
        ra = ra->nxt;
    }
    for (int i = 0; i < n; i++) {
        p = new ListNode;
        p->nxt = nullptr;
        cin >> p->val;
        rb->nxt = p;
        rb = rb->nxt;
    }

    if (m > n) {
        rb->nxt = ha->nxt;
        PrintLinkList(hb);
    } else {
        ra->nxt = hb->nxt;
        PrintLinkList(ha);
    }
        
    return 0;
}
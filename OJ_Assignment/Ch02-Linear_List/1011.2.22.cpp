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

void ReverseList(LinkList L) {
    ListNode *p = L->nxt, *q = nullptr;
    L->nxt = nullptr;
    while (p != nullptr) {
        q = p;
        p = p->nxt;
        q->nxt = L->nxt;
        L->nxt = q;
    }
}

int main() {
    LinkList L = nullptr;
    ListNode *p = nullptr;
    char c;

    p = L = new ListNode;

    while ((c = getchar()) != EOF) {
        if (c != ',' && !isspace(c)) {
            p->nxt = new ListNode(c);
            p = p->nxt;
        }
    }
    
    ReverseList(L);
    PrintLinkList(L);
    return 0;
}
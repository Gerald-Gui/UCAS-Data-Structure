#include <cstdio>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *nxt;

    ListNode(int e = 0, ListNode *ptr = nullptr) :
        val(e), nxt(ptr) {}
};

void PrintLinkList(ListNode *L) {
    if (L->nxt == nullptr) {
        return;
    }
    printf("%d", L->nxt->val);
    for (ListNode *p = L->nxt->nxt; p != nullptr; p = p->nxt) {
        printf(" %d", p->val);
    }
    putchar('\n');
}

void SelectSort(ListNode *L) {
    if (L->nxt == nullptr) {
        return;
    }
    ListNode *cur = L->nxt;
    while (cur != nullptr) {
        ListNode *min = nullptr;
        for (ListNode *p = min = cur; p != nullptr; p = p->nxt) {
            min = std::min(min, p, [](ListNode *p, ListNode *q) { return p->val < q->val; });
        }
        std::swap(cur->val, min->val);
        cur = cur->nxt;
    }
}

int main() {
    int tmp;
    ListNode *L = new ListNode;
    ListNode *p = L;

    while (scanf("%d", &tmp) == 1) {
        p = p->nxt = new ListNode(tmp);
    }

    SelectSort(L);

    PrintLinkList(L);

    return 0;
}

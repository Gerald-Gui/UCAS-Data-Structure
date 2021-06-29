#include <cstdio>

struct ListNode {
    int val;
    ListNode *nxt;

    ListNode(int e = 0, ListNode *ptr = nullptr) :
        val(e), nxt(ptr) {}
};

void InsertionSort(ListNode *L) {
    if (L->nxt == nullptr) {
        return;
    }
    ListNode *lst = L->nxt;
    ListNode *cur = lst->nxt;
    while (cur != nullptr) {
        if (lst->val <= cur->val) {
            lst = lst->nxt;
        } else {
            ListNode *pre = L;
            while (pre->nxt->val <= cur->val) {
                pre = pre->nxt;
            }
            lst->nxt = cur->nxt;
            cur->nxt = pre->nxt;
            pre->nxt = cur;
        }
        cur = lst->nxt;
    }
}

void PrintLinkList(ListNode *L) {
    if (L->nxt == nullptr) {
        printf("NULL\n");
        return;
    }
    printf("%d", L->nxt->val);
    for (ListNode *p = L->nxt->nxt; p != nullptr; p = p->nxt) {
        printf(" %d", p->val);
    }
    putchar('\n');
}

int main() {
    ListNode *L = new ListNode;
    ListNode *p = L;
    int n, tmp;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        p = p->nxt = new ListNode(tmp);
    }

    InsertionSort(L);

    PrintLinkList(L);
    return 0;
}

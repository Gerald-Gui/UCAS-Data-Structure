#include <cstdio>

struct ListNode {
    int val;
    ListNode *nxt;

    ListNode(int e = 0, ListNode *next = nullptr) :
        val(e), nxt(next) {}
};

void PrintLinkList(ListNode *L) {
    if (L->nxt == nullptr) {
        printf("NULL\n");
    }
    printf("%d", L->nxt->val);
    for (ListNode *p = L->nxt->nxt; p != nullptr; p = p->nxt) {
        printf(" %d", p->val);
    }
    putchar('\n');
}

// 仅修改结点间链接关系，不拷贝交换元素

ListNode *QuickSort(ListNode *beg, ListNode *end) {
    if (beg == end || beg->nxt == end) {
        return beg;
    }
    ListNode *lt_ptr = beg;
    ListNode *gt_ptr = beg;
    ListNode *p  = beg->nxt;
    while (p != end) {
        ListNode *tmp = p->nxt;
        if (p->val < beg->val) {
            p->nxt = lt_ptr;
            lt_ptr = p;
        } else {
            gt_ptr->nxt = p;
            gt_ptr = p;
        }
        p = tmp;
    }
    gt_ptr->nxt = end;
    ListNode *ret = QuickSort(lt_ptr, beg);
    beg->nxt = QuickSort(beg->nxt, end);
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);

    ListNode *L = new ListNode;
    ListNode *p = L;
    int tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        p = p->nxt = new ListNode(tmp);
    }

    L->nxt = QuickSort(L->nxt, nullptr);

    PrintLinkList(L);
    return 0;
}

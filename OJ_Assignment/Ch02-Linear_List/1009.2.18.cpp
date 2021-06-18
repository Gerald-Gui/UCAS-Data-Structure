#include <iostream>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode *nxt;

    ListNode(int e = 0, ListNode *ptr = nullptr) :
        val(e), nxt(ptr) {}
} *LinkList;

void PrintLinkList(LinkList p){
    if (p == nullptr) {
        printf("NULL\n");
        return;
    }
    while (p != nullptr) {
        printf("%d ", p->val);
        p = p->nxt;
    }
    putchar('\n');
}

int main() {
    LinkList head = nullptr;
    ListNode *p = nullptr;
    int tmp = 0, cnt = 0;

    cin >> tmp;
    p = head = new ListNode(tmp);
    while (cin >> tmp) {
        p->nxt = new ListNode(tmp, p);
        p = p->nxt;
    }

    ListNode *q = p->nxt;
    q->nxt = nullptr;
    delete p;
    
    p = head;
    if (tmp == 0) {
        head = head->nxt;
        delete p;
        p = head;
    } else {
        while (++cnt < tmp) {
            p = p->nxt;
        }
        ListNode *q = p->nxt;
        p->nxt = q->nxt;
        delete q;
        q = nullptr;
    }

    PrintLinkList(head);
    return 0;
}
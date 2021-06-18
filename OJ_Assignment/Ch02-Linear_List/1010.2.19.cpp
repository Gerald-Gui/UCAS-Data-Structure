#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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
        printf("%d ", p->val);
        p = p->nxt;
    }
    putchar('\n');
}

LinkList BuildList() {
    LinkList L = new ListNode;
    ListNode *p = L;

    int tmp;
    string line;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> tmp) {
        p->nxt = new ListNode(tmp);
        p = p->nxt;
    }

    return L;
}

void DeleteNode(LinkList L, int mink, int maxk) {
    ListNode *p = L, *q = nullptr;
    while (p->nxt != nullptr) {
        if (p->nxt->val > mink && p->nxt->val < maxk) {
            q = p->nxt;
            p->nxt = q->nxt;
            delete q;
            q = nullptr;
        } else {
            p = p->nxt;
        }
    }
}

int main() {
    int mink, maxk;

    LinkList L = BuildList();
    cin >> mink >> maxk;
    DeleteNode(L, mink, maxk);
    PrintLinkList(L);
    return 0;
}
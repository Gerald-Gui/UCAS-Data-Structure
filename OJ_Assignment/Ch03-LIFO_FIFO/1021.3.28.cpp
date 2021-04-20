#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *nxt;
    ListNode(int e = 0, ListNode *p = nullptr): val(e), nxt(p) {}
};

struct LinkQueue {
    ListNode *rear;
    LinkQueue() {
        rear = new ListNode;
        rear->nxt = rear;
    }
    void EnQueue(int e) {
        ListNode *p = new ListNode(e, rear->nxt);
        rear->nxt = p;
        rear = p;
    }
    int DeQueue() {
        ListNode *p = rear->nxt->nxt;
        delete rear->nxt;
        rear->nxt = p;
        return p->val;
    }
    bool IsEmpty() {
        return rear->nxt == rear;
    }
};

int main() {
    int n, tmp = 0;
    char c;
    LinkQueue Q;

    cin >> n;
    for (int i = 0; i < n ; i++) {
        if (i != n - 1) {
            scanf("%d,", &tmp);
        } else {
            scanf("%d", &tmp);
        }
        Q.EnQueue(tmp);
    }
    
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", Q.DeQueue());
        } else {
            printf("%d,", Q.DeQueue());
        }
    }
    return 0;
}
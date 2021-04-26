#include <cstdio>
#include <iostream>

using namespace std;

struct ListNode{
    char ch;
    ListNode *succ;
    ListNode *nxt;
    int seq;
    ListNode(char c = 0, int i = 0): ch(c), succ(nullptr), nxt(nullptr), seq(i) {}
};

int main(){
    int len1, len2;
    cin >> len1 >> len2;

    if (len1 < len2) {
        cout << -1 << endl;
        return 0;
    }

    char c;
    ListNode *str1 = new ListNode;
    ListNode *str2 = new ListNode;
    ListNode *p = str1;
    while ((c = getchar()) != '\n') {}
    for (int i = 0; i < len1; i++) {
        p->succ = new ListNode(getchar(), i);
        p->succ->nxt = p;
        p = p->succ;
    }
    while ((c = getchar()) != '\n') {}
    p = str2;
    for (int i = 0; i < len2; i++) {
        p->succ = new ListNode(getchar(), i);
        p = p->succ;
    }

    p = str2->succ;
    ListNode *pt = str2;
    p->nxt = str2;
    while (p != nullptr) {
        if (pt == str2 || p->ch == pt->ch) {
            p = p->succ;
            pt = pt->succ;
            if (p == nullptr) {
                break;
            }
            if (p->ch != pt->ch) {
                p->nxt = pt;
            } else {
                p->nxt = pt->nxt;
            }
        }else
            pt = pt->nxt;
    }

    ListNode *pm = str1->succ;
    p = str1->succ;
    pt = str2->succ;
    while (len1 - pm->seq >= len2) {
        if (p->ch == pt->ch) {
            if (pt->succ != nullptr) {
                p = p->succ;
                pt = pt->succ;
            } else {
                cout << pm->seq << endl;
                return 0;
            }
        } else if (pt == str2) {
            pm = p = p->succ;
            pt = pt->succ;
        } else {
            pt = pt->nxt;
            pm = p;
        }
    }

    cout << -1 << endl;
    return 0;
}

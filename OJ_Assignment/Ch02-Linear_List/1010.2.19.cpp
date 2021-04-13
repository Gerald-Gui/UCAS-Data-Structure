#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode * nxt;
} * LinkList;

void PrintLinkList(LinkList p){
    if(p->nxt == nullptr){
        printf("NULL\n");
        return;
    }
    p = p->nxt;
    while(p != nullptr){
        printf("%d ", p->val);
        p = p->nxt;
    }
    printf("\n");
}

LinkList BuildList(){
    LinkList L = new ListNode;
    L->nxt = nullptr;
    ListNode * p = L;

    int tmp;
    string line;
    getline(cin, line);
    stringstream ss(line);
    while(ss >> tmp){
        p->nxt = new ListNode;
        p->nxt->val = tmp;
        p->nxt->nxt = nullptr;
        p = p->nxt;
    }

    return L;
}

void DeleteNode(LinkList L, int mink, int maxk){
    ListNode * p = L, * q = nullptr;
    while(p->nxt != NULL){
        if(p->nxt->val > mink && p->nxt->val < maxk){
            q = p->nxt;
            p->nxt = q->nxt;
            delete q;
            q = NULL;
        }else
            p = p->nxt;
    }
}

int main(){
    int mink, maxk;

    LinkList L = BuildList();
    cin >> mink >> maxk;
    DeleteNode(L, mink, maxk);
    PrintLinkList(L);
    return 0;
}
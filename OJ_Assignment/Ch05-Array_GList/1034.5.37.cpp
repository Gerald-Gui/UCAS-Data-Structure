#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef enum {ATOM, LIST} ElemTag;
struct GLNode {
    ElemTag tag;
    union {
        char atom;
        GLNode *hp;
    };
    GLNode *nxt;
    GLNode() : nxt(nullptr) {};
    GLNode(char elem) : tag(ATOM), atom(elem), nxt(nullptr) {}
    GLNode(GLNode *ptr) : tag(LIST), hp(ptr), nxt(nullptr) {}
};
using GList = GLNode*;

GList CreateGList() {
    GLNode *head = new GLNode;
    GLNode *p = head;
    for (char c = getchar(); c != ')' && c != ' '; c = getchar()) {
        if (c == '(') {
            p->nxt = new GLNode(CreateGList());
            p = p->nxt;
        } else if (c != ',') {
            p->nxt = new GLNode(c);
            p = p->nxt;
        }
    }
    p = head->nxt;
    delete head;
    return p;
}

void PrintGList(GList L) {
    while (L != nullptr) {
        if (L->tag == LIST) {
            putchar('(');
            PrintGList(L->hp);
            putchar(')');
        } else {
            putchar(L->atom);
        }
        if (L->nxt != nullptr) {
            putchar(',');
        }
        L = L->nxt;
    }
}

GList DeleteAtom(GList L, char tar) {
    GLNode *head = new GLNode;
    head->nxt = L;
    L = head;
    while (L->nxt != nullptr) {
        if (L->nxt->tag == LIST) {
            L->nxt->hp = DeleteAtom(L->nxt->hp, tar);
            if (L->nxt->hp == nullptr) {
                GLNode *p = L->nxt;
                L->nxt = L->nxt->nxt;
                delete p;
            } else {
                L = L->nxt;
            }
        } else if (L->nxt->atom == tar) {
            GLNode *p = L->nxt;
            L->nxt = L->nxt->nxt;
            delete p;
        } else {
            L = L->nxt;
        }
    }
    L = head->nxt;
    delete head;
    return L;
}

bool Search(GList L) {
    if (L == nullptr) {
        return false;
    }
    if (L->tag == ATOM) {
        return true;
    }
    while (L != nullptr) {
        if (L->tag == ATOM) {
            return true;
        }
        if (Search(L->hp)) {
            return true;
        }
        L = L->nxt;
    }
    return false;
}

int main() {
    GList L = CreateGList();
    char tar;
    while (isspace(tar = getchar())) {}
    L = DeleteAtom(L, tar);
    if (Search(L)) {
        PrintGList(L);
    } else {
        printf("-1");
    }
    putchar('\n');
    return 0;
}

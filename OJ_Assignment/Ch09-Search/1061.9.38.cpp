#include <bits/stdc++.h>
using namespace std;

constexpr int MAXNODE = 1000;

struct Node {
    int val;
    Node *lchild;
    Node *rchild;

    Node(int e = 0, Node *l = nullptr, Node *r = nullptr) :
        val(e), lchild(l), rchild(r) {}
};

Node *ptree1 = nullptr;
Node *ptree2 = nullptr;

void Insert(Node *&ptree, int e) {
    if (e == -1) {
        return;
    }
    if (ptree == nullptr) {
        ptree = new Node(e);
        return;
    }
    Node *p = ptree;
    while ((p->lchild != nullptr && p->val > e) || (p->rchild != nullptr && p->val < e)) {
        p = p->val > e ? p->lchild : p->rchild;
    }
    if (p->lchild == nullptr && p->val > e) {
        p->lchild = new Node(e);
    } else if (p->rchild == nullptr && p->val < e) {
        p->rchild = new Node(e);
    }
}

Node *BuildTree(const vector<int> &vec) {
    Node *p = nullptr;
    for (const auto &i : vec) {
        Insert(p, i);
    }
    return p;
}

void InOrder(Node *root, void (*func)(Node *&, int)) {
    Node *stk[MAXNODE];
    int sp = 0;
    Node *p = root;
    while (p != nullptr || sp != 0) {
        if (p != nullptr) {
            stk[sp++] = p;
            p = p->lchild;
        } else {
            p = stk[--sp];
            (*func)(ptree1, p->val);
            p = p->rchild;
        }
    }
}

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c, *p = NULL;
    for (p = line; --lim > 0 && (c = fgetc(stream)) != EOF && c != '\n'; *p++ = c) {}
    *p = '\0';
    if (c == EOF && p != line) ungetc(c, stream);
    return c == EOF && p == line ? NULL : line;
}

int main() {
    vector<int> vec;
    char line[BUFSIZ];

    for (char *p = strtok(fgetline(line, BUFSIZ, stdin), " "); p != nullptr; p = strtok(nullptr, " ")) {
        vec.push_back(atoi(p));
    }
    ptree1 = BuildTree(vec);

    vec.clear();
    
    for (char *p = strtok(fgetline(line, BUFSIZ, stdin), " "); p != nullptr; p = strtok(nullptr, " ")) {
        vec.push_back(atoi(p));
    }
    ptree2 = BuildTree(vec);
    InOrder(ptree2, Insert);

    InOrder(ptree1, [](Node *&p, int a) { printf("%d ", a); });
    putchar('\n');

    return 0;
}

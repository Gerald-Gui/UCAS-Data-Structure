#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
    int val;
    Node *lchild;
    Node *rchild;

    Node(int e = 0, Node *lp = nullptr, Node *rp = nullptr) :
        val(e), lchild(lp), rchild(rp) {}
};

void InsertBST(Node *&ptree, int e) {
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

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c, *p = nullptr;
    for (p = line; --lim > 0 && (c = fgetc(stream)) != EOF && c != '\n'; *p++ = c) {}
    *p = '\0';
    if (c == EOF && p != line) ungetc(c, stream);
    return c == EOF && p == line ? nullptr : line;
}

void InOrder(Node *p, int x) {
    if (p == nullptr) {
        return;
    }
    InOrder(p->rchild, x);
    if (p->val < x) {
        return;
    }
    printf("%d ", p->val);
    InOrder(p->lchild, x);
}

int main() {
    char line[BUFSIZ];
    Node *ptree = nullptr;

    for (char *p = strtok(fgetline(line, BUFSIZ, stdin), " "); p != nullptr; p = strtok(nullptr, " ")) {
        InsertBST(ptree, atoi(p));
    }

    int x;
    scanf("%d", &x);
    
    InOrder(ptree, x);
    putchar('\n');

    return 0;
}

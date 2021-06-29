#include <cstdio>
#include <cstdlib>
#include <cstring>

constexpr int MAXNODE = 1000;

struct Node {
    int val;
    Node *lchild;
    Node *rchild;

    Node(int e = 0, Node *lp = nullptr, Node *rp = nullptr) :
        val(e), lchild(lp), rchild(rp) {}
};

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c, *p = nullptr;
    for (p = line; --lim > 0 && (c = fgetc(stream)) != EOF && c != '\n'; *p++ = c) {}
    *p = '\0';
    if (c == EOF && p != line) ungetc(c, stream);
    return c == EOF && p == line ? nullptr : line;
}

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

void InOrderPrint(Node *root, int a, int b) {
    Node *stk[MAXNODE];
    int sp = 0;
    Node *p = root;
    while (p != nullptr || sp != 0) {
        if (p != nullptr) {
            stk[sp++] = p;
            p = p->lchild;
        } else {
            p = stk[--sp];
            if (p->val >= b) {
                return;
            } else if (p->val > a) {
                printf("%d ", p->val);
            }
            p = p->rchild;
        }
    }
}

int main() {
    char line[BUFSIZ];
    Node *ptree = nullptr;
    
    for (char *p = strtok(fgetline(line, BUFSIZ, stdin), " "); p != nullptr; p = strtok(nullptr, " ")) {
        InsertBST(ptree, atoi(p));
    }

    int a, b;
    scanf("%d %d", &a, &b);
    InOrderPrint(ptree, a, b);
    putchar('\n');

    return 0;
}

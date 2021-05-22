#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

#define STR_LEN 1000

struct ListNode {
    ssize_t val;
    ListNode *nxt;
    ListNode(ssize_t i = 0, ListNode *ptr = nullptr) :
        val(i), nxt(ptr) {}
};

ssize_t low = LONG_MAX;

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c, *p = NULL;
    for (p = line; --lim > 0 && (c = fgetc(stream)) != EOF && c != '\n'; *(p++) = c) {}
    *p = '\0';
    if (c == EOF && p != line) ungetc(c, stream);
    return c == EOF && p == line ? NULL : line;
}

ListNode *InitGraph(size_t amt) {
    ListNode *graph = new ListNode[amt + 1];
    for (size_t i = 0; i < amt + 1; i++) {
        graph[i].val = -1;
    }
    return graph;
}

char *GetArc(const char *str, ssize_t &head, ssize_t &tail) {
    if (str == nullptr) {
        return nullptr;
    }
    char *p = nullptr;
    head = strtol(str, &p, 10);
    tail = atoi(p + 1);
    return p;
}

void InsertArc(ssize_t head, ssize_t tail, ListNode *graph) {
    low = min(head, min(tail, low));
    graph[head].nxt = new ListNode(tail, graph[head].nxt);
}

size_t MaxPathLen(size_t i, ListNode *graph) {
    if (graph[i].val >= 0) {
        return graph[i].val;
    }
    size_t len = 0;
    for (ListNode *p = graph[i].nxt; p != nullptr; p = p->nxt) {
        len = max(len, MaxPathLen(p->val, graph) + 1);
    }
    return graph[i].val = len;
}

int main() {
    char line[STR_LEN];
    size_t n = atoi(fgetline(line, STR_LEN, stdin));
    ListNode *graph = InitGraph(n);

    ssize_t head, tail;
    GetArc(strtok(fgetline(line, STR_LEN, stdin), ","), head, tail);
    InsertArc(head, tail, graph);
    while (GetArc(strtok(nullptr, ","), head, tail) != nullptr) {
        InsertArc(head, tail, graph);
    }

    for (size_t i = 0; i < n; i++) {
        graph[i + low].val = MaxPathLen(i + low, graph);
    }

    for (size_t i = 0; i < n; i++) {
        printf("%ld%c", graph[i + low].val, i == n - 1 ? '\n' : ',');
    }

    return 0;
}

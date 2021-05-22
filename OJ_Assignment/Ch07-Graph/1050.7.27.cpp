#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define STR_LEN 1000

struct ListNode {
    size_t val;
    ListNode *nxt;
    ListNode(size_t e = 0, ListNode *ptr = nullptr) :
        val(e), nxt(ptr) {}
};
using LinkList = ListNode*;

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c;
    char *p = NULL;
    for (p = line; --lim > 0 && (c = getchar()) != EOF && c != '\n'; p++) {
        *p = c;
    }
    *p = '\0';
    if (c == EOF && p == line) {
        return NULL;
    } else {
        if (c == EOF) {
            ungetc(c, stream);
        }
        return line;
    }
}

LinkList *InitGraph(size_t vtx) {
    LinkList *graph = new LinkList[vtx + 1];
    fill(graph, graph + vtx + 1, nullptr);
    return graph;
}

void StrSplitInto2(char *str, size_t &head, size_t &tail, char delim) {
    char *p = str;
    while (*p != delim && *p != '\0') {
        p++;
    }
    *p = '\0';
    head = atoi(str);
    tail = atoi(p + 1);
    *p = delim;
}

void InsertArc(size_t head, size_t tail, LinkList *graph) {
    graph[head] = new ListNode(tail, graph[head]);
}

bool DFS(size_t beg, size_t tar, LinkList *graph, size_t k, bool *visited) {
    if (beg == tar && k == 0) {
        return true;
    }
    for (ListNode *p = graph[beg]; p != nullptr; p = p->nxt) {
        if (!visited[p->val]) {
            visited[p->val] = true;
            if (DFS(p->val, tar, graph, k - 1, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool FindLenkPath(size_t beg, size_t tar, LinkList *graph, size_t k, size_t vtx) {
    bool *visited = new bool[vtx + 1];
    fill(visited, visited + vtx + 1, false);
    visited[beg] = true;
    bool flg = DFS(beg, tar, graph, k, visited);
    delete[] visited;
    return flg;
}

int main(void) {
    char line[STR_LEN];
    size_t n, k;
    StrSplitInto2(fgetline(line, STR_LEN, stdin), n, k, ',');
    LinkList *graph = InitGraph(n);

    size_t beg, tar;
    StrSplitInto2(fgetline(line, STR_LEN, stdin), beg, tar, ',');

    char *p = strtok(fgetline(line, STR_LEN, stdin), ",");
    size_t head, tail;
    StrSplitInto2(p, head, tail, '-');
    InsertArc(head, tail, graph);
    while ((p = strtok(nullptr, ",")) != nullptr) {
        StrSplitInto2(p, head, tail, '-');
        InsertArc(head, tail, graph);
    }

    puts(FindLenkPath(beg, tar, graph, k, n) ? "yes" : "no");
    return 0;
}

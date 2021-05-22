#include <cstdio>
#include <cstring>
#include <climits>

#define STR_LEN 1000

struct ListNode {
    size_t tail;
    size_t weight;
    ListNode *nxt;
    ListNode(size_t v = 0, size_t w = 0, ListNode *ptr = nullptr) :
        tail(v), weight(w), nxt(ptr) {}
};
using LinkList = ListNode*;

size_t Min_ulong(size_t a, size_t b) {
    return a < b ? a : b;
}

LinkList *InitGraph(size_t n) {
    LinkList *graph = new LinkList[n + 1];
    for (size_t i = 0; i < n + 1; i++) {
        graph[i] = nullptr;
    }
    return graph;
}

void InsertArc(size_t head, size_t tail, size_t weight, LinkList *graph) {
    graph[head] = new ListNode(tail, weight, graph[head]);
}

void Dijkstra(size_t n, size_t beg, LinkList *graph, size_t *pLen, bool *visited) {
    pLen[beg] = 0;
    for (size_t k = n; k > 0; k--) {
        size_t cur = 0;
        size_t len = ULONG_MAX;
        for (size_t i = 1; i <= n; i++) {
            if (!visited[i] && pLen[i] < len) {
                len = pLen[i];
                cur = i;
            }
        }
        visited[cur] = true;
        for (ListNode *p = graph[cur]; p != nullptr; p = p->nxt) {
            pLen[p->tail] = Min_ulong(pLen[p->tail], len + p->weight);
        }
    }
}

int main() {
    size_t n, beg;
    scanf("%ld %ld", &n, &beg);
    LinkList *graph = InitGraph(n);

    size_t h, t, w;
    while (scanf("%ld-%ld %ld", &h, &t, &w) == 3) {
        InsertArc(h, t, w, graph);
    }

    size_t *pathLen = new size_t[n + 1];
    bool *visited = new bool[n + 1];
    memset(pathLen, 0xFF, (n + 1) * sizeof(size_t));
    memset(visited, 0, (n + 1) * sizeof(bool));

    Dijkstra(n, beg, graph, pathLen, visited);

    for (size_t i = 1; i <= n; i++) {
        if (i != beg) {
            printf("%ld%c", pathLen[i], i == n || (i == n - 1 && n == beg) ? '\n' : ',');
        }
    }

    return 0;
}

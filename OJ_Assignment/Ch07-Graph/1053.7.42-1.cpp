#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <utility>
using std::vector;
using std::pair;
using std::priority_queue;
using std::greater;

#define STR_LEN 1000

struct ListNode {
    size_t tail;
    size_t weight;
    ListNode *nxt;
    ListNode(size_t v = 0, size_t w = 0, ListNode *ptr = nullptr) :
        tail(v), weight(w), nxt(ptr) {}
};
using LinkList = ListNode*;

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
    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> heap;
    heap.push({pLen[beg], beg});
    while (!heap.empty()) {
        pair<size_t, size_t> tmp = heap.top();
        heap.pop();
        if (visited[tmp.second]) {
            continue;
        }
        visited[tmp.second] = true;
        for (ListNode *p = graph[tmp.second]; p != nullptr; p = p->nxt) {
            if (tmp.first + p->weight < pLen[p->tail]) {
                pLen[p->tail] = tmp.first + p->weight;
            }
            if (!visited[p->tail]) {
                heap.push({pLen[p->tail], p->tail});
            }
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

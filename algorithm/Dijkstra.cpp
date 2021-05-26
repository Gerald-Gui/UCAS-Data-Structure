//https://www.luogu.com.cn/problem/P4779

#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

struct ListNode {
    int val;
    int wgt;
    ListNode *nxt;
    ListNode(int e = 0, int w = 0, ListNode *ptr = nullptr) :
        val(e), wgt(w), nxt(ptr) {}
};
using LinkList = ListNode*;

// Dijkstra based on heap
void Dijkstra(int n, int src, LinkList *graph, int *plen, bool *visited) {
    plen[src] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;
    heap.push({plen[src], src});
    while (!heap.empty()) {
        std::pair<int, int> tmp = heap.top();
        heap.pop();
        if (visited[tmp.second]) {
            continue;
        }
        visited[tmp.second] = true;
        for (ListNode *p = graph[tmp.second]; p != nullptr; p = p->nxt) {
            if (tmp.first + p->wgt < plen[p->val]) {
                plen[p->val] = tmp.first + p->wgt;
            }
            if (!visited[p->val]) {
                heap.push({plen[p->val], p->val});
            }
        }
    }
}

int main() {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);

    LinkList *graph = new LinkList[n + 1];
    for (int i = 0; i <= n; i++) {
        graph[i] = nullptr;
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u] = new ListNode(v, w, graph[u]);
    }

    bool *visited = new bool[n + 1];
    int *plen = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
        plen[i] = 0x7fffffff;
    }

    Dijkstra(n, s, graph, plen, visited);

    for (int i = 1; i <= n; i++) {
        printf("%d%c", plen[i], i == n ? '\n' : ' ');
    }

    return 0;
}

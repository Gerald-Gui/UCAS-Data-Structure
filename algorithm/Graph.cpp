struct ListNode {
    int val;
    ListNode *nxt;
    ListNode(int e = 0, ListNode *ptr = nullptr) :
        val(e), nxt(ptr) {}
};
using LinkList = ListNode*;
using Graph = LinkList*;

Graph InitGraph(int n) {
    Graph G = new LinkList[n];
    for (int i = 0; i < n; i++) {
        G[i] = nullptr;
    }
    return G;
}

void InsertArc(Graph G, int head, int tail) {
    G[head] = new ListNode(tail, G[head]);
    /* if without directions */
    //G[tail] = new ListNode(head, G[tail]);
}

// Simple Path

bool PathDFS(Graph G, int v, int w, bool *visited) {
    if (v == w) {
        return true;
    }
    visited[v] = true;
    for (ListNode *p = G[v]; p != nullptr; p = p->nxt) {
        if (!visited[p->val]) {
            if (PathDFS(G, p->val, w, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool PathExists(Graph G, int v, int w, int n) {
    bool *visited = new bool[n];    //adjust the amount of bools according to nodes
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    bool ret = PathDFS(G, v, w, visited);
    delete[] visited;
    return ret;
}

// Hamilton Path

bool HPathDFS(Graph G, int v, int w, int d, bool *visited) {
    if (v == w) {
        if (d == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    visited[v] = true;
    for (ListNode *p = G[v]; p != nullptr; p = p->nxt) {
        if (!visited[p->val]) {
            if (HPathDFS(G, p->val, w, d - 1, visited)) {
                return 1;
            }
        }
    }
    visited[v] = false;
    return 0;
}

bool HPathExists(Graph G, int v, int w, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    bool ret = HPathDFS(G, v, w, n - 1, visited);
    delete[] visited;
    return ret;
}

// Euler Path

int ODegree(Graph G, int v) {
    int cnt = 0;
    for (ListNode *p = G[v]; p != nullptr; p = p->nxt) {
        cnt++;
    }
    return cnt;
}

bool EPathExists(Graph G, int v, int w, int n) {
    if ((ODegree(G, v) + ODegree(G, w) % 2) != 0) {
        return false;
    }
    for (int i = 0; i < n; i++) {  // nodes start at 0
        if (i != v && i != w) {
            if ((ODegree(G, i) % 2) != 0) {
                return false;
            }
        }
    }
    return true;
}

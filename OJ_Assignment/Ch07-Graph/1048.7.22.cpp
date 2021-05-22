#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    size_t val;
    ListNode *nxt;
    ListNode(size_t e = 0, ListNode *ptr = nullptr) :
        val(e), nxt(ptr) {}
};
using LinkList = ListNode*;

LinkList *InitGraph(size_t vtx) {
    LinkList *graph = new LinkList[vtx + 1];
    fill(graph, graph + vtx + 1, nullptr);
    return graph;
}

void GetArc(const string &str, size_t &head, size_t &tail) {
    auto it = str.cbegin();
    string tmp;
    while (*it != '-') {
        tmp += *it;
        it++;
    }
    head = stoi(tmp);
    tmp.clear();
    while (++it != str.cend()) {
        tmp += *it;
    }
    tail = stoi(tmp);
}

void InsertArc(size_t head, size_t tail, LinkList *graph) {
    graph[head] = new ListNode(tail, graph[head]);
}

bool DFS(size_t i, size_t j, LinkList *graph, bool *visited) {
    if (i == j) {
        return true;
    }
    for (ListNode *p = graph[i]; p != nullptr; p = p->nxt) {
        if (!visited[p->val]) {
            visited[p->val] = true;
            if (DFS(p->val, j, graph, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool FindPath(size_t i, size_t j, LinkList *graph, size_t vtx) {
    bool *visited = new bool[vtx + 1];
    fill(visited, visited + vtx + 1, false);
    visited[i] = true;
    bool flg = DFS(i, j, graph, visited);
    delete[] visited;
    return flg;
}

int main() {
    size_t amt;
    size_t i, j;
    size_t head, tail;
    string line, tmp;
    LinkList *graph = nullptr;

    getline(cin, line);
    amt = stoi(line);
    graph = InitGraph(amt);

    getline(cin, line);
    stringstream ss(line);
    while (getline(ss, tmp, ',')) {
        GetArc(tmp, head, tail);
        InsertArc(head, tail, graph);
    }

    scanf("%ld,%ld", &i, &j);
    if (FindPath(i, j, graph, amt)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}

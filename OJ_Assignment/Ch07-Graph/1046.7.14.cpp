#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

struct ListNode {
    string val;
    ListNode *nxt;
    ListNode(string str = "", ListNode *ptr = nullptr) {
        val = str;
        nxt = ptr;
    }
};

void InsertArc(const string &head, const string &tail, map<int, ListNode> &graph) {
    ListNode *pre = &(graph[stoi(head)]);
    ListNode *p = pre->nxt;
    while (p != nullptr) {
        if (tail > p->val) {
            break;
        }
        p = p->nxt;
        pre = pre->nxt;
    }
    pre->nxt = new ListNode(tail, p);
    if (graph.find(stoi(tail)) == graph.end()) {
        graph[stoi(tail)] = {"", nullptr};
    }
}

void PrintGraph(const map<int, ListNode> &graph) {
    for (auto it = graph.cbegin(); it != graph.cend(); it++) {
        cout << it->first;
        if (it->second.nxt != nullptr) {
            cout << " ";
            ListNode *p = it->second.nxt;
            while (p != nullptr) {
                cout << p->val;
                if (p->nxt != nullptr) {
                    cout << ",";
                }
                p = p->nxt;
            }
        }
        cout << endl;
    }
}

string gethead(const string &arc, char delim) {
    auto it = arc.cbegin();
    string ret;
    while (*it != delim) {
        ret += *it;
        it++;
    }
    return ret;
}

string gettail(const string &arc, char delim) {
    auto it = arc.cbegin();
    string ret;
    while (*it != delim) {
        it++;
    }
    it++;
    while (it != arc.cend()) {
        ret += *it;
        it++;
    }
    return ret;
}

int main() {
    size_t vtxamt, arcamt;
    string line;
    getline(cin, line);
    vtxamt = stoi(gethead(line, ','));
    arcamt = stoi(gettail(line, ','));

    map<int, ListNode> graph;
    getline(cin, line);
    string arc;
    stringstream ss(line);
    while (getline(ss, arc, ',')) {
        InsertArc(gethead(arc, '-'), gettail(arc, '-'), graph);
    }

    PrintGraph(graph);
    return 0;
}

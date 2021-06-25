#include <bits/stdc++.h>
using namespace std;

constexpr int ABSIZE = 26;

struct Node {
    bool flg;
    Node *nxt[ABSIZE];

    Node() {
        flg = false;
        for (auto &p : nxt) {
            p = nullptr;
        }
    }
};

void Insert(Node *&ptree, const string &str) {
    if (ptree == nullptr) {
        ptree = new Node;
    }
    Node *p = ptree;
    for (auto it = str.cbegin(); it != str.cend(); ++it) {
        if (p->nxt[*it - 'a'] == nullptr) {
            p->nxt[*it - 'a'] = new Node;
        }
        p = p->nxt[*it - 'a'];
    }
    p->flg = true;
}

bool Search(Node *ptree, const string &str) {
    if (ptree == nullptr) {
        return false;
    }
    Node *p = ptree;
    for (auto it = str.cbegin(); it != str.cend() && p != nullptr; ++it) {
        p = p->nxt[*it - 'a'];
    }
    return p == nullptr ? false : p->flg;
}

void Delete(Node *ptree, const string &str) {
    if (ptree == nullptr) {
        return;
    }
    Node *p = ptree;
    for (auto it = str.cbegin(); it != str.cend() && p != nullptr; ++it) {
        p = p->nxt[*it - 'a'];
    }
    if (p != nullptr) {
        p->flg = false;
    }
}

int main() {
    int op;
    string word;
    Node *ptree = new Node;

    while (cin >> op >> word) {
        switch (op) {
            case 1:
                Insert(ptree, word);
                break;
            case 3:
                puts(Search(ptree, word) ? "True" : "False");
                break;
            case 2:
                Delete(ptree, word);
        }
    }

    return 0;
}

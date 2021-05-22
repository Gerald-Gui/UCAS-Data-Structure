#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

struct tnode {
    char val;
    tnode *left;
    tnode *right;
    tnode(char ch = '\0', tnode *lptr = nullptr, tnode *rptr = nullptr) :
        val(ch), left(lptr), right(rptr) {}
};

void BuildTree(tnode *&ptr, const string &pre, const string &in, size_t lo, size_t hi) {
    static auto it = pre.cbegin();
    if (it != pre.cend()) {
        auto tar = find(in.cbegin() + lo, in.cbegin() + hi, *it);
        if (tar == in.cbegin() + hi) {
            ptr = nullptr;
        } else {
            ptr = new tnode(*it, nullptr, nullptr);
            it++;
            BuildTree(ptr->left, pre, in, lo, tar - in.cbegin());
            BuildTree(ptr->right, pre, in, tar - in.cbegin(), hi);
        }
    }
}

void PostOrderPrint(tnode *root) {
    stack<tnode*> stk;
    tnode *p = root, *r = nullptr;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.push(p);
            p = p->left;
        } else {
            p = stk.top();
            if (p->right != nullptr && p->right != r) {
                p = p->right;
                stk.push(p);
                p = p->left;
            } else {
                stk.pop();
                cout << p->val;
                r = p;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int main() {
    string pre, in;
    tnode *ptree;
    getline(cin, pre);
    getline(cin, in);
    BuildTree(ptree, pre, in, 0, pre.size());
    PostOrderPrint(ptree);
    return 0;
}

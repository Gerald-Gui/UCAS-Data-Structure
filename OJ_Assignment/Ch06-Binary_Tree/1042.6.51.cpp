#include <iostream>
using namespace std;

struct tnode {
    char val;
    tnode *lft;
    tnode *rgt;
};

inline bool OpHigher(char op1, char op2) {
    return (op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-');
}

inline bool OpLowEqual(char op1, char op2) {
    return op1 == '-' && (op2 == '+' || op2 == '-');
}

void CreateTree(tnode *&ptr) {
    char c = cin.get();
    if (c == '#') {
        ptr = nullptr;
    } else {
        ptr = new tnode;
        ptr->val = c;
        CreateTree(ptr->lft);
        CreateTree(ptr->rgt);
    }
}

void InOrder(tnode *root) {
    if (root == nullptr) {
        return;
    }
    bool flg = false;

    if (root->lft != nullptr) {
        flg = OpHigher(root->val, root->lft->val);
    } else {
        flg = false;
    }
    if (flg) cout << "(";
    InOrder(root->lft);
    if (flg) cout << ")";

    cout << root->val;

    if (root->rgt != nullptr) {
        flg = OpHigher(root->val, root->rgt->val) || OpLowEqual(root->val, root->rgt->val);
    } else {
        flg = false;
    }
    if (flg) cout << "(";
    InOrder(root->rgt);
    if (flg) cout << ")";
}

int main() {
    tnode *ptree = nullptr;
    CreateTree(ptree);
    InOrder(ptree);
    cout << endl;
    return 0;
}

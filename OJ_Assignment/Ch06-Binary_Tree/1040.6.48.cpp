#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct tnode {
    char val;
    tnode *left;
    tnode *right;
    tnode(char e = '\0', tnode *lft = nullptr, tnode *rgt = nullptr) :
        val(e), left(lft), right(rgt) {}
};

void CreateTree(tnode *&ptr) {
    char ch = cin.get();
    if (ch == '^') {
        ptr = nullptr;
    } else {
        ptr = new tnode(ch);
        CreateTree(ptr->left);
        CreateTree(ptr->right);
    }
}

bool GetPath(tnode *ptree, vector<char> &path, char tar) {
    if (ptree == nullptr) {
        return false;
    }
    path.push_back(ptree->val);
    if (ptree->val == tar) {
        return true;
    }
    if (GetPath(ptree->left, path, tar)) {
        return true;
    }
    if (GetPath(ptree->right, path, tar)) {
        return true;
    }
    path.pop_back();
    return false;
}

char CloseAncestor(const vector<char> &path1, const vector<char> &path2) {
    auto it1 = path1.begin();
    auto it2 = path2.begin();
    char ret = '\0';
    while (it1 != path1.end() && it2 != path2.end()) {
        if (*it1 == *it2) {
            ret = *it1;
        } else {
            break;
        }
        it1++;
        it2++;
    }
    return ret;
}

int main() {
    tnode *ptree;
    CreateTree(ptree);
    string p, q;
    cin >> p >> q;

    vector<char> ppath, qpath;
    GetPath(ptree, ppath, p[0]);
    GetPath(ptree, qpath, q[0]);
    cout << CloseAncestor(ppath, qpath) << endl;
    return 0;
}

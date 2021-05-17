#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

template <typename _type>
void PrintVector(const vector<_type> vec) {
    for (auto it = vec.cbegin(); it != vec.cend(); it++) {
        cout << *it;
        if (it != vec.cend() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

vector<int> FindRoots(const vector<int> &child, const vector<int> &sibil, size_t n) {
    decltype(n) tar = 0;
    vector<int> roots;
    while (++tar <= n) {
        bool inChild = find(child.begin(), child.end(), tar) != child.end();
        bool inSibil = find(sibil.begin(), sibil.end(), tar) != sibil.end();
        if (!inChild && !inSibil) {
            roots.push_back(tar);
        }
    }
    roots.push_back(0);
    return roots;
}

int Forest2Tree(const vector<int> &child, const vector<int> &sibil,
                 vector<int> &left, vector<int> &right, size_t n) {
    vector<int> roots = FindRoots(child, sibil, n);
    auto itr = roots.begin();
    for (size_t i = 1; i <= n; i++) {
        bool isRoot = find(roots.begin(), roots.end(), i) != roots.end();
        if (isRoot) {
            left[i] = child[i];
            right[i] = *(++itr);
        } else {
            left[i] = child[i];
            right[i] = sibil[i];
        }
    }
    return roots[0];
}

void PreOrderPreTag(const vector<int> &left, const vector<int> &right, int root) {
    stack<int> stk;
    vector<int> lft(left.begin(), left.end());
    int i = root, pre = 0;
    while (i != 0 || !stk.empty()) {
        if (i != 0) {
            if (!lft[i]) {
                lft[i] = pre;
            }
            stk.push(i);
            pre = i;
            i = left[i];
        } else {
            i = stk.top();
            stk.pop();
            i = right[i];
        }
    }
    PrintVector(lft);
    PrintVector(right);
}

void InOrderBothTag(const vector<int> &left, const vector<int> &right, int root) {
    stack<int> stk;
    vector<int> lft(left.begin(), left.end());
    vector<int> rgt(right.begin(), right.end());
    int i = root, ppre = 0, pre = 0;
    while (i != 0 || !stk.empty()) {
        if (i != 0) {
            stk.push(i);
            i = left[i];
        } else {
            i = stk.top();
            stk.pop();
            if (!lft[pre]) {
                lft[pre] = ppre;
            }
            if (!rgt[pre]) {
                rgt[pre] = i;
            }
            ppre = pre;
            pre = i;
            i = right[i];
        }
    }
    if (!lft[pre]) {
        lft[pre] = ppre;
    }
    PrintVector(lft);
    PrintVector(rgt);
}

void PostOrderPostTag(const vector<int> &left, const vector<int> &right, int root) {
    stack<int> stk;
    vector<int> rgt(right.begin(), right.end());
    int i = root, r = 0, pre = 0;
    while (i != 0 || !stk.empty()) {
        if (i != 0) {
            stk.push(i);
            i = left[i];
        } else {
            i = stk.top();
            if (right[i] != 0 && right[i] != r) {
                i = right[i];
                stk.push(i);
                i = left[i];
            } else {
                stk.pop();
                if (!rgt[pre]) {
                    rgt[pre] = i;
                }
                pre = r = i;
                i = 0;
            }
        }
    }
    PrintVector(left);
    PrintVector(rgt);
}

int main() {
    size_t n;
    cin >> n;
    
    vector<int> value(n + 1);
    vector<int> child(n + 1);
    vector<int> sibil(n + 1);
    for (size_t i = 1; i <= n; i++) {
        cin >> value[i] >> child[i] >> sibil[i];
    }

    vector<int> lft(n + 1, 1);
    vector<int> rgt(n + 1, 1);
    int root = Forest2Tree(child, sibil, lft, rgt, n);
    PreOrderPreTag(lft, rgt, root);
    InOrderBothTag(lft, rgt, root);
    PostOrderPostTag(lft, rgt, root);
    return 0;
}

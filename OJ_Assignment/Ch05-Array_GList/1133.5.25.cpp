#include <iostream>
#include <string>
#include <sstream>
using namespace std;

constexpr int max_len = 200;

struct OLNode {
    int i, j;
    int e;
    OLNode *right, *down;
    OLNode(int i, int j, int e): i(i), j(j), e(e) {
        right = down = nullptr;
    }
};
using OLink = OLNode*;

struct CrossList{
    OLink *rhead, *chead;
    int mu, nu, tu;

    CrossList() {
        mu = nu = tu = 0;
        rhead = chead = nullptr;
    }
    CrossList(int m, int n): mu(m), nu(n) {
        rhead = new OLink[m];
        chead = new OLink[n];
        for (int i = 0; i < m; i++) {
            rhead[i] = nullptr;
        }
        for (int i = 0; i < n; i++) {
            chead[i] = nullptr;
        }
        tu = 0;
    }

    void BuildMatrix(int *v, int len, int b[max_len][max_len]) {
        tu = len;
        int index = 0;
        OLNode *p = nullptr, *q = nullptr;
        for (int i = 0; i < mu; i++) {
            for (int j = 0; j < nu; j++) {
                if (b[i][j]) {
                    p = new OLNode(i, j, v[index++]);

                    if (rhead[i] == nullptr || rhead[i]->j > j) {
                        p->right = rhead[i];
                        rhead[i] = p;
                    } else {
                        for (q = rhead[i]; q->right != nullptr && q->right->j < j; q = q->right) {}
                        p->right = q->right;
                        q->right = p;
                    }

                    if (chead[j] == nullptr || chead[j]->i > i) {
                        p->down = chead[j];
                        chead[j] = p;
                    } else {
                        for(q = chead[j]; q->down != nullptr && q->down->i < i; q = q->down) {}
                        p->down = q->down;
                        q->down = p;
                    }
                }
            }
        }
    }

    //O(ta + tb)
    void operator += (const CrossList &B) {
        OLNode *pa = nullptr, *pb = nullptr, *pre = nullptr;
        OLNode *p = nullptr;
        OLink hl[nu];
        for (int i = 0; i < nu; i++) {
            hl[i] = chead[i];
        }
        for (int i = 0; i < mu; i++) {
            pa = rhead[i];
            pb = B.rhead[i];
            pre = nullptr;
            while (pb != nullptr) {
                if (pa == nullptr || pa->j > pb->j) {
                    p = new OLNode(pb->i, pb->j, pb->e);
                    if (pre == nullptr) {
                        rhead[p->i] = p;
                    } else {
                        pre->right = p;
                    }
                    p->right = pa;
                    pre = p;
                    if (chead[p->j] == nullptr || chead[p->j]->i > p->i) {
                        p->down = chead[p->j];
                        chead[p->j] = p;
                    } else {
                        p->down = hl[p->j]->down;
                        hl[p->j]->down = p;
                    }
                    hl[p->j] = p;
                    pb = pb->right;
                    tu++;
                } else if (pa != nullptr && pa->j < pb->j) {
                    pre = pa;
                    pa = pa->right;
                } else if (pa->j == pb->j) {
                    pa->e += pb->e;
                    if (pa->e == 0) {
                        if (pre == nullptr) {
                            rhead[pa->i] = pa->right;
                        } else {
                            pre->right = pa->right;
                        }
                        p = pa;
                        pa = pa->right;
                        if (chead[p->j] == p) {
                            chead[p->j] = hl[p->j] = p->down;
                        } else {
                            hl[p->j]->down = p->down;
                        }
                        delete p;
                        p = nullptr;
                        pb = pb->right;
                        tu--;
                    } else {
                        if (pre == nullptr) {
                            pre = rhead[pa->i];
                        } else {
                            pre = pre->right;
                        }
                        pa = pa->right;
                        pb = pb->right;
                    }
                }
            }
        }
    }

    void BuildOutput(int *arr, int &len, int b[max_len][max_len]) {
        OLNode *p = nullptr;
        int index = 0;
        for (int i = 0; i < mu; i++) {
            for (int j = 0; j < nu; j++) {
                b[i][j] = 0;
            }
        }
        for (int i = 0; i < mu; i++) {
            p = rhead[i];
            while (p != nullptr) {
                b[p->i][p->j] = 1;
                arr[index++] = p->e;
                p = p->right;
            }
        }
        len = index;
    }
};

int Str2Ints(string str, int *arr, int max_len) {
    int cnt = 0, tmp;
    stringstream ss(str);
    while (ss >> tmp) {
        arr[cnt++] = tmp;
    }
    return cnt;
}

int main(){    
    int v[max_len];
    int b[max_len][max_len];
    int len;
    string line;

    int m, n;
    cin >> m >> n;
    cin.ignore(max_len, '\n');
    CrossList m1(m, n);
    CrossList m2(m, n);

    getline(cin, line);
    len = Str2Ints(line, v, max_len);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    cin.ignore(max_len, '\n');
    m1.BuildMatrix(v, len, b);

    getline(cin, line);
    len = Str2Ints(line, v, max_len);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    m2.BuildMatrix(v, len, b);

    m1 += m2;

    m1.BuildOutput(v, len, b);

    if (len != 0) {
        for (int i = 0; i < len; i++) {
            cout << v[i] << (i == len - 1 ? '\n' : ' ');
        }
    } else {
        cout << endl;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << (j == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}

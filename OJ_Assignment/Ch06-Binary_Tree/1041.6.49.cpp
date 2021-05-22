#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool IsComplete(int index, const vector<int> &left, const vector<int> &right) {
    queue<int> que;
    int p = index;
    que.push(p);
    while (!que.empty()) {
        p = que.front();
        if (left[p] != -1 && right[p] != -1) {
            que.pop();
            que.push(left[p]);
            que.push(right[p]);
        }
        if (left[p] == -1 && right[p] != -1) {
            return false;
        }
        if (right[p] == -1) {
            if (left[p] != -1) {
                que.push(left[p]);
            }
            que.pop();
            while (!que.empty()) {
                p = que.front();
                if (left[p] == -1 && right[p] == -1) {
                    que.pop();
                } else {
                    return false;
                }
            }
            return true;
        }
    }
    return true;
}

int main() {
    string str;
    vector<int> left(1, 0);
    vector<int> right(1, 0);

    int lft, rgt;
    while (cin >> str >> lft >> rgt) {
        left.push_back(lft);
        right.push_back(rgt);
    }

    bool flg = IsComplete(1, left, right);
    if (flg) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
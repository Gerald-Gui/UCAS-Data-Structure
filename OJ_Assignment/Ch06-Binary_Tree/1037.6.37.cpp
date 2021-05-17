#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void PreOrderPrint(size_t index, const vector<string> &value,
                   const vector<int> &left, const vector<int> &right) {
    stack<size_t> stk;
    size_t p = index;
    while (p != -1 || !stk.empty()) {
        if (p != -1) {
            cout << value[p] << " ";
            stk.push(p);
            p = left[p];
        } else {
            p = stk.top();
            stk.pop();
            p = right[p];
        }
    }
    cout << endl;
}

int main() {
    vector<string> val(1, "");
    vector<int> left(1, 0);
    vector<int> right(1, 0);

    string str;
    int lft, rgt;
    while (cin >> str >> lft >> rgt) {
        val.push_back(str);
        left.push_back(lft);
        right.push_back(rgt);
    }

    PreOrderPrint(1, val, left, right);
    return 0;
}

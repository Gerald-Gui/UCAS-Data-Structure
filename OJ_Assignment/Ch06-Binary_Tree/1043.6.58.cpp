#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

void BuildVector(vector<int> &vec, const string &input) {
    int tmp;
    stringstream ss(input);
    while (ss >> tmp) {
        vec.push_back(tmp);
    }
}

void Insert(const int p,
            vector<int> &left, vector<int> &right,
            const vector<int> &xleft, const vector<int> &xright) {
    int tmp = left[p];
    while (left.size() < xleft[0]) {
        left.push_back(0);
        right.push_back(0);
    }
    left[p] = xleft[0];
    auto lit = xleft.cbegin() + 1;
    auto rit = xright.cbegin() + 1;
    while (lit != xleft.cend() && rit != xright.cend()) {
        left.push_back(*lit);
        right.push_back(*rit);
        lit++;
        rit++;
    }
    right[xleft[0]] = tmp;
}

void InOrderPrint(const vector<int> &left, const vector<int> &right) {
    stack<int> stk;
    int p = 1;
    while (p != 0 || !stk.empty()) {
        if (p != 0) {
            stk.push(p);
            p = left[p];
        } else {
            p = stk.top();
            cout << p << ' ';
            stk.pop();
            p = right[p];
        }
    }
    cout << endl;
}

int main() {
    int p;
    vector<int> left, right;
    vector<int> xleft, xright;
    string line;

    getline(cin, line);
    BuildVector(left, line);
    getline(cin, line);
    BuildVector(right, line);

    getline(cin, line);
    p = stoi(line);

    getline(cin, line);
    BuildVector(xleft, line);
    getline(cin, line);
    BuildVector(xright, line);

    Insert(p, left, right, xleft, xright);

    InOrderPrint(left, right);
    
    return 0;
}
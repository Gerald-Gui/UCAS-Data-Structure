#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void BuildVec(vector<int> &vec, string input) {
    int tmp;
    stringstream ss(input);
    while (ss >> tmp) {
        vec.push_back(tmp);
    }
}

bool Search(int root, const int &tar, const vector<int> &left, const vector<int> &right) {
    if (left[root] == tar || right[root] == tar) {
        return true;
    }
    if (left[root] != 0) {
        if (Search(left[root], tar, left, right)) {
            return true;
        }
    }
    if (right[root] != 0) {
        if (Search(right[root], tar, left, right)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> left, right;
    string line;
    getline(cin, line);
    BuildVec(left, line);
    getline(cin, line);
    BuildVec(right, line);

    int u, v;
    cin >> u >> v;
    if (Search(v, u, left, right)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
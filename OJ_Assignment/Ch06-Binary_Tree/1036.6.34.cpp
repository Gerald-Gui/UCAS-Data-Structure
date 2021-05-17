#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void BuildVector(vector<size_t> &vec, string line) {
    size_t tmp;
    stringstream ss(line);
    while (ss >> tmp) {
        vec.push_back(tmp);
    }
}

bool IsDescendant(const vector<size_t> &parent, size_t beg, size_t tar) {
    if (tar == 0) {
        return false;
    }
    for (size_t i = beg; i != 0; i = parent[i]) {
        if (i == tar) {
            return true;
        }
    }
    return false;
}

int main() {
    string line;
    vector<size_t> lft;
    vector<size_t> rgt;
    vector<size_t> prt;

    getline(cin, line);
    BuildVector(prt, line);
    getline(cin, line);
    BuildVector(lft, line);
    getline(cin, line);
    BuildVector(rgt, line);

    size_t u, v;
    cin >> u >> v;
    if (IsDescendant(prt, u, v)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}

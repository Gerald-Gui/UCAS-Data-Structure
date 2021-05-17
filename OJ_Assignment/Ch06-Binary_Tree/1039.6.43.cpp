#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void BuildVec(vector<int> &vec, string input) {
    int tmp;
    stringstream ss(input);
    while (ss >> tmp) {
        vec.push_back(tmp);
    }
}

void SwapChildren(int index, vector<int> &left, vector<int> &right) {
    swap(left[index], right[index]);
    if (left[index] != 0) {
        SwapChildren(left[index], left, right);
    }
    if (right[index] != 0) {
        SwapChildren(right[index], left, right);
    }
}

template <typename T>
void DisplayVector(const vector<T> &vec) {
    auto tail = vec.end() - 1;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (it == tail) {
            cout << *it << endl;
        } else {
            cout << *it << ' ';
        }
    }
}

int main() {
    vector<int> left, right;
    string line;
    getline(cin, line);
    BuildVec(left, line);
    getline(cin, line);
    BuildVec(right, line);

    SwapChildren(1, left, right);

    DisplayVector(left);
    DisplayVector(right);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void Line2Vec(vector<int> &vec, const string &str) {
    stringstream ss(str);
    int tmp;
    while (ss >> tmp) {
        vec.push_back(tmp);
    }
}

int main() {
    vector<int> vec1;
    vector<int> vec2;
    string line;

    getline(cin, line);
    Line2Vec(vec1, line);
    getline(cin, line);
    Line2Vec(vec2, line);

    auto it1 = vec1.cbegin();
    auto it2 = vec2.cbegin();
    while (it1 != vec1.cend() || it2 != vec2.cend()) {
        if (it1 == vec1.cend()) {
            printf("%d", *it2++);
            putchar(it2 == vec2.cend() ? '\n' : ' ');
        } else if (it2 == vec2.cend()) {
            printf("%d", *it1++);
            putchar(it1 == vec1.cend() ? '\n' : ' ');
        } else if (*it1 < *it2) {
            printf("%d ", *it1++);
        } else {
            printf("%d ", *it2++);
        }
    }
    
    return 0;
}

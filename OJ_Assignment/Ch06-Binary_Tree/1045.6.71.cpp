#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintNode(string val, int d) {
    for (int i = 0; i < d; i++) {
        cout << "-";
    }
    cout << val << endl;
}

void DisplayTree(int index, int depth,
                 const vector<int> &child, const vector<int> &sibil,
                 const vector<string> &val) {
    PrintNode(val[index], depth);
    int i = child[index];
    while (i != -1) {
        DisplayTree(i, depth + 1, child, sibil, val);
        i = sibil[i];
    }
}

int main() {
    vector<string> val(1, "");
    vector<int> child(1, 0);
    vector<int> sibil(1, 0);

    string str;
    int chi, sib;
    while (cin >> str >> chi >> sib) {
        val.push_back(str);
        child.push_back(chi);
        sibil.push_back(sib);
    }

    DisplayTree(1, 0, child, sibil, val);

    return 0;
}

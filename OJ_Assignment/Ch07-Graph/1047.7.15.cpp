#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef enum {IV, IA, DV, DA} OpType;

void InitMatrix(vector<vector<int>> &mtx, size_t vtxamt) {
    mtx.clear();
    mtx.assign(vtxamt, vector<int>(vtxamt, 0));
}

OpType Decode(const string &line, int &operand1, int &operand2) {
    stringstream ss(line);
    string token[3];
    ss >> token[0];
    if (token[0] == "IV" || token[0] == "DV") {
        ss >> token[1];
        operand1 = stoi(token[1]);
        return token[0][0] == 'I' ? IV : DV;
    } else {
        ss >> token[1] >> token[2];
        operand1 = stoi(token[1]);
        operand2 = stoi(token[2]);
        return token[0][0] == 'I' ? IA : DA;
    }
}

void InsertVex(vector<vector<int>> &mtx, int v) {
    if (v < 0 || v > mtx.size()) {
        return;
    }
    for (auto &vec : mtx) {
        vec.insert(vec.begin() + v, 0);
    }
    mtx.insert(mtx.begin() + v, vector<int>(mtx[0].size(), 0));
}

void InsertArc(vector<vector<int>> &mtx, int v, int w) {
    if (v < 0 || v >= mtx.size() || w < 0 || w >= mtx[0].size()) {
        return;
    }
    mtx[v][w] = mtx[w][v] = 1;
}

void DeleteVex(vector<vector<int>> &mtx, int v) {
    if (v < 0 || v > mtx.size()) {
        return;
    }
    for (auto &vec : mtx) {
        vec.erase(vec.begin() + v);
    }
    mtx.erase(mtx.begin() + v);
}

void DeleteArc(vector<vector<int>> &mtx, int v, int w) {
    if (v < 0 || v >= mtx.size() || w < 0 || w >= mtx[0].size()) {
        return;
    }
    mtx[v][w] = mtx[w][v] = 0;
}

void PrintMatrix(vector<vector<int>> &mtx) {
    for (const auto &vec : mtx) {
        for (auto cit = vec.cbegin(); cit != vec.cend(); cit++) {
            cout << *cit;
            if (cit != vec.cend() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mtx;
    size_t vtxamt;
    cin >> vtxamt;
    InitMatrix(mtx, vtxamt);
    for (size_t i = 0; i < mtx.size(); i++) {
        for (size_t j = 0; j < mtx[0].size(); j++) {
            cin >> mtx[i][j];
        }
    }
    for (char ch = cin.get(); ch != '\n'; ch = cin.get()) {}

    string line;
    int para1, para2;
    OpType op;
    while (getline(cin, line)) {
        op = Decode(line, para1, para2);
        switch (op) {
            case IV:
                InsertVex(mtx, para1);
                break;
            case IA:
                InsertArc(mtx, para1, para2);
                break;
            case DV:
                DeleteVex(mtx, para1);
                break;
            case DA:
                DeleteArc(mtx, para1, para2);
        }
    }
    PrintMatrix(mtx);
    return 0;
}

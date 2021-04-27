#include <string>
#include <iostream>
using namespace std;

void Replace(string &S, const string &T, const string &V) {
    int pos = 0;
    while ((pos = S.find(T, pos)) != string::npos) {
        S.erase(pos, T.length());
        S.insert(pos, V);
        pos += V.length();
    }
}

int main() {
    string S, T, V;
    cin >> S >> T >> V;
    Replace(S, T, V);
    cout << S << endl;
}

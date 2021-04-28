#include <iostream>
using namespace std;

void PrintTerm(const int coe, const int x_exp, const int y_exp, bool flg) {
    if (coe != 1 || (x_exp == 0 && y_exp == 0)) {
        cout << coe;
    }
    if (x_exp != 0) {
        cout << "xE" << x_exp;
    }
    if (y_exp != 0) {
        cout << "yE" << y_exp;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    bool flg = false;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (arr[i][j] != 0) {
                if (flg) {
                    cout << "+";
                }
                PrintTerm(arr[i][j], i, j, flg);
                flg = true;
            }
        }
    }
    cout << endl;

    return 0;
}

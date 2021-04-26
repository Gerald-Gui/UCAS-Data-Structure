#include <iostream>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    int arr[m][n];
    int min[m], max[n];
    for (int i = 0; i < m; i++) {
        min[i] = 0x7FFFFFFF;
    }
    for (int i = 0; i < n; i++) {
        max[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] < min[i]) {
                min[i] = arr[i][j];
            }
            if (arr[i][j] > max[j]) {
                max[j] = arr[i][j];
            }
        }
    }
    
    int res[m * n];
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == min[i] && arr[i][j] == max[j]) {
                res[cnt++] = arr[i][j];
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        cout << res[i] << (i == cnt - 1 ? "\n" : " ");
    }
    
    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

constexpr int max_len = 200;

int Str2Ints(char *str, int *arr, int str_len, int arr_len){
    char *p;
    int cnt = 0;
    if (str[0] != '\0') {
        arr[cnt++] = atoi(strtok(str, " "));
        while ((p = strtok(nullptr, " ")) != nullptr) {
            arr[cnt++] = atoi(p);
        }
    }
    return cnt;
}

int main() {
    int m, n;
    cin >> m >> n;
    char c;
    while ((c = cin.get()) != '\n') {}

    int v1[max_len], v2[max_len];
    int b1[m][n], b2[m][n];
    int len1 = 0, len2 = 0;
    char str[max_len];

    cin.getline(str, max_len);
    len1 = Str2Ints(str, v1, max_len, max_len);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b1[i][j];
        }
        while ((c = cin.get()) != '\n') {}
    }

    cin.getline(str, max_len);
    len2 = Str2Ints(str, v2, max_len, max_len);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b2[i][j];
        }
    }

    //O(m * n)
    int vres[max_len];
    int bres[m][n];
    int len_res = 0;
    int index1 = 0, index2 = 0;
    int tmp;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (b1[i][j] && b2[i][j]) {
                tmp = v1[index1++] + v2[index2++];
                if (tmp != 0) {
                    vres[len_res++] = tmp;
                    bres[i][j] = 1;
                } else {
                    bres[i][j] = 0;
                }
            } else if (b1[i][j] && !b2[i][j]) {
                vres[len_res++] = v1[index1++];
                bres[i][j] = 1;
            } else if (!b1[i][j] && b2[i][j]) {
                vres[len_res++] = v2[index2++];
                bres[i][j] = 1;
            } else {
                bres[i][j] = 0;
            }
        }
    }
    
    if (len_res != 0) {
        for (int i = 0; i < len_res; i++) {
            cout << vres[i] << (i == len_res - 1 ? '\n' : ' ');
        }
    } else {
        putchar('\n');
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << bres[i][j] << (j == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
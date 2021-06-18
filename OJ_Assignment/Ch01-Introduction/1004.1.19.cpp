#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const unsigned int maxint = 0xffffffff;

int main() {
    int n, arrsize;
    uint32_t * arr;

    cin >> n >> arrsize;
    if (n > arrsize || n <= 0) {
        printf("-1\n");
        return 0;
    }
    arr = new uint32_t[arrsize];
    memset(arr, 0, sizeof(uint32_t) * arrsize);

    arr[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1] > maxint / 2 / i) {
            printf("-1\n");
            return 0;
        } else {
            arr[i] = arr[i - 1] * 2 * i;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%u ", arr[i]);
    }
    printf("\n");

    return 0;
}
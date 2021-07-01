#include <cstdio>
#include <cstring>

int main() {
    int arr[4];
    memset(arr, 0, sizeof(arr));

    int tmp;
    while (scanf("%d", &tmp) == 1) {
        ++arr[tmp];
    }

    for (int i = 1; i < 4; ++i) {
        for (int j = 0; j < arr[i]; ++j) {
            printf("%d ", i);
        }
    }
    putchar('\n');

    return 0;
}

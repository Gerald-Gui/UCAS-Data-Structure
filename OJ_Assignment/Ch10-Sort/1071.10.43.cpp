#include <cstdio>
#include <cstring>

constexpr int MAXLEN = 1010;

int main() {
    int a[MAXLEN];
    int c[MAXLEN];
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));

    int len = 0;
    int tmp;
    while (scanf("%d", &tmp) == 1) {
        a[len++] = tmp;
    }

    for (int i = 0; i < len; ++i) {
        int cnt = 0;
        for (int j = 0; j < len; ++j) {
            if (i == j) {
                continue;
            }
            if (a[j] < a[i]) {
                ++cnt;
            }
        }
        c[i] = cnt;
    }

    for (int i = 0; i < len; ++i) {
        printf("%d%c", c[i], i == len - 1 ? '\n' : ' ');
    }

    return 0;
}

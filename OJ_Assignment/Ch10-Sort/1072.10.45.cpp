#include <cstdio>
#include <cstring>

int main() {
    int cnt[10010];
    memset(cnt, 0, sizeof(cnt));

    int tmp;
    while (scanf("%d", &tmp) == 1) {
        ++cnt[tmp];
    }

    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            printf("%d ", i);
        }
    }
    putchar('\n');

    return 0;
}

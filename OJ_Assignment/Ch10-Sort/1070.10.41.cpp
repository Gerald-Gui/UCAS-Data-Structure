#include <bits/stdc++.h>
using namespace std;

int main() {
    int tmp;
    int cnt[10000];
    memset(cnt, 0, sizeof(cnt));
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

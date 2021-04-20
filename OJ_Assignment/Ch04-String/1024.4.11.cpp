#include <cstdio>
#include <cstring>

constexpr int max_len = 200;

int main() {
    char s[max_len], t[max_len], r[max_len];
    int lens, lent, lenr = 0;
    int pos[max_len];
    memset(r, 0, max_len * sizeof(char));
    memset(pos, 0, max_len * sizeof(int));

    int i;
    char c;
    for (i = 0; (c = getchar()) != ' '; s[i++] = c) {}
    s[i] = '\0';
    lens = i;
    for (i = 0; (c = getchar()) != '\n'; t[i++] = c) {}
    t[i] = '\0';
    lent = i;

    bool flg;
    for (i = 0; i < lens; i++) {
        flg = true;
        for (int j = 0; j < i; j++) {
            if (s[j] == s[i]) {
                flg = false;
            }
        }
        if (flg) {
            r[lenr] = s[i];
            pos[lenr] = i;
            lenr++;
        }
    }

    for (i = 0; i < lenr; i++) {
        flg = true;
        for (int j = 0; j < lent; j++) {
            if (r[i] == t[j]) {
                flg = false;
            }
        }
        if (!flg) {
            pos[i] = r[i] = -1;
        }
    }

    int j;
    for (i = j = 0; j < lenr; j++) {
        while (r[j] == -1 && j < lenr) {
            j++;
        }
        if (j < lenr) {
            r[i] = r[j];
            pos[i] = pos[j];
            i++;
        }
    }
    r[i] = '\0';
    lenr = i;

    if (lenr == 0) {
        printf("-1\n");
    } else {
        printf("%s ", r);
        for (i = 0; i < lenr; i++) {
            printf("%d", pos[i]);
        }
        putchar('\n');
    }
    return 0;
}

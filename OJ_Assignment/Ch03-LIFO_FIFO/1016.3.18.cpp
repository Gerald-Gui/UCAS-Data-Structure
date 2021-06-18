#include <cstdio>

int main() {
    int flg = 0;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("%d\n", flg == 0 ? 1 : 0);
            flg = 0;
        } else if (c == '(') {
            ++flg;
        } else if (c == ')') {
            --flg;
        }
    }

    return 0;
}
#include <cstdio>

int main() {
    int flg = 0;
    char c, tmp;
    char stk[BUFSIZ];
    int sp = 0;

    while ((c = getchar()) != '@') {
        if (flg == 0) {
            if (c == '&') {
                flg = 1;
            } else {
                stk[sp++] = c;
            }
        } else if (flg == 1) {
            if (sp == 0) {
                printf("0\n");
                return 0;
            } else if (stk[sp - 1] == c) {
                --sp;
            }
        }
    }

    printf("%c\n", sp == 0 ? '1' : '0');

    return 0;
}
#include "find.h"

const void *find(const void *beg, const void *end, const void *tar, size_t n) {
    const char *p = beg;
    while (p != end) {
        if (memcmp(p, tar, n) == 0) {
            break;
        }
        p += n;
    }
    return p;
}

/*
#include <stdio.h>
int main() {
    int itar;
    char ctar;
    const char *str = "Hello, world";
    int arr[5] = {1, 2, 3, 4, 5};

    ctar = getchar();
    if (find(str, str + 13, &ctar, sizeof(char)) == str + 13) {
        puts("False");
    } else {
        puts("True");
    }

    scanf("%d", &itar);
    if (find(arr, arr + 5, &itar, sizeof(int)) == arr + 5) {
        puts("False");
    } else {
        puts("True");
    }

    return 0;
}
*/

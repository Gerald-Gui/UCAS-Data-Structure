#include <cstdio>
#include <cstring>
#include <cctype>

constexpr size_t maxlen = 100;

int main() {
    char listA[maxlen], listB[maxlen];
    int pa, pb;
    char c;

    memset(listA, 0, sizeof(listA));
    memset(listB, 0, sizeof(listB));
    pa = pb = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (isalpha(c)) {
            listA[pa++] = c;
        }
    }
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            listB[pb++] = c;
        }
    }
    
    for (int i = 0; i <= pa && i <= pb; ++i) {
        if (listA[i] < listB[i]) {
            printf("1\n");
            return 0;
        } else if(listA[i] > listB[i]) {
            printf("2\n");
            return 0;
        }
    }

    printf("0\n");
    return 0;
}
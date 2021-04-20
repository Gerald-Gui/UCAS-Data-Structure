#include <cstdio>
#include <cstring>

constexpr int maxlen = 100;

int main(){
    char str[maxlen];
    while (scanf("%s", str) == 1) {
        int i = 0, j = strlen(str) - 2;
        while (i < j) {
            if (str[i] != str[j]) {
                printf("0\n");
                break;
            }
            i++;
            j--;
        }
        if (i >= j) {
            printf("1\n");
        }
    }
    return 0;
}
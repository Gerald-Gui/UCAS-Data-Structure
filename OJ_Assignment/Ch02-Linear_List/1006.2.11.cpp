#include <iostream>
#include <cstdio>

constexpr int maxlen = 100;

using namespace std;

int main(){
    int va[maxlen];
    int i, j;

    for(i = 0; i < maxlen && cin >> va[i]; i++)
        ;
    int val = va[--i];
    for(j = 0; j < i && va[j] < val; j++)
        ;
    if(j != i)
        for(int k = i; k > j; k--)
            va[k] = va[k - 1];
    va[j] = val;

    for(j = 0; j <= i; j++)
        printf("%d ", va[j]);
    printf("\n");
    return 0;
}
// show how to use swap func in swap.h

#include "swap.h"

swap_ipl(int)
swap_ipl(float)
swap_ipl(char)

#include <stdio.h>

int main() {
    int a = 10, b = 20;
    float fa = 1.0, fb = 2.0;
    char ca = 'a', cb = 'A';

    swap(int)(&a, &b);
    swap(float)(&fa, &fb);
    swap(char)(&ca, &cb);

    printf("%d %d\n", a, b);
    printf("%f %f\n", fa, fb);
    printf("%c %c\n", ca, cb);
    return 0;
}
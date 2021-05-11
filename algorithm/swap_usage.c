// show how to use swap func in swap.h

#define swap(type, a, b) (swap_ ## type((a), (b)))

#define _type int
#define _func swap_int
#include "swap.h"

#define _type char
#define _func swap_char
#include "swap.h"

#define _type float
#define _func swap_float
#include "swap.h"

#include <stdio.h>

int main() {
    int a = 10, b = 20;
    float fa = 1.0, fb = 2.0;
    char ca = 'a', cb = 'A';

    swap(int, &a, &b);
    swap(float, &fa, &fb);
    swap(char, &ca, &cb);

    printf("%d %d\n", a, b);
    printf("%f %f\n", fa, fb);
    printf("%c %c\n", ca, cb);
    return 0;
}
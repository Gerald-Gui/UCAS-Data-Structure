#include "swap_on_byte.h"
#include <stdio.h>

// swap on bytes
void swap(void *pa, void *pb, size_t size) {
    while (size > 0) {
        size--;
        ((char*)pa)[size] = ((char*)pa)[size] ^ ((char*)pb)[size];
        ((char*)pb)[size] = ((char*)pa)[size] ^ ((char*)pb)[size];
        ((char*)pa)[size] = ((char*)pa)[size] ^ ((char*)pb)[size];
    }
}

// main func to show swap usage
//int main() {
//    int a = 10, b = 20;
//    float fa = 1.0, fb = 2.0;
//    char ca = 'a', cb = 'A';
//
//    swap(&a, &b, sizeof(int));
//    swap(&fa, &fb, sizeof(float));
//    swap(&ca, &cb, sizeof(char));
//
//    printf("%d %d\n", a, b);
//    printf("%f %f\n", fa, fb);
//    printf("%c %c\n", ca, cb);
//
//    return 0;
//}


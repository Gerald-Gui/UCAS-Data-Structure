#include "swap_on_byte.h"
#include <stdio.h>

// swap on bytes
void swap(byte_ptr pa, byte_ptr pb, size_t size) {
    for (size_t i = 0; i < size; i++) {
        pa[i] = pa[i] ^ pb[i];
        pb[i] = pa[i] ^ pb[i];
        pa[i] = pa[i] ^ pb[i];
    }
}

// main func to show swap usage
//int main() {
//    int a = 10, b = 20;
//    float fa = 1.0, fb = 2.0;
//    char ca = 'a', cb = 'A';
//
//    swap((byte_ptr)&a, (byte_ptr)&b, sizeof(int));
//    swap((byte_ptr)&fa, (byte_ptr)&fb, sizeof(float));
//    swap((byte_ptr)&ca, (byte_ptr)&cb, sizeof(char));
//
//    printf("%d %d\n", a, b);
//    printf("%f %f\n", fa, fb);
//    printf("%c %c\n", ca, cb);
//
//    return 0;
//}


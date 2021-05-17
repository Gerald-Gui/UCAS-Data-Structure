#include "fill.h"

void fill(void *beg, void *end, void *elem, size_t n) {
    char *p = beg;
    while (p != end) {
        memcpy(p, elem, n);
        p += n;
    }
}

// main func to show usage
//#include <stdlib.h>
//#include <stdio.h>
//int main() {
//    int arr[10] = {0};
//    int elem = 2;
//    fill(arr, arr + 10, &elem, sizeof(int));
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", arr[i]);
//    }
//    putchar('\n');
//
//    float *farr = malloc(20 * sizeof(float));
//    float f = 1.2;
//    fill(farr, farr + 20, &f, sizeof(float));
//    for (int i = 0; i < 20; i++) {
//        printf("%.1f ", farr[i]);
//    }
//    putchar('\n');
//    return 0;
//}

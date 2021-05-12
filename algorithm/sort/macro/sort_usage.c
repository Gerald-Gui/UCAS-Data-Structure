#include "quicksort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// swap won't be implemented by any sort methods
// DON'T forget to implement swap
swap_ipl(int);
quicksort_ipl(int);

int main() {
    srand((unsigned)time(NULL));
    int a = 10, b = 20;
    int arr[10];
    for (size_t i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }

    swap(int)(&a, &b);
    quicksort(int)(arr, 0, 9);
    for (size_t i = 0; i < 10; i ++) {
        printf("%3d ", arr[i]);
    }
    putchar('\n');
    
    return 0;
}
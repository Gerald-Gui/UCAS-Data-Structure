#include <utility>
#include <functional>
#include <iostream>

template <typename T>
void Swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T, typename _cmp>
void Sort(T arr[], size_t len, _cmp cmp) {
    if (len == 0) { return; }
    std::pair<size_t, size_t> *stk = new std::pair<size_t, size_t>[len];
    size_t sp = 0;
    stk[sp++] = {0, len - 1};
    while (sp != 0) {
        std::pair<size_t, size_t> tmp = stk[--sp];
        if (tmp.first >= tmp.second) { continue; }
        T mid = arr[(tmp.first + tmp.second) / 2];
        size_t left  = tmp.first;
        size_t right = tmp.second;
        do {
            while ((*cmp)(arr[left], mid))  { left++; }
            while ((*cmp)(mid, arr[right])) { right--;}
            if (left <= right) {
                Swap(arr[left], arr[right]);
                left++;
                right = right == 0 ? left - 1 : right - 1;
            }
        } while (left <= right);
        if (tmp.first < right) { stk[sp++] = {tmp.first, right}; }
        if (left < tmp.second) { stk[sp++] = {left, tmp.second}; }
    }
    delete[] stk;
}

#include <utility>
#include <cstdio>
#include <cstring>

constexpr int MAXLEN = 1010;

void CmpSort(int arr[], int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    switch (hi - lo) {
        case 1:
            if (arr[lo] > arr[hi]) { std::swap(arr[lo], arr[hi]); }
            break;
        case 2:
            int mid = lo + 1;
            if (arr[mid] < arr[lo] && arr[mid] < arr[hi]) {
                std::swap(arr[mid], arr[lo]);
            } else if (arr[hi] < arr[lo] && arr[hi] < arr[mid]) {
                std::swap(arr[hi], arr[lo]);
            }
            if (arr[mid] > arr[hi]) {
                std::swap(arr[mid], arr[hi]);
            }
    }
}

void QuickSort(int arr[], int len) {
    std::pair<int, int> *stk = new std::pair<int, int>[len];
    int sp = 0;
    stk[sp++] = {0, len - 1};
    while (sp != 0) {
        std::pair<int, int> tmp = stk[--sp];
        int l = tmp.first;
        int r = tmp.second;
        if (r - l < 3) {
            CmpSort(arr, l, r);
            continue;
        }
        int mid = (l + r) / 2;
        do {
            while (arr[l] < arr[mid]) { ++l; }
            while (arr[mid] < arr[r]) { --r; }
            if (l <= r) { std::swap(arr[l++], arr[r--]); }
        } while (l <= r);
        int len1 = r - tmp.first;
        int len2 = tmp.second - l;
        if (len1 < len2) {
            stk[sp++] = {l, tmp.second};
            stk[sp++] = {tmp.first, r };
        } else {
            stk[sp++] = {tmp.first, r };
            stk[sp++] = {l, tmp.second};
        }
    }
    delete[] stk;
}

int main() {
    int arr[MAXLEN];
    memset(arr, 0, sizeof(arr));

    int tmp;
    int i = 0;
    while (scanf("%d", &tmp) == 1) {
        arr[i++] = tmp;
    }

    QuickSort(arr, i);

    for (int j = 0; j < i; ++j) {
        printf("%d%c", arr[j], j == i - 1 ? '\n' : ' ');
    }

    return 0;
}

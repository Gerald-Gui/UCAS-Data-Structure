#include <cstdio>
#include <algorithm>

constexpr int MAXELEM = 1010;

struct Heap {
    int base[MAXELEM];
    int len;

private:
    inline int prt(int n) {
        return (n + 1) / 3;
    }
    inline int lft(int n) {
        return n * 3 - 1;
    }
    inline int mid(int n) {
        return n * 3;
    }
    inline int rgt(int n) {
        return n * 3 + 1;
    }
    void sink(int k) {
        int j = lft(k);
        while (j <= len) {
            int tar = j;
            if (j < len && base[j + 1] > base[tar]) {
                tar = j + 1;
            }
            if (j < len - 1 && base[j + 2] > base[tar]) {
                tar = j + 2;
            }
            j = tar;

            if (base[k] >= base[j]) {
                break;
            }
            std::swap(base[k], base[j]);
            k = j;
            j = lft(j);
        }
    }

public:
    Heap() : len(0) {}
    void init() {
        for (int i = len; i >= 1; --i) {
            sink(i);
        }
    }
    void add(int e) {
        base[++len] = e;
    }
    void pop() {
        std::swap(base[1], base[len]);
        --len;
        sink(1);
    }
    void sort() {
        while (len > 0) {
            pop();
        }
    }
    void Print(int size) {
        printf("%d", base[1]);
        for (int i = 2; i <= size; ++i) {
            printf(" %d", base[i]);
        }
        putchar('\n');
    }
};

int main() {
    int cnt = 0;
    int tmp;
    Heap heap;

    while (scanf("%d", &tmp) == 1) {
        heap.add(tmp);
        ++cnt;
    }
    heap.init();
    
    heap.sort();

    heap.Print(cnt);

    return 0;
}

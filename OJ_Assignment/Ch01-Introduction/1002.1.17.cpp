#include <iostream>

using namespace std;

int Fibonacci(int k, int m);

int main() {
    int k, m;
    cin >> k >> m;
    cout << Fibonacci(k, m) << endl;
    return 0;
}

int Fibonacci(int k, int m) {
    int i;
    int tmp = 0;
    if (m < k - 1) {
        return 0;
    }
    if (m == k - 1) {
        return 1;
    }
    for (i = 1; i <= k; ++i) {
        tmp += Fibonacci(k, m - i);
    }
    return tmp;
}

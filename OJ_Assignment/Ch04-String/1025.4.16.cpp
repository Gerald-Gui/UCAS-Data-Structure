#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

constexpr int max_len = 200;

int main(){
    char s[max_len], t[max_len];
    scanf("%s %s", s, t);
    int lens = strlen(s);
    int lent = strlen(t);

    for (int i = 0; s[i] != '\0' && t[i] != '\0'; i++) {
        if (s[i] != t[i]) {
            cout << (s[i] > t[i] ? 1 : -1) << endl;
            return 0;
        }
    }
    if (lens == lent) {
        cout << 0 << endl;
    } else {
        cout << (lens > lent ? 1 : -1) << endl;
    }
    return 0;
}

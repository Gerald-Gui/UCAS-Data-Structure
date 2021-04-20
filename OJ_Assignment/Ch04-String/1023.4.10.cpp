#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    for (string::iterator iti = str.begin(), itj = str.end() - 1; iti < itj; iti++, itj--) {
        swap(*iti, *itj);
    }
    cout << str << endl;
    return 0;
}

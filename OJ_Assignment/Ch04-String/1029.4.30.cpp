#include <iostream>
#include <string>
using namespace std;

string SubStr(string src, const size_t pos, const size_t len) {
    string sub = "";
    if (pos > src.size()) {
        return sub;
    }
    auto it = src.begin() + pos;
    while (it != src.end() && sub.size() < len) {
        sub += *it;
        it++;
    }
    return sub;
}

int main() {
    string str;
    getline(cin, str);

    for (auto len = str.size() - 1; len > 0; len--) {
        for (decltype(str.size()) j = 0; j + len <= str.size(); j++) {
            //string dest = str.substr(j, len);
            string dest = SubStr(str, j, len);
            for (decltype(str.size()) k = j + 1; k + len <= str.size(); k++) {
                //string tmp = str.substr(k, len);
                string tmp = SubStr(str, k, len);
                if (dest == tmp) {
                    cout << dest << " " << j << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}

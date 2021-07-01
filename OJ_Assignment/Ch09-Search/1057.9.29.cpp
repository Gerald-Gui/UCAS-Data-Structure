#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c, *p = nullptr;
    for (p = line; --lim > 0 && (c = fgetc(stream)) != EOF && c != '\n'; *p++ = c) {}
    *p = '\0';
    if (c == EOF && p != line) ungetc(c, stream);
    return c == EOF && p == line ? nullptr : line;
}

int main() {
    std::vector<int> tab;
    char line[BUFSIZ];
    
    for (char *p = strtok(fgetline(line, BUFSIZ, stdin), " "); p != nullptr; p = strtok(nullptr, " ")) {
        tab.push_back(atoi(p));
    }

    int tar;
    int t = 0;
    while (scanf("%d", &tar) == 1) {
        if (tar == tab[t]) {
            printf("1 ");
        } else if (tar < tab[0]) {
            printf("0 ");
        } else {
            int p = tar < tab[t] ? 0 : t;
            int hi = tar < tab[t] ? t : tab.size();
            bool flg = false;
            while (p < hi) {
                if (tab[p] == tar) {
                    flg = true;
                    break;
                }
                ++p;
            }
            printf(flg ? "1 " : "0 ");
            t = flg ? p : t;
        }
    }
    putchar('\n');

    return 0;
}

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

#define STRLEN 1000

char *fgetline(char *line, size_t lim, FILE *stream);
size_t Line2Vector(char *line, std::vector<int> &vec);
bool Cycle(int v, const std::vector<int> &s, const int *fst, const int *lst, int *visited);

int main() {
    char line[STRLEN];
    int n = atoi(fgetline(line, STRLEN, stdin));

    std::vector<int> s;
    Line2Vector(fgetline(line, STRLEN, stdin), s);

    int *fst = new int[n + 1];
    int *lst = new int[n + 1];
    fst[0] = lst[0] = 0;
    int i = 0;
    for (char *p = strtok(fgetline(line, STRLEN, stdin), " "); p != nullptr; p = strtok(nullptr, " ")) {
        fst[i++] = atoi(p);
    }
    i = 0;
    for (char *p = strtok(fgetline(line, STRLEN, stdin), " "); p != nullptr; p = strtok(nullptr, " ")) {
        lst[i++] = atoi(p);
    }

    int *visited = new int[n + 1];
    memset(visited, 0, (n + 1) * sizeof(int));

    bool flg = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && Cycle(i, s, fst, lst, visited)) {
            flg = true;
            break;
        }
    }
    printf("%s\n", flg ? "yes" : "no");

    return 0;
}

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c, *p = nullptr;
    for (p = line; --lim > 0 && (c = fgetc(stream)) != EOF && c != '\n'; *(p++) = c) {}
    *p = '\0';
    if (c == EOF && p != line) ungetc(c, stream);
    return c == EOF && p == line ? nullptr : line;
}

size_t Line2Vector(char *line, std::vector<int> &vec) {
    vec.clear();
    for (char *p = strtok(line, " "); p != nullptr; p = strtok(nullptr, " ")) {
        vec.push_back(atoi(p));
    }
    return vec.size();
}

bool Cycle(int v, const std::vector<int> &s, const int *fst, const int *lst, int *visited) {
    if (visited[v] == -1) {
        return true;
    }
    visited[v] = -1;
    for (int i = fst[v]; i < lst[v]; i++) {
        if (Cycle(s[i], s, fst, lst, visited)) {
            return true;
        }
    }
    visited[v] = 1;
    return false;
}

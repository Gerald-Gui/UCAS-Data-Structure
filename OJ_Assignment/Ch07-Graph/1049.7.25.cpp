#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ARR_INIT_SIZE 8
#define STR_LEN 1000

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c;
    char *p = NULL;
    for (p = line; --lim > 0 && (c = getchar()) != EOF && c != '\n'; p++) {
        *p = c;
    }
    *p = '\0';
    if (c == EOF && p == line) {
        return NULL;
    } else {
        if (c == EOF) {
            ungetc(c, stream);
        }
        return line;
    }
}

size_t *BuildDynamicArray(char *str, size_t *arr) {
    if (arr != nullptr) {
        free(arr);
    }
    arr = (size_t*)malloc(ARR_INIT_SIZE * sizeof(size_t));
    size_t arrsize = ARR_INIT_SIZE;
    char *p = strtok(str, " ");
    size_t i = 0;
    arr[i++] = atoi(p);
    while ((p = strtok(nullptr, " ")) != nullptr) {
        if (i >= arrsize) {
            arrsize <<= 1;
            arr = (size_t*)realloc(arr, arrsize);
        }
        arr[i++] = atoi(p);
    }
    return arr;
}

void Str2Arr(char *str, size_t *arr) {
    char *p = strtok(str, " ");
    size_t i = 0;
    arr[i++] = atoi(p);
    while ((p = strtok(nullptr, " ")) != nullptr) {
        arr[i++] = atoi(p);
    }
}

bool Cycle(const size_t i, const size_t *s, const size_t *fst, const size_t *lst, bool *visited, bool *visited_tmp) {
    visited[i] = true;
    if (visited_tmp[i]) {
        return true;
    }
    visited_tmp[i] = true;
    for (size_t j = fst[i]; j < lst[i]; j++) {
        if (Cycle(s[j], s, fst, lst, visited, visited_tmp)) {
            return true;
        }
    }
    visited_tmp[i] = false;
    return false;
}

int main() {
    size_t n;
    char line[STR_LEN];
    n = atoi(fgetline(line, STR_LEN, stdin));

    size_t *s = nullptr;
    size_t *fst = (size_t*)malloc((n + 1) * sizeof(size_t));
    size_t *lst = (size_t*)malloc((n + 1) * sizeof(size_t));
    s = BuildDynamicArray(fgetline(line, STR_LEN, stdin), s);
    
    Str2Arr(fgetline(line, STR_LEN, stdin), fst);
    Str2Arr(fgetline(line, STR_LEN, stdin), lst);

    bool *visited = (bool*)malloc((n + 1) * sizeof(bool));
    bool *visited_tmp = (bool*)malloc((n + 1) * sizeof(bool));
    for (size_t i = 0; i < n + 1; i++) {
        visited[i] = visited_tmp[i] = false;
    }

    bool flg = false;
    for (size_t i = 1; i <= n; i++) {
        if (!visited[i] && Cycle(i, s, fst, lst, visited, visited_tmp)) {
            flg = true;
            break;
        }
    }
    printf("%s\n", flg ? "yes" : "no");
    
    return 0;
}


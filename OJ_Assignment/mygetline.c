#include <stdio.h>

// ignore \n, ungetc EOF
// if read file end, return NULL
// otherwise return ptr line
char *mygetline(char *line, size_t lim) {
    size_t i = 0;
    char c;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    if (c == EOF && i == 0) {
        return NULL;
    } else if (c == EOF && i != 0) {
        ungetc(c, stdin);
        return line;
    } else {
        return line;
    }
}

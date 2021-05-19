#include <stdio.h>

// ignore \n, ungetc EOF
// if read file end, return NULL
// otherwise return the tail ptr of the string
// you can use the return value to calculate strlen easily
char *fgetline(char *line, size_t lim, FILE *stream) {
    char c;
    char *p = NULL;
    for (p = line; --lim > 0 && (c = getchar()) != EOF && c != '\n'; p++) {
        *p = c;
    }
    *p = '\0';
    if (c == EOF && p == line) {
        return NULL;
    } else if (c == EOF && p != line) {
        ungetc(c, stream);
        return p;
    } else {
        return p;
    }
}

#include <stdio.h>

// ignore \n, ungetc EOF
// if read file end, return NULL
// otherwise return line or p
// adjust the return value according to your wish
char *fgetline(char *line, size_t lim, FILE *stream) {
    char c, *p = NULL;
    for (p = line; --lim > 0 && (c = fgetc(stream)) != EOF && c != '\n'; *p++ = c) {}
    *p = '\0';
    if (c == EOF && p != line) ungetc(c, stream);
    return c == EOF && p == line ? NULL : line;
}

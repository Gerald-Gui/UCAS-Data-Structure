#include <stdio.h>

// ignore \n, ungetc EOF
// if read file end, return NULL
// otherwise return ptr line
char *fgetline(char *line, size_t lim, FILE *stream) {
    size_t i = 0;
    char c;
    while (--lim > 0 && (c = fgetc(stream)) != EOF && c != '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    if (c == EOF && i == 0) {
        return NULL;
    } else if (c == EOF && i != 0) {
        ungetc(c, stream);
        return line;
    } else {
        return line;
    }
}

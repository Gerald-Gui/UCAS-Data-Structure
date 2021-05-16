#include "KMP.h"

int *BuildNext(const char *str) {
    size_t len = strlen(str);
    size_t j = 0;
    size_t *next = malloc(len * sizeof(size_t));
    size_t t = next[0] = 0;
    while (j < len - 1) {
        if (t == 0 || str[j] == str[t]) {
            j++;
            t++;
            next[j] = str[j] != str[t] ? t : next[t];
        } else {
            t = next[t];
        }
    }
    return next;
}

size_t KMPIndex(const char *haystack, const char *needle, size_t pos) {
    size_t len_haystack = strlen(haystack);
    size_t len_needle = strlen(needle);
    size_t *next = BuildNext(needle);
    size_t j = pos;
    size_t k = 0;
    if (pos + len_needle > len_haystack) {
        free(next);
        return -1;
    }
    while (j < len_haystack && k < len_needle) {
        if (haystack[j] == needle[k]) {
            j++;
            k++;
        } else if (k > 0) {
            k = next[k - 1];
        } else {
            j++;
        }
    }
    free(next);
    if (k == len_needle) {
        return j - k;
    } else {
        return -1;
    }
}

#ifndef KMP_H
#define KMP_H

#include <string.h>
#include <stdlib.h>

int *BuildNext(const char *str);
size_t KMPIndex(const char *haystack, const char *needle, size_t pos);

#endif
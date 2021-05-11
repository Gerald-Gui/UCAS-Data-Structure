#ifndef SWAP_H
#define SWAP_H

#include <stddef.h>

typedef unsigned char byte;
typedef unsigned char *byte_ptr;

void swap(byte_ptr pa, byte_ptr pb, size_t size);

#endif

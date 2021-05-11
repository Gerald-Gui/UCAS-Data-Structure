#ifndef SWAP_H
#define SWAP_H

#define _swap(T) swap$_##T##_$
#define swap(T) _swap(T)

#define _swap_ipl(T) void swap(T)(T *a, T *b) {\
    T tmp = *a;\
    *a = *b;\
    *b = tmp;\
}
#define swap_ipl(T) _swap_ipl(T)

#endif

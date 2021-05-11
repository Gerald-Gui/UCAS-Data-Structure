void _func(_type *a, _type *b) {
    _type tmp = *a;
    *a = *b;
    *b = tmp;
}
#undef _type
#undef _func
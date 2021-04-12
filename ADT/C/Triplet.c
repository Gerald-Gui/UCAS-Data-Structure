#include <stdlib.h>
#include "Triplet.h"

//----------Function-----------

Status InitTriplet(Triplet * T, Elemtype v1, Elemtype v2, Elemtype v3){
    *T = (Elemtype *)malloc(3 * sizeof(Elemtype));
    if(*T == NULL)
        exit(OVERFLOW);
    (*T)[0] = v1;
    (*T)[1] = v2;
    (*T)[2] = v3;
    return OK;
}

Status DestroyTriplet(Triplet * T){
    free(*T);
    *T = NULL;
    return OK;
}

Status Get(Triplet T, int i, Elemtype * e){
    if(i < 1 || i > 3)
        return ERROR;
    *e = T[i-1];
    return OK;
}

Status Put(Triplet * T, int i, Elemtype e){
    if(i < 1 || i > 3)
        return ERROR;
    (*T)[i-1] = e;
    return OK;
}

Status IsAscending(Triplet T){
    return T[0] <= T[1] && T[1] <= T[2];
}

Status IsDescending(Triplet T){
    return T[0] >= T[1] && T[1] >= T[2];
}

Status Max(Triplet T, Elemtype * e){
    *e = T[0] >= T[1] ? (T[0] >= T[2] ? T[0] : T[2]) : (T[1] >= T[2] ? T[1] : T[2]);
    return OK;
}

Status Min(Triplet T, Elemtype * e){
    *e = T[0] <= T[1] ? (T[0] <= T[2] ? T[0] : T[2]) : (T[1] <= T[2] ? T[1] : T[2]);
    return OK;
}

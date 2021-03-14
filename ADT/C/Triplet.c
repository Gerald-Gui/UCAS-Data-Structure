#include <stdlib.h>

//--------Status macros--------
#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define INFEASIBLE  -1
#define OVERFLOW    -2

//------------Types------------
typedef int Status;
typedef int Elemtype;
typedef Elemtype *Triplet;

//--------Function List--------

    //initialize triplet with 3 elements
Status InitTriplet(Triplet * T, Elemtype v1, Elemtype v2, Elemtype v3);
    //destroy triplet
Status DestroyTriplet(Triplet * T);
    //return the ith element with e
Status Get(Triplet T, int i, Elemtype * e);
    //set the ith element with e
Status Put(Triplet * T, int i, Elemtype e);
    //judge whether elems are getting larger
Status IsAscending(Triplet T);
    //judge whether elems are getting smaller
Status IsDescending(Triplet T);
    //return the max element
Status Max(Triplet T, Elemtype * e);
    //return the min element
Status Min(Triplet T, Elemtype * e);

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
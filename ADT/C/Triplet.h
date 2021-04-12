#ifndef _TRIPLET_H
#define _TRIPLET_H

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

#endif

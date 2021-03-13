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

    //构造三元组T，元素e1,e2,e3分别赋值为v1,v2,v3
Status InitTriplet(Triplet * T, Elemtype v1, Elemtype v2, Elemtype v3);
    //销毁三元组T
Status DestroyTriplet(Triplet * T);
    //用e返回T的第i元
Status Get(Triplet T, int i, Elemtype * e);
    //改变T的第i元为e
Status Put(Triplet * T, int i, Elemtype e);
    //判断T的三个元素是否按升序排列
Status IsAscending(Triplet T);
    //判断T的三个元素是否按降序排列
Status IsDescending(Triplet T);
    //用e返回T的三个元素中最大值
Status Max(Triplet T, Elemtype * e);
    //用e返回T的三个元素中最小值
Status Min(Triplet T, Elemtype * e);

//----------Function-----------

Status InitTriplet(Triplet * T, Elemtype v1, Elemtype v2, Elemtype v3){
    *T = (Elemtype *)malloc(3 * sizeof(Elemtype));//分配内存空间
    if(*T == NULL)//分配空间失败
        exit(OVERFLOW);
    //元素赋值
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
    if(i < 1 || i > 3)//i不合法
        return ERROR;
    *e = T[i-1];
    return OK;
}

Status Put(Triplet * T, int i, Elemtype e){
    if(i < 1 || i > 3)//i不合法
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
#include <cstdlib>

const int overflow = 1;
const int list_init_size = 100;
const int list_increment = 10;

template <typename T>
struct SqList{
    T * elem;
    int len;
    int size;

    //initialize sequent list
    SqList(){
        elem = (T *)malloc(list_init_size * sizeof(T));
        if(elem == nullptr)
            exit(overflow);
        len = 0;
        size = list_init_size;
    }

    //destroy list
    void Destroy(){
        if(size == 0)
            return;
        free(elem);
        len = size = 0;
    }

    //set the list empty
    void Clear(){
        len = 0;
    }

    //judge whether the list is empty
    bool IsEmpty(){
        return len == 0;
    }

    //return the length of the list
    int ListLen(){
        return len;
    }

    //use e to return the ith element of list
    bool GetElem(int i, T & e){
        if(i < 1 || i > len)
            return false;
        e = elem[i - 1];
        return true;
    }

    //return the order of the first element meet cmp()
    int LocateElem(T e, bool (*cmp)(T data, T e)){
        int cnt = 1;
        T * p = elem;
        while(cnt <= len && (*cmp)(*p++, e) != 0)
            cnt++;
        if(cnt <= len)
            return cnt;
        return 0;
    }

    //use prior to return the former element of cur
    bool PriorElem(T cur, T & prior){
        int i = 0;
        while(cur != elem[i] && i < len)
            i++;
        if(i == len || i == 0)
            return false;
        prior = elem[i - 1];
        return true;
    }

    //use next to return the latter element of cur
    bool NextElem(T cur, T * next){
        int i = 0;
        while(cur != elem[i] && i < len)
            i++;
        if(i == len || i == len - 1)
            return false;
        next = elem[i + 1];
        return true;
    }

    //insert e before the ith element
    bool ListIns(int i, T e){
        if(i < 1 || i > len + 1)
            return false;
        if(len >= size){
            T * newbase = (T *)realloc(elem, (size + list_increment) * sizeof(T));
            if(newbase == nullptr)
                exit(overflow);
            elem = newbase;
            size += list_increment;
        }
        for(int j = len - 1; j >= i; j--)
            elem[j + 1] = elem[j];
        elem[i - 1] = e;
        len++;
        return true;
    }

    //delete the ith element and return it with e
    bool ListDel(int i, T & e){
        if(i < 1 || i > len)
            return false;
        e = elem[i - 1];
        for(i++; i < len - 1; i++)
            elem[i - 1] = elem[i];
        len--;
        return true;
    }
};

template <typename T>
void MergeList_Sq(SqList<T> La, SqList<T> Lb, SqList<T> & Lc){
    Lc.size = Lc.len = La.len + Lb.len;
    Lc.elem = (T *)malloc(Lc.size * sizeof(T));
    if(Lc.elem == NULL)
        exit(overflow);
    int i, j, k;
    for(i = j = k = 0; i <= La.len - 1 && j <= Lb.len - 1; k++)
        if(La.elem[i] <= Lb.elem[j])
            Lc.elem[k] = La.elem[i++];
        else
            Lc.elem[k] = Lb.elem[j++];        
    while(i <= La.len - 1)
        Lc.elem[k++] = La.elem[i++];
    while(j <= Lb.len - 1)
        Lc.elem[k++] = Lb.elem[j++];
}
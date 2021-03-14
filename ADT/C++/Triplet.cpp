#include <cstdlib>

const int overflow = 1;

template <typename T>
struct Triplet{
    T * arr;
    Triplet(){
        arr = nullptr;
    }
    Triplet(T v1, T v2, T v3){
        arr = (T *)malloc(sizeof(T));
        if(arr == nullptr)
            exit(overflow);
        arr[0] = v1;    arr[1] = v2;    arr[2] = v3;
    }
    void Destroy(){
        free(arr);
        arr = nullptr;
    }
    bool Get(int i, T & e){
        if(i < 1 || i > 3 || arr == nullptr)
            return false;
        e = arr[i - 1];
        return true;
    }
    bool Put(int i, T e){
        if(i < 1 || i > 3 || arr == nullptr)
            return false;
        arr[i - 1] = e;
        return true;
    }
    bool IsAscending(){
        return arr[0] <= arr[1] && arr[1] <= arr[2];
    }
    bool IsDescending(){
        return arr[0] >= arr[1] && arr[1] >= arr[2];
    }
    T Max(){
        return arr[0] >= arr[1] ? (arr[0] >= arr[2] ? arr[0] : arr[2]) : (arr[1] >= arr[2] ? arr[1] : T[2]);
    }
    T Min(){
        return arr[0] <= arr[1] ? (arr[0] <= arr[2] ? arr[0] : arr[2]) : (arr[1] <= arr[2] ? arr[1] : T[2]);
    }
};
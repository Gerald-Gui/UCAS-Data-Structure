#include <exception>

const int overflow = 1;

template <typename T>
struct Triplet{
    T * arr;
    //initialize an empty triplet
    Triplet();
    //initialize triplet with 3 elements
    Triplet(T v1, T v2, T v3);
    //destroy triplet
    ~Triplet();
    //return the ith element with e
    bool Get(int i, T & e);
    //set the ith element with e
    bool Put(int i, T e);
    //judge whether elems are getting larger
    bool IsAscending();
    //judge whether elems are getting smaller
    bool IsDescending();
    //return the max element
    T Max();
    //return the min element
    T Min();
};

template <typename T>
Triplet<T>::Triplet(){
    arr = nullptr;
}

template <typename T>
Triplet<T>::Triplet(T v1, T v2, T v3){
    try{
        arr = new T[3];
    }catch(std::bad_alloc){
        exit(overflow);
    }
    arr[0] = v1;    arr[1] = v2;    arr[2] = v3;
}

template <typename T>
Triplet<T>::~Triplet(){
    delete arr;
    arr = nullptr;
}

template <typename T>
bool Triplet<T>::Get(int i, T & e){
    if(i < 1 || i > 3 || arr == nullptr)
        return false;
    e = arr[i - 1];
    return true;
}

template <typename T>
bool Triplet<T>::Put(int i, T e){
    if(i < 1 || i > 3 || arr == nullptr)
        return false;
    arr[i - 1] = e;
    return true;
}

template <typename T>
bool Triplet<T>::IsAscending(){
    return arr[0] <= arr[1] && arr[1] <= arr[2];
}

template <typename T>
bool Triplet<T>::IsDescending(){
    return arr[0] >= arr[1] && arr[1] >= arr[2];
}

template <typename T>
T Max(){
    return arr[0] >= arr[1] ? (arr[0] >= arr[2] ? arr[0] : arr[2]) : (arr[1] >= arr[2] ? arr[1] : T[2]);
}

template <typename T>
T Min(){
    return arr[0] <= arr[1] ? (arr[0] <= arr[2] ? arr[0] : arr[2]) : (arr[1] <= arr[2] ? arr[1] : T[2]);
}

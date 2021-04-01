#include <cstdlib>

const int stack_init_size = 100;
const int stack_inc = 10;
const int overflow = 1;

template <typename T>
struct SqStack{
    T * data;
    int top;
    int size;

    //initialize an empty stack
    SqStack();
    //destroy stack
    ~SqStack();
    //set stack empty
    void Clear();    
    //judge whether stack is empty
    inline bool IsEmpty();
    //return the head elem with e if stack is not empty
    bool GetTop(T & e);
    //push elem into stack
    bool Push(T e);
    //delete the top elem and return it with e if stack is not empty
    bool Pop(T & e);
    //call func visit() from bottom to top
    bool Traverse(bool (*visit)(T e));
};

template <typename T>
SqStack<T>::SqStack(){
    if((data = (T *)malloc(stack_init_size * sizeof(T))) == nullptr)
        exit(overflow);
    top = 0;
    size = stack_init_size;
}

template <typename T>
SqStack<T>::~SqStack(){
    free(data);
    data = nullptr;
    top = size = 0;
}

template <typename T>
void SqStack<T>::Clear(){
    top = 0;
}

template <typename T>
inline bool SqStack<T>::IsEmpty(){
    return top == 0;
}

template <typename T>
bool SqStack<T>::GetTop(T & e){
    if(SqStack<T>::IsEmpty())
        return false;
    e = data[top - 1];
    return true;
}

template <typename T>
bool SqStack<T>::Push(T e){
    if(top >= size)
        if((data = (T *)realloc(data, (size += stack_inc) * sizeof(T))) == nullptr)
            exit(overflow);
    data[top++] = e;
    return true;
}

template <typename T>
bool SqStack<T>::Pop(T & e){
    if(SqStack<T>::IsEmpty())
        return false;
    e = data[--top];
    return true;
}

template <typename T>
bool SqStack<T>::Traverse(bool (*visit)(T e)){
    for(int i = 0; i < top; i++)
        if(!(*visit)(data[i]))
            return false;
    return true;
}

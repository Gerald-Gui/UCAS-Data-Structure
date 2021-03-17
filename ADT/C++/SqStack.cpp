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
    SqStack(){
        data = (T *)malloc(stack_init_size * sizeof(T));
        if(data == nullptr)
            exit(overflow);
        top = 0;
        size = stack_init_size;
    }

    //destroy stack
    ~SqStack(){
        free(data);
        data = NULL;
        top = size = 0;
    }

    //set stack empty
    void ClearStack(){
        top = 0;
    }
    
    //judge whether stack is empty
    inline bool IsEmpty(){
        return top == 0;
    }

    //return the head elem with e if stack is not empty
    bool GetTop(T & e){
        if(IsEmpty())
            return false;
        e = data[top - 1];
        return true;
    }

    //push elem into stack
    bool Push(T e){
        if(top >= size)
            if((data = (T *)realloc(data, (size += stack_inc) * sizeof(T))) == NULL)
                exit(overflow);
        data[top++] = e;
        return true;
    }

    //delete the top elem and return it with e if stack is not empty
    bool Pop(T & e){
        if(IsEmpty())
            return false;
        e = data[--top];
        return true;
    }

    //call func visit() from bottom to top
    bool Traverse(bool (*visit)(T e)){
        for(int i = 0; i < top; i++)
            if(!(*visit)(data[i]))
                return false;
        return true;
    }
};
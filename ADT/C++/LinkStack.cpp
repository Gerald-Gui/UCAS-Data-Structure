template <typename T>
struct ListNode{
    T val;
    ListNode<T> * pre;
    ListNode<T> * nxt;
    ListNode(){
        val = 0;
        pre = nxt = nullptr;
    }
    ListNode(T e): val(e){
        pre = nxt = nullptr;
    }
    ListNode(T e, ListNode<T> * prior, ListNode<T> * next): val(e), nxt(next), pre(prior) {}
};

template <typename T>
struct LinkStack{
    ListNode<T> * top;
    int len;

    //initialize an empty stack
    LinkStack();
    //set the stack empty(== destroy stack as no head node was used)
    ~LinkStack();
    //judge whether stack S is empty
    inline bool IsEmpty();
    //push elem into stack
    void Push(T e);
    //delete the top elem and return it with e if stack is not empty
    bool Pop(T & e);
    //return the head elem with e if stack is not empty
    bool GetTop(T & e);
    //call func visit() from bottom to top
    bool Traverse(bool (*visit)(T e));
};

template <typename T>
LinkStack<T>::LinkStack(){
    top = nullptr;
    len = 0;
}

template <typename T>
LinkStack<T>::~LinkStack(){
    T tmp;
    while(LinkStack<T>::Pop(tmp))
        ;
}

template <typename T>
inline bool LinkStack<T>::IsEmpty(){
    return top == nullptr;
}

template <typename T>
void LinkStack<T>::Push(T e){
    ListNode<T> * p = new ListNode<T>(e, nullptr, top);
    top->pre = p;
    top = p;
    len++;
}

template <typename T>
bool LinkStack<T>::Pop(T & e){
    if(LinkStack<T>::IsEmpty())
        return false;
    ListNode<T> * p = top;
    e = p->val;
    top = p->nxt;
    delete p;
    top->pre = p = nullptr;
    len--;
    return true;
}

template <typename T>
bool LinkStack<T>::GetTop(T & e){
    if(LinkStack<T>::IsEmpty())
        return false;
    e = top->val;
    return true;
}

template <typename T>
bool LinkStack<T>::Traverse(bool (*visit)(T e)){
    ListNode<T> * p = top;
    while(p->nxt != nullptr)
        p = p->nxt;
    while(p->pre != nullptr)
        if(!(*visit)(p->val))
            return false;
    return true;
}

template <typename T>
struct ListNode{
    T val;
    ListNode<T> * nxt;
    ListNode(){
        val = 0;
        nxt = nullptr;
    }
    ListNode(T e): val(e){
        nxt = nullptr;
    }
    ListNode(T e, ListNode<T> * p): val(e), nxt(p) {}
};

template <typename T>
struct LinkStack{
    ListNode<T> * top;
    int len;

    //initialize an empty stack
    LinkStack(){
        top = nullptr;
        len = 0;
    }

    //judge whether stack S is empty
    inline bool IsEmpty(){
        return top == nullptr;
    }

    //push elem into stack
    void Push(T e){
        ListNode<T> * p = new ListNode(e, top);
        top = p;
        len++;
    }

    //delete the top elem and return it with e if stack is not empty
    bool Pop(T & e){
        if(IsEmpty())
            return false;
        ListNode<T> * p = top;
        e = p->val;
        top = top->nxt;
        delete p;
        p = nullptr;
        len--;
        return true;
    }

    //set the stack empty(== destroy stack as no head node was used)
    ~LinkStack(){
        T e;
        while(Pop(e))
            ;
    }

    //return the head elem with e if stack is not empty
    bool GetTop(T & e){
        if(IsEmpty())
            return false;
        e = top->val;
        return true;
    }

    //call func visit() from bottom to top
    bool Traverse(bool (*visit)(T e)){
        LinkStack<T> * S = new LinkStack<T>;
        S->top = top->nxt;
        S->len = len - 1;
        if(S->IsEmpty())
            return true;
        if(!(S->Traverse(visit)))
            return false;
        if(!(*visit)(S.top->val))
            return false;
    }
};
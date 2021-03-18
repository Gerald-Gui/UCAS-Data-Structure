template <typename T>
struct ListNode{
    T val;
    ListNode<T> * nxt;
    ListNode(){
        val = 0;
        nxt = nullptr;
    }
    ListNode(T e): val(e) {
        nxt = nullptr;
    }
    ListNode(T e, ListNode<T> * p): val(e), nxt(p) {}
};

template <typename T>
struct LinkQueue{
    ListNode<T> * front;
    ListNode<T> * rear;

    //initialize an empty queue
    LinkQueue();
    //destroy queue Q
    ~LinkQueue();
    //set queue Q empty
    void Clear();
    //judge whether queue Q is empty
    inline bool IsEmpty();
    //return the num of elems in queue Q
    int QueueLength();
    //return the head elem of Q with e
    bool GetHead(T & e);
    //insert new elem e to tail of Q
    bool EnQueue(T e);
    //delete head elem of Q and return it with e
    bool DeQueue(T & e);
    //call func visit() from front to rear
    bool QueueTraverse_L(bool (*visit)(T e));

    LinkQueue(){
        front = rear = new ListNode<T>(0, nullptr);
    }
    
    ~LinkQueue(){
        ClearQueue();
        delete front;
        front = rear = nullptr;
    }
    
    void Clear(){
        T e;
        while(DeQueue(e))
            ;
    }
    
    inline bool IsEmpty(){
        return front == rear;
    }
    
    int Length(){
        ListNode<T> * p = front;
        int cnt;
        for(cnt = 0; p != rear; p = p->nxt)
            cnt++;
        return cnt;
    }
    
    bool GetHead(T & e){
        if(IsEmpty())
            return false;
        e = front->nxt->val;
        return true;
    }
    
    bool EnQueue(T e){
        rear->nxt = new ListNode<T>(e, nullptr);
        rear = rear->nxt;
        return true;
    }

    bool DeQueue(T & e){
        if(front == rear)
            return false;
        e = front->nxt->val;
        ListNode<T> * p = front;
        front = front->nxt;
        free(p);
        p = nullptr;
        return true;
    }
    
    bool Traverse(bool (*visit)(T e)){
        for(ListNode<T> * p = front->nxt; p != nullptr; p = p->nxt)
            if(!(*visit)(p->val))
                return false;
        return true;
    }
};
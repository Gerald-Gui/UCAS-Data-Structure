template <typename T>
struct ListNode{
    T val;
    ListNode<T> * nxt;
    ListNode(): val(0), nxt(nullptr) {}
    ListNode(T e): val(e), nxt(nullptr) {}
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
    int Length();
    //return the head elem of Q with e
    bool GetHead(T & e);
    //insert new elem e to tail of Q
    bool EnQueue(T e);
    //delete head elem of Q and return it with e
    bool DeQueue(T & e);
    //call func visit() from front to rear
    bool Traverse(bool (*visit)(T e));
};

template <typename T>
LinkQueue<T>::LinkQueue(){
    front = rear = new ListNode<T>(0, nullptr);
}

template <typename T>
LinkQueue<T>::~LinkQueue(){
    this->Clear();
    delete front;
    front = rear = nullptr;
}

template <typename T>
void LinkQueue<T>::Clear(){
    T tmp;
    while(this->DeQueue(tmp))
        ;
}

template <typename T>
inline bool LinkQueue<T>::IsEmpty(){
    return front == rear;
}

template <typename T>
int LinkQueue<T>::Length(){
    ListNode<T> * p = front;
    int cnt;
    for(cnt = 0; p != rear; p = p->nxt)
        cnt++;
    return cnt;
}

template <typename T>
bool LinkQueue<T>::GetHead(T & e){
    if(this->IsEmpty())
        return false;
    e = front->nxt->val;
    return true;
}

template <typename T>
bool LinkQueue<T>::EnQueue(T e){
    rear->nxt = new ListNode<T>(e, nullptr);
    rear = rear->nxt;
    return true;
}

template <typename T>
bool LinkQueue<T>::DeQueue(T & e){
    if(this->IsEmpty())
        return false;
    e = front->nxt->val;
    ListNode<T> * p = front;
    front = front->nxt;
    delete p;
    p = nullptr;
    return true;
}

template <typename T>
bool LinkQueue<T>::Traverse(bool (*visit)(T e)){
    for(ListNode<T> * p = front->nxt; p != nullptr; p = p->nxt)
        if(!(*visit)(p->val))
            return false;
    return true;
}

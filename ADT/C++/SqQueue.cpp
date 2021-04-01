const int max_queue_size = 100;

template <typename T>
struct LinkQueue{
    T * data;
    int front;
    int rear;

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
    data = new T[max_queue_size];
    front = rear = 0;
}

template <typename T>
LinkQueue<T>::~LinkQueue(){
    delete data;
    data = nullptr;
    front = rear = 0;
}

template <typename T>
void LinkQueue<T>::Clear(){
    front = rear = 0;
}

template <typename T>
inline bool LinkQueue<T>::IsEmpty(){
    return front == rear;
}

template <typename T>
int LinkQueue<T>::Length(){
    return (rear - front + max_queue_size) % max_queue_size;
}

template <typename T>
bool LinkQueue<T>::GetHead(T & e){
    if(LinkQueue<T>::IsEmpty())
        return false;
    e = data[front];
    return true;
}

template <typename T>
bool LinkQueue<T>::EnQueue(T e){
    if((rear + 1) % max_queue_size == front)
        return false;
    data[rear] = e;
    rear = (rear + 1) % max_queue_size;
    return true;
}

template <typename T>
bool LinkQueue<T>::DeQueue(T & e){
    if(front == rear)
        return false;
    e = data[front];
    front = (front + 1) % max_queue_size;
    return true;
}

template <typename T>
bool LinkQueue<T>::Traverse(bool (*visit)(T e)){
    for(int i = front; i != rear; i++){
        if(!(*visit)(data[front]))
            return false;
        front++;
        front %= max_queue_size;
    }
    return true;
}

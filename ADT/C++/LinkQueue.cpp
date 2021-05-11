#include <cstddef>

template <typename T>
class LinkQueue {
private:
    struct ListNode {
        T val;
        ListNode *nxt;
        ListNode(T data = 0, ListNode *ptr = nullptr) : val(data), nxt(ptr) {};
    };
    ListNode *front;
    ListNode *rear;

public:
    //initialize an empty queue
    LinkQueue();
    //destroy queue Q
    ~LinkQueue();
    //set queue Q empty
    void Clear();
    //judge whether queue Q is empty
    bool IsEmpty();
    //return the num of elems in queue Q
    size_t Length();
    //return the head elem of Q with e
    bool GetHead(T &dest);
    //insert new elem e to tail of Q
    void EnQueue(T src);
    //delete head elem of Q and return it with e
    bool DeQueue(T &dest);
    //call func visit() from front to rear
    bool Traverse(bool (*visit)(T elem));
};

template <typename T>
LinkQueue<T>::LinkQueue() {
    front = rear = new ListNode(0, nullptr);
}

template <typename T>
LinkQueue<T>::~LinkQueue() {
    this->Clear();
    delete front;
}

template <typename T>
void LinkQueue<T>::Clear() {
    ListNode *p = front->nxt;
    while (p != nullptr) {
        front->nxt = p->nxt;
        delete p;
        p = front->nxt;
    }
    rear = front;
}

template <typename T>
size_t LinkQueue<T>::Length() {
    size_t cnt = 0;
    ListNode *p = front;
    while (p != rear) {
        cnt++;
        p = p->nxt;
    }
    return cnt;
}

template <typename T>
inline bool LinkQueue<T>::IsEmpty() {
    return front == rear;
}

template <typename T>
bool LinkQueue<T>::GetHead(T &dest) {
    if (IsEmpty()) {
        return false;
    }
    dest = front->nxt->val;
    return true;
}

template <typename T>
inline void LinkQueue<T>::EnQueue(T src) {
    rear->nxt = new ListNode(src, nullptr);
    rear = rear->nxt;
}

template <typename T>
bool LinkQueue<T>::DeQueue(T &dest) {
    if (IsEmpty()) {
        return false;
    }
    dest = front->nxt->val;
    ListNode *p = front;
    front = front->nxt;
    delete p;
    return true;
}

template <typename T>
bool Traverse(bool (*visit)(T elem)) {
    for (ListNode *p = front->nxt; p != nullptr; p = p->nxt) {
        if (!(*visit)(p->val)) {
            return false;
        }
    }
    return true;
}

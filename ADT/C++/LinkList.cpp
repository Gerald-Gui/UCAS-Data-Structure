#include <iostream>
#include <new>
using namespace std;

template <typename T>
inline void DeletePtr(T * & ptr){
    delete ptr;
    ptr = nullptr;
}

template <typename T>
struct ListNode{
    T val;
    ListNode * nxt;
    ListNode(){
        val = 0;
        nxt = nullptr;
    }
    ListNode(T v): val(v) {
        nxt = nullptr;
    }
    ListNode(T v, ListNode * p): val(v), nxt(p) {}
};

template <typename T>
struct LinkList{
    ListNode<T> * head;
    int len;
    //initialize an empty link list
    LinkList();
    //destroy link list and free memory
    ~LinkList();
    //build a link list with n elems reversely inputed
    void CreateList(int n);
    //set the link list empty
    void ClearList();
    //insert a new node right after the head node
    void HeadIns(ListNode<T> * h, ListNode<T> * s);    
    //delete the first elem in link list
    bool HeadDel(ListNode<T> * h, ListNode<T> * & q);
    //return a pointer to the tail node
    ListNode<T> * GetLast();
    //return a pointer to the prior node of p
    ListNode<T> * PriorPos(ListNode<T> * p);
    //insert node s to the front of node p and point p to s
    bool InsBefore(ListNode<T> * & p, ListNode<T> * s); 
    //link s to the tail
    void Append(ListNode<T> * s);
    //remove the tail node and return it with q
    bool RemoveTail(ListNode<T> * & q);
    //return the ith elem with node p
    bool LocatePos(int i, ListNode<T> * & p);
};

template <typename T>
LinkList<T>::LinkList(){
    set_new_handler(abort);
    this->head = new ListNode<T>;
    this->len = 0;
}

template <typename T>
LinkList<T>::~LinkList(){
    this->ClearList();
    DeletePtr(head);
}

template <typename T>
void LinkList<T>::CreateList(int n){
    set_new_handler(abort);
    ListNode<T> * p = nullptr;
    while(n--){
        p = new ListNode<T>;
        cin >> p->val;
        this->HeadIns(this->head, p);
    }
    ////if build list in input order
    //p = head;
    //while(n--){
    //    p->nxt = new ListNode<T>;
    //    cin >> p->val;
    //    p->nxt->nxt = nullptr;
    //    p = p->nxt;
    //}
}

template <typename T>
void LinkList<T>::ClearList(){
    ListNode<T> * p = nullptr;
    while(this->HeadDel(this->head, p))
        DeletePtr(p);
}

template <typename T>
void LinkList<T>::HeadIns(ListNode<T> * h, ListNode<T> * s){
    s->nxt = h->nxt;
    h->nxt = s;
    this->len++;
}

template <typename T>
bool LinkList<T>::HeadDel(ListNode<T> * h, ListNode<T> * & q){
    if(this->len == 0)
        return false;
    q = h->nxt;
    h->nxt = h->nxt->nxt;
    this->len--;
    return true;
}

template <typename T>
ListNode<T> * LinkList<T>::GetLast(){
    ListNode<T> * p = this->head;
    while(p->nxt != nullptr)
        p = p->nxt;
    return p;
}

template <typename T>
ListNode<T> * LinkList<T>::PriorPos(ListNode<T> * p){
    ListNode<T> * q = this->head;
    while(q->nxt != p && q->nxt != nullptr)
        q = q->nxt;
    return q->nxt != p ? nullptr : q;
}

template <typename T>
bool LinkList<T>::InsBefore(ListNode<T> * & p, ListNode<T> * s){
    ListNode<T> * q = this->PriorPos(p);
    if(q == nullptr)
        return false;
    this->HeadIns(q, s);
    p = s;
    return true;
}

template <typename T>
void LinkList<T>::Append(ListNode<T> * s){
    ListNode<T> * p = this->GetLast();
    p->nxt = s;
    while(p->nxt != nullptr){
        p = p->nxt;
        this->len++;
    }
}

template <typename T>
bool LinkList<T>::RemoveTail(ListNode<T> * & q){
    if(this->len == 0)
        return false;
    q = this->GetLast();
    ListNode<T> * p = this->PriorPos(q);
    p->nxt = nullptr;
    this->len--;
    return true;
}

template <typename T>
bool LinkList<T>::LocatePos(int i, ListNode<T> * & p){
    int cnt = 0;
    ListNode<T> * q = head;
    if(i < 1 || i > this->len)
        return false;
    while(q != nullptr && cnt < i){
        q = q->nxt;
        cnt++;
    }
    if(q == nullptr || cnt > i)
        return false;
    p = q;
    return true;
}

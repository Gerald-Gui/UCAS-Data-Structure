#include <iostream>
using namespace std;

template <typename T>
struct DuListNode{
    T val;
    DuListNode * pre;
    DuListNode * nxt;
    DuListNode(){
        val = 0;
        pre = nxt = nullptr;
    }
    DuListNode(T v): val(v) {
        pre = nxt = nullptr;
    }
    DuListNode(T v, ListNode * prev, ListNode * next): val(v), pre(prev), nxt(next) {}
};

template <typename T>
struct DuLinkList{
    DuListNode<T> * head;
    int len;

    //initialize an empty double linked list
    DuLinkList(){
        head = new DuListNode<T>;
        len = 0;
    }

    //insert a new node right after the head node
    void HeadIns(DuListNode<T> * head, DuListNode<T> * s){
        s->nxt = head->nxt;
        if(len != 0)
            s->nxt->pre = s;
        head->nxt = s;
        s->pre = head;
        len++;
    }

    //delete the first elem in double link list
    bool HeadDel(DuListNode<T> * & q){
        if(len == 0)
            return false;
        q = head->nxt;
        if(len != 1)
            q->nxt->pre = head;
        head = q->nxt;
        len--;
        return true;
    }

    //return a pointer to the tail node
    DuListNode<T> * GetLast(){
        DuListNode<T> * p = head;
        while(p->nxt != nullptr)
            p = p->nxt;
        return p;
    }

    //return a pointer to the prior node of p
    DuListNode<T> * PriorPos(DuListNode<T> * p){
        DuListNode<T> * q = head;
        while(q->nxt != p && q->nxt != nullptr)
            q = q->nxt;
        if(q->nxt != p)
            return nullptr;
        return q;
    }

    //insert node s to the front of node p and point p to s
    bool InsBefore(DuListNode<T> * & p, DuListNode<T> * s){
        DuListNode<T> * q = PriorPos();
        if(q == nullptr)
            return false;
        HeadIns(q, s);
        p = s;
        return true;
    }

    //build a double link list with n elems reversely inputed
    void CreateList(int n){
        DuListNode<T> * p = nullptr;
        while(n--){
            p = new DuListNode<T>;
            cin >> p->val;
            HeadIns(head, p);
        }
        ////if build list in input order
        //p = head;
        //while(n--){
        //    p->nxt = new DuListNode<T>;
        //    cin >> p->val;
        //    p->nxt->nxt = nullptr;
        //    p->nxt->pre = p;
        //    p = p->nxt;
        //}
    }

    //set the double link list empty
    void ClearList(){
        DuListNode<T> * p = nullptr;
        while(HeadDel(p)){
            delete p;
            p = nullptr;
        }
    }

    //destroy double link list and free memory
    void DestroyList(){
        ClearList();
        delete head;
        head = nullptr;
    }

    //link a series of nodes headed with s to the tail
    void Append(DuListNode<T> * s){
        DuListNode<T> * p = GetLast();
        p->nxt = s;
        s->pre = p;
        for(; p->nxt != nullptr; p = p->nxt)
            len++;
    }

    //remove the tail node and return it with q
    bool RemoveTail(DuListNode<T> * & q){
        if(len == 0)
            return false;
        DuListNode<T> * p = head;
        while(p->nxt->nxt != nullptr)
            p = p->nxt;
        q = p->nxt;
        p->nxt = nullptr;
        len--;
        return true;
    }

    //return the ith elem with node p
    bool LocatePos(int i, DuListNode<T> ** p){
        if(i < 1 || i > len)
            return false;
        int cnt = 0;
        DuListNode<T> * q = head;
        while(q != nullptr && cnt < i){
            q = q->nxt;
            cnt++;
        }
        if(q == nullptr || cnt > i)
            return false;
        *p = q;
        return true;
    }
};
#include <iostream>
using namespace std;

template <typename T>
struct ListNode{
    T val;
    ListNode * nxt;
    ListNode(){
        val = 0;
        nxt = nullptr;
    }
    ListNode(T v): val(v){
        nxt = nullptr;
    }
    ListNode(T v, ListNode * p): val(v), nxt(p) {}
};

template <typename T>
struct CircularLinkList{
    ListNode<T> * head;
    int len;
    //initialize an empty circular linked list
    CircularLinkList(){
        head = new ListNode<T>;
        head->nxt = head;
        len = 0;
    }

    //insert a new node right after the head node
    void HeadIns(ListNode<T> * head, ListNode<T> * s){
        s->nxt = head->nxt;
        head->nxt = s;
        len++;
    }

    //delete the first elem in circular link list
    bool HeadDel(ListNode<T> * & q){
        if(len == 0)
            return false;
        q = head->nxt;
        head->nxt = head->nxt->nxt;
        len--;
        return true;
    }

    //return a pointer to the tail node
    ListNode<T> * GetLast(){
        ListNode<T> * p = head;
        while(p->nxt != head)
            p = p->nxt;
        return p;
    }

    //return a pointer to the prior node of p
    ListNode<T> * PriorPos(ListNode<T> * p){
        ListNode<T> * q = head;
        while(q->nxt != p && q->nxt != head)
            q = q->nxt;
        if(q->nxt != p)
            return nullptr;
        return q;
    }

    //insert node s to the front of node p and point p to s
    bool InsBefore(ListNode<T> ** p, ListNode<T> * s){
        ListNode<T> * q = PriorPos(*p);
        if(q == nullptr)
            return false;
        HeadIns(q, s);
        *p = s;
        return true;
    }

    //build a circular link list with n elems reversely inputed
    void CreateList(int n){
        ListNode<T> * p = nullptr;
        while(n--){
            p = new ListNode<T>;
            cin >> p->val;
            HeadIns(head, p);
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

    //set the circular link list empty
    void ClearList(){
        ListNode<T> * p = nullptr;
        while(HeadDel(p)){
            delete p;
            p = nullptr;
        }
    }

    //destroy circular link list and free memory
    void DestroyList(){
        ClearList();
        delete head;
        head = nullptr;
    }

    //link a series of node headed with s to the tail
    void Append(ListNode<T> * s){
        ListNode<T> * p = GetLast();
        p->nxt = s;
        while(p->nxt != nullptr){
            p = p->nxt;
            len++;
        }
        p->nxt = head;
    }

    //remove the tail node and return it with q
    bool RemoveTail(ListNode<T> * & q){
        if(len == 0)
            return false;
        ListNode<T> * p = head;
        while(p->nxt->nxt != nullptr)
            p = p->nxt;
        HeadDel(q);
        return true;
    }

    //return a pointer to the prior node of p
    ListNode<T> * PriorPos(ListNode<T> * p){
        ListNode<T> * q = head;
        while(q->nxt != p && q->nxt != head)
            q = q->nxt;
        if(p == head)
            return q;
        if(q->nxt != p)
            return nullptr;
        return q;
    }

    //insert node s to the front of node p and point p to s
    bool InsBefore(ListNode<T> * & p, ListNode<T> * s){
        ListNode<T> * q = head;
        if((q = PriorPos(p)) != nullptr)
            return false;
        HeadIns(q, s);
        p = s;
        return true;
    }

    //return the ith elem with node p
    bool LocatePos(int i, ListNode<T> ** p){
        if(i < 1 || i > len)
            return false;
        int cnt = 0;
        ListNode<T> * q = head;
        while(q != head && cnt > i){
            q = q->nxt;
            cnt++;
        }
        if(q == head || cnt > i)
            return false;
        *p = q;
        return true;
    }
};
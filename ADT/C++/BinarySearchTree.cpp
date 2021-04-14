#include <vector>
using namespace std;

template <typename T>
struct BSTNode{
    T val;
    BSTNode<T> left;
    BSTNode<T> right;
    BSTNode(T data = 0): val(data) {
        left = right = nullptr;
    }

    //create a BST with array
    bool BuildBST(T * arr, int len);
    //create a BST with array
    bool BuildBST(vector<T> vec);
    //search target elem in BST
    BSTNode<T> * Search(T tar);
    //insert a new node into BST
    bool Insert(T elem);
    //delete this node from BST
    bool Delete();
    //delete a node from BST according to tar
    bool Delete(T tar);
    //destroy the BST
    void Destroy();
};

template <typename T>
bool BSTNode<T>::BuildBST(T * arr, int len){
    this = nullptr;
    for(int i = 0; i < len; i++)
        if(!this->Insert(arr[i])){
            this->Destroy();
            return false;
        }
    return true;
}

template <typename T>
bool BSTNode<T>::BuildBST(vector<T> vec){
    this = nullptr;
    for(int i = 0; i < vec.size(); i++)
        if(!this->Insert(vec[i])){
            this->Destroy();
            return false;
        }
    return true;
}

template <typename T>
bool BSTNode<T>::Insert(T elem){
    if(this == nullptr){
        this = new BSTNode<T>(elem);
        return true;
    }else if(elem == this->val)
        return false;
    else if(elem < this->val)
        return this->left->Insert(elem);
    else
        return this->right->Insert(elem);
}

template <typename T>
BSTNode<T> * BSTNode<T>::Search(T tar){
    BSTNode<T> * p = this;
    while(p != nullptr && p->val != tar)
        if(tar < p->val)
            p = p->left;
        else
            p = p->right;
    return p;
}

template <typename T>
bool BSTNode<T>::Delete(){
    BSTNode<T> * q = nullptr, * s = nullptr;
    if(this == nullptr)
        return false;
    if(this->right == nullptr){
        q = this;
        this = this->left;
        delete q;
        q = nullptr;
    }else if(this->left == nullptr){
        q = this;
        this = this->right;
        delete q;
        q = nullptr;
    }else{
        q = this;
        s = this->left;
        while(s->right != nullptr){
            q = s;
            s = s->right;
        }
        this->val = s->val;
        if(q != this)
            q->right = s->left;
        else
            q->left = s->left;
        delete s;
        s = nullptr;
    }
    return true;
}

template <typename T>
bool BSTNode<T>::Delete(T tar){
    if(this == nullptr)
        return false;
    else
        if(tar == this->val)
            return this->Delete();
        else if(tar < this->val)
            return this->left->Delete(tar);
        else
            return this->right->Delete(tar);    
}

template <typename T>
void BSTNode<T>::Destroy(){
    while(this->Delete())
        ;
}

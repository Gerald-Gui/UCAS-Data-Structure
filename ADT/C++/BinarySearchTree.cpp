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

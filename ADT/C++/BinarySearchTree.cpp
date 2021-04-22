#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
struct BSTNode{
    T val;
    BSTNode<T> left;
    BSTNode<T> right;
    BSTNode(T data = 0): val(data) {
        left = right = nullptr;
    }
};

template <typename T>
struct BSTree {
    BSTNode<T> *root;

    BSTree() {
        root = nullptr;
    }
    BSTree(T *arr, int len);
    BSTree(vector<T> vec);
    BSTNode<T> *Search(T tar);
    bool Insert(T elem);
    bool Delete(T tar);
    static BSTNode<T> *Destroy(BSTNode<T> *p);
};

template <typename T>
BSTree<T>::BSTree(T *arr, int len) {
    for (int i = 0; i < len; i++) {
        this->Insert(arr[i]);
    }
}

template <typename T>
bool BSTree<T>::Insert(T elem) {
    if (root == nullptr) {
        root = new BSTNode<T>(elem);
        return true;
    }
    BSTNode<T> *p = root;
    while ((p->left != nullptr && p->val > elem) || (p->right != nullptr && p->val < elem)) {
        p = p->val > elem ? p->left : p->right;
    }
    if (p->left == nullptr && p->val > elem) {
        p->left = new BSTNode<T>(elem);
    } else if (p->right == nullptr && p->val < elem) {
        p->right = new BSTNode<T>(elem);
    } else if (p->val == elem) {
        return false;
    }
    return true;
}

template <typename T>
BSTNode<T>* BSTree<T>::Search(T tar) {
    BSTNode<T> *p = root;
    while (p != nullptr && p->val != tar) {
        p = p->val > tar ? p->left : p->right;
    }
    return p;
}

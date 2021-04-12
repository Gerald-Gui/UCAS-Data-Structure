#include <iostream>
using namespace std;

template <typename T>
struct BinaryTNode{
    T val;
    BinaryTNode<T> * left;
    BinaryTNode<T> * right;
};

template <typename T>
bool InitBinaryTree(BinaryTNode<T> * root, T e){
    if(root != nullptr){
        DestroyBinaryTree(root);
        root = nullptr;
    }
    root = new BinaryTNode<T>;
    root->val = e;
    root->left = root->right = nullptr;
    return true;
}

void CreateBinaryTree(BinaryTNode<char> ** root){
    char elem;
    cin >> elem;
    if(elem == ' ')
        *root = NULL;
    else{
        *root = new BinaryTNode<char>;
        (*root)->val = elem;
        CreateBinaryTree(&((*root)->left));
        CreateBinaryTree(&((*root)->right));
    }
}

template <typename T>
bool PreOrderTraverse(BinaryTNode<T> * root, bool (*visit)(T e)){
    if(root == nullptr)
        return true;
    if(!(*visit)(root->val))
        return false;    
    if(!PreOrderTraverse(root->left, visit))
        return false;
    if(!PreOrderTraverse(root->right, visit))
        return false;
}

template <typename T>
bool InOrderTraverse(BinaryTNode<T> * root, bool (*visit)(T e)){
    if(root == nullptr)
        return true;
    if(!InOrderTraverse(root->left, visit))
        return false;
    if(!(*visit)(root->val))
        return false;
    if(!InOrderTraverse(root->left, visit))
        return false;
}

template <typename T>
bool PostOrderTraverse(BinaryTNode<T> * root, bool (*visit)(T e)){
    if(root == nullptr)
        return true;
    if(!PostOrderTraverse(root->left, visit))
        return false;
    if(!PostOrderTraverse(root->right, visit))
        return false;
    if(!(*visit)(root->val))
        return false;
}

template <typename T>
void DestroyBinaryTree(BinaryTNode<T> * root){
    if(root == nullptr)
        return;
    DestroyBinaryTree(root->left);
    DestroyBinaryTree(root->right);
    delete root;
    root = nullptr;
}

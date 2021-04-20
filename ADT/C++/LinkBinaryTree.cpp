#include <iostream>
#include <stack>
#include <queue>
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
/* recursive way
 *  if(root == nullptr)
 *      return true;
 *  if(!(*visit)(root->val))
 *      return false;    
 *  if(!PreOrderTraverse(root->left, visit))
 *      return false;
 *  if(!PreOrderTraverse(root->right, visit))
 *      return false;
 */
    stack<BinaryTNode<T> *> S;
    BinaryTNode<T> * p = root;
    while(p != nullptr || !S.empty())
        if(p != nullptr){
            if(!(*visit)(p->val))
                return false;
            S.push(p);
            p = p->left;
        }else{
            p = S.top();
            S.pop();
            p = p->right;
        }
    return true;
}

template <typename T>
bool InOrderTraverse(BinaryTNode<T> * root, bool (*visit)(T e)){
/*
 *  if(root == nullptr)
 *      return true;
 *  if(!InOrderTraverse(root->left, visit))
 *      return false;
 *  if(!(*visit)(root->val))
 *      return false;
 *  if(!InOrderTraverse(root->left, visit))
 *      return false;
 */
    stack<BinaryTNode<T> *> S;
    BinaryTNode<T> * p = root;
    while(p != nullptr || !S.empty())
        if(p != nullptr){
            S.push(p);
            p = p->left;
        }else{
            p = S.top();
            S.pop();
            if(!(*visit)(p->val))
                return false;
            p = p->right;
        }
    return true;
}

template <typename T>
bool PostOrderTraverse(BinaryTNode<T> * root, bool (*visit)(T e)){
/* recursive way
 *  if(root == nullptr)
 *      return true;
 *  if(!PostOrderTraverse(root->left, visit))
 *      return false;
 *  if(!PostOrderTraverse(root->right, visit))
 *      return false;
 *  if(!(*visit)(root->val))
 *      return false;
 */
    stack<BinaryTNode<T> *> S;
    BinaryTNode<T> * p = root, * r = nullptr;
    while(p != nullptr || !S.empty())
        if(p != nullptr){
            S.push(p);
            p = p->left;
        }else{
            p = S.top();
            if(p->right != nullptr && p->right != r){
                p = p->right;
                S.push(p);
                p = p->left;
            }else{
                S.pop();
                if(!(*visit)(p->val))
                    return false;
                r = p;
                p = nullptr;
            }
        }
    return true;
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

template <typename T>
bool LevelOrderTraverse(BinaryTNode<T> * ptree, bool (*visit)(T e)){
    queue<BinaryTNode<T> *> Q;
    BinaryTNode<T> * p = nullptr;
    Q.push(ptree);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        if(!(*visit)(p->val))
            return false;
        if(p->left != nullptr)
            Q.push(p->left);
        if(p->right != nullptr)
            Q.push(p->right);
    }
    return true;
}
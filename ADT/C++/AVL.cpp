#include <algorithm>
using namespace std;

template <typename T>
struct AVLNode {
    T val;
    AVLNode *left;
    AVLNode *right;
    int height;
};

template <typename T>
inline int GetHeight(AVLNode<T> *p) {
    return p == nullptr ? -1 : p->height;
}

template <typename T>
inline void UpdateHeight(AVLNode<T> *p) {
    p->height = p == nullptr ? -1 : max(GetHeight(p->left), GetHeight(p->right)) + 1;
}

template <typename T>
int UpdateHeightFrom(AVLNode<T> *p) {
    if(p == nullptr)
        return -1;
    return p->height = max(UpdateHeightFrom(p->left), UpdateHeightFrom(p->right)) + 1;
}

template <typename T>
AVLNode<T> *SingleRightRotate(AVLNode<T> *p) {
    AVLNode<T> *lc = p->left;
    p->left = lc->right;
    lc->right = p;
    UpdateHeight(p);
    UpdateHeight(lc);
    return lc;
}

template <typename T>
AVLNode<T> *SingleLeftRotate(AVLNode<T> *p) {
    AVLNode<T> *rc = p->right;
    p->right = rc->left;
    rc->right = p;
    UpdateHeight(p);
    UpdateHeight(rc);
    return rc;
}
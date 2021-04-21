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
    rc->left = p;
    UpdateHeight(p);
    UpdateHeight(rc);
    return rc;
}

template <typename T>
int GetBalanceFactor(AVLNode<T> *p) {
    if (p == nullptr) {
        return 0;
    }
    return GetHeight(p->left) - GetHeight(p->right);
}

template <typename T>
AVLNode<T> *ReBalance(AVLNode<T> *p) {
    int bf  = GetBalanceFactor(p);
    int lbf = GetBalanceFactor(p->left);
    int rbf = GetBalanceFactor(p->right);
    if (bf > 1) {
        if (lbf <= 0) {
            p->left = SingleLeftRotate(p->left);
        }
        return SingleRightRotate(p);
    } else if (bf < -1) {
        if (rbf > 0) {
            p->right = SingleRightRotate(p->right);
        }
        return SingleLeftRotate(p);
    } else {
        return p;
    }
}
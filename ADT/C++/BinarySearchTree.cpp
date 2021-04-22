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
    //display the BST (traverse output nodes in In Order)
    void Display();
    //display the BST (using recursive way)
    void rDisplay();
};

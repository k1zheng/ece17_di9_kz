//
// Created by kayre on 11/27/2023.
//
#include <iostream>
using namespace std;

#ifndef DISCUSSION9_BINARYTREE_H
#define DISCUSSION9_BINARYTREE_H
//class-generate-generate dfinitions
class BinaryTree {
private:
    struct Node {
        int val;
        Node *left;
        Node *right;
    };

    int clean;

    Node* root;
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);

public:
    BinaryTree(int clean, Node *root);

    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);

    void displayInOrder(Node* aNodePtr){
        if(aNodePtr){
            displayInOrder(aNodePtr->left);
            cout << aNodePtr->val << " ";
            displayInOrder(aNodePtr->right);
        }
    };

    void printTree(){
        displayInOrder(root);
        cout << endl;
    };
};
#endif //DISCUSSION9_BINARYTREE_H

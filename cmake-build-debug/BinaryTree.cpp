//
// Created by kayre on 11/27/2023.
//

#include "BinaryTree.h"

void BinaryTree::insert(BinaryTree::Node *&aNodePtr, BinaryTree::Node *&aNewNodePtr) {
    if (aNodePtr == nullptr){
        aNodePtr == aNewNodePtr;
    }
    else if( aNewNodePtr ->val < aNodePtr -> val){
        insert(aNodePtr -> left, aNewNodePtr);
    }
    else{
        insert(aNodePtr -> right, aNewNodePtr);
    }
}

void BinaryTree::deleteNode(int aVal, BinaryTree::Node *&aNodePtr) {
    if (aVal < aNodePtr->val){
        deleteNode(aVal, aNodePtr->left);
    }
    else if (aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    }
    else{ //if the value is found
        makeDeletion(aNodePtr);
    }
}

void BinaryTree::makeDeletion(BinaryTree::Node *&aNodePtr) {
    Node* tempNodePtr = nullptr;

    if(aNodePtr == nullptr){
        std::cout << "Cannot remove empty Node" << std::endl;
    }
    else if(aNodePtr->right == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else if(aNodePtr->left == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete tempNodePtr;
    }
    else{
        tempNodePtr = aNodePtr->right;

        while(tempNodePtr->left){
            tempNodePtr=tempNodePtr->left;
        }

        tempNodePtr->left=aNodePtr->left;

        tempNodePtr=aNodePtr;
        aNodePtr=tempNodePtr->right;
    }
}

BinaryTree::BinaryTree(int clean, BinaryTree::Node *root) {
    //return false;
}

void BinaryTree::BinaryTree() {
    //return 0;
}

void BinaryTree::insertNode(int aVal) {
    Node* newNode = new Node(aVal);
    insert(root,newNode);
}

bool BinaryTree::searchNode(int aVal) {
    Node* currentNode = root;

    while(currentNode){
        if(currentNode->val == aVal){
            return true;
        }
        else if (aVal < currentNode->val){
            currentNode=currentNode->left;
        }
        else{
            currentNode=currentNode->right;
        }
    }
    return false;
}

void BinaryTree::remove(int aVal) {
    deleteNode(aVal,root);
}


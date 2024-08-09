#ifndef PA2_AVLTREE_H
#define PA2_AVLTREE_H

#include <iostream>
#include <cstdlib>
#include "AVLNode.h"

using std::cout;
using std::endl;

template <class T>
class AVLTree {
private:
    
    AVLNode<T>* root;

    void deleteTreeHelper(AVLNode<T>* rt);
    void treeHeightHelper(AVLNode<T>* rt, int* height);
    int height(AVLNode<T>* node){
        return node == nullptr? -1: node->height;
    }
    
    int max(int a, int b){
        if(a > b){
            return a;
        }
        else{
            return b;
        }
    }
    
    void rotateWithLeftChild(AVLNode<T>*& k2);
    void rotateWithRightChild(AVLNode<T>*& k1);
    void doubleWithLeftChild(AVLNode<T>*& k3);
    void doubleWithRightChild(AVLNode<T> *& k3);
    void insertHelper(const T& dat, AVLNode<T>*& rt);
    void containsHelper(const T& data, AVLNode<T>* rt, bool& flag);
    bool validateHelper(AVLNode<T>* rt);
    void inOrderPrintHelper(AVLNode<T>* rt);



public:

   
    AVLTree(){
        root = nullptr;
    }

   
    ~AVLTree(){
        deleteTreeHelper(root);
    }

    
    AVLNode<T>* getRoot() const{
        return root;
    }
   
    int treeHeight(){
        int height = 0;
        treeHeightHelper(root, &height);
        return height;
    }

    void insert(const T& dat){
        insertHelper(dat, root);
    }

    bool contains(const T& dat){
        bool flag = false;
        containsHelper(dat, root, flag);
        return flag;
    }

    bool validate(){
        return validateHelper(root);
    }

    void inOrderPrint(){
        inOrderPrintHelper(root);
    }
};

template <class T>
void AVLTree<T>::deleteTreeHelper(AVLNode<T>* rt){
    if(rt == nullptr){
        return;
    }
    deleteTreeHelper(rt->leftPtr);
    deleteTreeHelper(rt->rightPtr);
    delete rt;
}

template <class T>
void AVLTree<T>::treeHeightHelper(AVLNode<T> *rt, int *height){
    if(rt == nullptr)
        return;
    if(rt->getHeight() > *height)
        *height = rt->getHeight();
}

template <class T>
void AVLTree<T>::rotateWithLeftChild(AVLNode<T>*& k2){
    AVLNode<T>* k1 = k2->leftPtr;

    k2->leftPtr = k1->rightPtr;
    k1->rightPtr = k2;
    k2->height = max(height(k2->leftPtr), height(k2->rightPtr))+1;
    k1->height = max(height(k1->leftPtr), height(k1->rightPtr)) +1;
    k2 = k1;
}

template <class T>
void AVLTree<T>::rotateWithRightChild(AVLNode<T>*& k1){
    AVLNode<T>* k2 = k1->rightPtr;

    k1->rightPtr = k2->leftPtr;
    k2->leftPtr = k1;
    k2->height = max(height(k2->leftPtr), height(k2->rightPtr))+1;
    k1->height = max(height(k1->leftPtr), height(k1->rightPtr)) +1;
    k1 = k2;
}

template <class T>
void AVLTree<T>::doubleWithLeftChild(AVLNode<T>*& k3){
    rotateWithRightChild(k3->leftPtr);
    rotateWithLeftChild(k3);
}

template <class T>
void AVLTree<T>::doubleWithRightChild(AVLNode<T> *& k3){
    rotateWithLeftChild(k3->rightPtr);
    rotateWithRightChild(k3);
}

template <class T>
void AVLTree<T>::insertHelper(const T& dat, AVLNode<T>*& rt){
   
    if(rt == nullptr){
        rt = new AVLNode<T>(dat, nullptr, nullptr);   
    }
   
    else if (dat < rt->data){
       
        insertHelper(dat, rt->leftPtr);
        
        int hL = height(rt->leftPtr);
        int hR = height(rt->rightPtr);
        if( hL - hR == 2){
            if(dat < rt->leftPtr->data)
                rotateWithLeftChild(rt);
            else
                doubleWithLeftChild(rt);
        }
    }
    
    else if(rt->data<dat){
        
        insertHelper(dat, rt->rightPtr);
        
        int hR = height(rt->rightPtr);
        int hL = height(rt->leftPtr);
        if( hR - hL == 2){
            
            if(rt->rightPtr->data < dat)
                rotateWithRightChild(rt);
            
            else
                doubleWithRightChild(rt);
        }
    }
    rt->height = max(height(rt->leftPtr), height(rt->rightPtr)) + 1;
}


template <class T>
void AVLTree<T>::containsHelper(const T& data, AVLNode<T>* rt, bool& flag){
    if(rt == nullptr)
        return;
    if(rt->data == data)
        flag = true;

    containsHelper(data, rt->leftPtr, flag);
    containsHelper(data, rt->rightPtr, flag);

}

template <class T>
bool AVLTree<T>::validateHelper(AVLNode<T>* rt){
    if(rt == nullptr)
        return true;
    int hLeft = height(rt->leftPtr);
    int hRight = height(rt->rightPtr);
    if(abs((hLeft - hRight)) != 2 && validateHelper(rt->leftPtr)&& validateHelper(rt->rightPtr)){
        return true;
    }
    return false;
}

template <class T>
void AVLTree<T>::inOrderPrintHelper(AVLNode<T>* rt){
    if(rt == nullptr)
        return;
    inOrderPrintHelper(rt->leftPtr);
    cout << rt->data;
    inOrderPrintHelper(rt->rightPtr);

}

#endif 
//
// Created by MyPC on 2019/6/18.
//

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

bool BinarySearchTree:: contains(const int & x) const {
    return contains(x, root);
}

void BinarySearchTree::insert(const int &x) {
    insert(x, root);
}

void BinarySearchTree::remove(const int &x) {
    remove(x, root);
}

bool BinarySearchTree::contains(const int &x, BinarySearchTree::BinaryNode *t) const {
    if (t == NULL) {
        return false;
    } else if (x < t->data) {
        return contains(x, t->left);
    } else if (x > t->data) {
        return contains(x, t->right);
    } else {
        return true;
    }
}

BinarySearchTree::BinarySearchTree() {
    root = new BinaryNode(0, NULL, NULL);
}

BinarySearchTree::~BinarySearchTree() {
    makeEmpty();
}

void BinarySearchTree::makeEmpty() {
    makeEmpty(root);
}

void BinarySearchTree::makeEmpty(BinarySearchTree::BinaryNode *&t) {
    if (t != NULL) {
        makeEmpty(t->left);
        makeEmpty(t->right);
    }
    t = NULL;
}

void BinarySearchTree::printTree()  {
    printTree(root);
}

void BinarySearchTree::printTree(BinarySearchTree::BinaryNode *&t) {
    if (t != NULL) {
        //中序遍历
        printTree(t->left);
        cout << t->data << endl;
        printTree(t->right);
    }
}

void BinarySearchTree::insert(const int &x, BinarySearchTree::BinaryNode *&t) const {
    if (t == NULL) {
        t = new BinaryNode(x, NULL, NULL);
    } else if (x > t->data) {
        insert(x, t->right);
    } else if (x < t->data) {
        insert(x, t->left);
    }
}

void BinarySearchTree::remove(const int &x, BinarySearchTree::BinaryNode *&t) const {
    if (t == NULL) {
        return;
    }
    if (x < t->data) {
        remove(x, t->left);
    } else if (x > t->data) {
        remove(x, t->right);
    } else if (t->left != NULL && t->right != NULL){
        //两个节点,找到右边最小的点
        //把这个节点上升，然后删除该节点
        t->data = findMin(t->right)->data;
        remove(t->data, t->right);
    } else {
        BinaryNode * old = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete old;
    }
}

const int & BinarySearchTree::findMax() const {
    return findMax(root)->data;
}

const int & BinarySearchTree::findMin() const  {
    return findMin(root)->data;
}

BinarySearchTree::BinaryNode *BinarySearchTree::findMax(BinarySearchTree::BinaryNode *t) const {
    if (t != NULL) {
        while (t->right != NULL) {
            t = t->right;
        }
    }
    return t;
}

BinarySearchTree::BinaryNode *BinarySearchTree::findMin(BinarySearchTree::BinaryNode *t) const {
    if (t == NULL) {
        return t;
    }
    if (t->left == NULL) {
        return t;
    } else {
        return findMin(t->left);
    }
}

bool BinarySearchTree::isEmpty() const {
    return root == NULL;
}



const BinarySearchTree&  BinarySearchTree::operator=(const BinarySearchTree &rhs) {
    if (this != &rhs) {
        makeEmpty();
        root = clone(rhs.root);
    }
    return *this;
}

BinarySearchTree::BinaryNode *BinarySearchTree::clone(BinarySearchTree::BinaryNode *t) const {
    if (t == NULL) {
        return NULL;
    }
    return new BinaryNode(t->data, clone(t->left), clone(t->right));
}


//int main() {
//    BinarySearchTree *tree = new BinarySearchTree();
//    tree->insert(1);
//    tree->insert(3);
//    bool b = tree->contains(3);
//    int a = tree->findMax();
//    cout<< b << a <<endl;
//    tree->printTree();
//}
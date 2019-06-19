//
// Created by MyPC on 2019/6/18.
//

#ifndef ALGORITHM_BINARYSEARCHTREE_H
#define ALGORITHM_BINARYSEARCHTREE_H


class BinarySearchTree {

public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs);
    ~BinarySearchTree();

    const int & findMax() const;
    const int & findMin() const;

    bool contains(const int & x) const;

    bool isEmpty() const ;

    void printTree()  ;

    void makeEmpty();
    void insert(const int & x);
    void remove(const int & x);
    const BinarySearchTree & operator= (const BinarySearchTree &rhs);

private:
    struct BinaryNode{
        int data;
        BinaryNode * left;
        BinaryNode * right;

        BinaryNode(const int & element, BinaryNode * lt, BinaryNode * rt): data(element),left(lt), right(rt){}
    };

    BinaryNode * root;

    void insert(const int &x, BinaryNode * & t) const ;
    void remove(const int &x, BinaryNode * & t) const ;
    BinaryNode * findMin(BinaryNode *t) const ;
    BinaryNode * findMax(BinaryNode *t) const ;
    bool contains(const int &x, BinaryNode * t) const;
    void makeEmpty(BinaryNode *& t);
    void printTree(BinaryNode *& t)  ;
    BinaryNode * clone(BinaryNode *t) const ;

};


#endif //ALGORITHM_BINARYSEARCHTREE_H

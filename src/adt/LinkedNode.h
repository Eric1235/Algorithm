//
// Created by MyPC on 2019/5/26.
//

#ifndef ALGORITHM_LINKEDNODE_H
#define ALGORITHM_LINKEDNODE_H
#include <clocale>

struct LinkedNode{
    int data;
    LinkedNode *prev;
    LinkedNode *next;
    LinkedNode(const int &a ,LinkedNode *p = NULL, LinkedNode *n = NULL) : data(a), prev(p), next(n){}
};


#endif //ALGORITHM_LINKEDNODE_H

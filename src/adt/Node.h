//
// Created by MyPC on 2019/5/26.
//

#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H
#include <clocale>

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(const int &a ,Node *p = NULL, Node *n = NULL) : data(a), prev(p), next(n){}
};


#endif //ALGORITHM_NODE_H

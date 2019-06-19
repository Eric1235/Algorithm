//
// Created by MyPC on 2019/6/19.
//

#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H
#include <clocale>
struct Node{
    int data;
    Node *next;
    Node(const int &a ,Node *p = NULL) : data(a), next(p){}
};
#endif //ALGORITHM_NODE_H

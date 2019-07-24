//
// Created by MyPC on 2019/6/19.
//

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

#include "Node.h"
class List {
private:
    Node *head;

    int theSize;
public:
    List() ;

    List(const List &rhs);

    ~List();

    void clear();

    void insert(int x);

    bool earse(int x);

    void reverse();

    Node* reverse(Node *node);

    void printList();
};


#endif //ALGORITHM_LIST_H

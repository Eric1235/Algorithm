//
// Created by MyPC on 2019/5/26.
//

#ifndef ALGORITHM_CONST_ITERATOR_H
#define ALGORITHM_CONST_ITERATOR_H

#include "Node.h"

class const_iterator {
public:

protected:
    Node *current;
    int & retrieve() const {
        return current->data;
    }

};


#endif //ALGORITHM_CONST_ITERATOR_H

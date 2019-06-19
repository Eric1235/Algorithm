//
// Created by MyPC on 2019/5/26.
//

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H


#include <clocale>
#include "Node.h"

class List {


private:
   Node *head;
   Node *tail;
   int theSize;

public:
    class const_iterator {
    public:
        const_iterator() : current(NULL) {}

        const int &operator*() const {
            return retrieve();
        }

        const_iterator &operator++() {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator &rhs) const {
            return !(*this == rhs);
        }

        const_iterator(Node *p) : current(p) {}

        Node *current;

        int &retrieve() const {
            return current->data;
        }
    }

public:
    class iterator: public const_iterator {
    public:
        iterator() {}

        int &operator* (){
            return retrieve();
        }

        const int &operator*() const  {
            return const_iterator::operator*();
        }

        iterator &operator ++ () {
            current = current -> next;
            return  *this;
        };

        iterator &operator ++ (int) {
            iterator old = *this;
            ++(*this);
            return old;
        };
        iterator(Node *p) : const_iterator(p) {}

    };

public:
    List() ;

    List(const List &rhs);

    ~List();

    const List &operator= (const List &rhs) ;

    iterator begin() ;

    const_iterator begin() const ;

    iterator end() ;

    const_iterator end() const;

    int size() const;

    bool empty() const ;

    void  clear() ;

    void init();

    int & front();

    const int & front() const ;

    int & back();

    const int & back() const;

    void push_back(const int & x) ;

    void push_front(const int & x) ;

    void pop_front() ;

    void pop_back() ;

    iterator insert(iterator it, const int & x);

    iterator erase(iterator itr);

    iterator erase(iterator start, iterator end);
};


#endif //ALGORITHM_LIST_H

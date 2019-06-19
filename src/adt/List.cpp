//
// Created by MyPC on 2019/5/26.
//

#include "List.h"

List::List() {
    init();
}

List::~List() {
    clear();
    delete head;
    delete tail;
}

List::List(const List &rhs) {
    init();
    *this = rhs;
}

const List & List::operator=(const List &rhs) {
    if (this == &rhs) {
        return *this;
    }
    clear();
    for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr) {
        push_back(*itr);
    }
    return *this;
}

//构成一个回环
void List::init() {
    theSize = 0;
    head = new Node(0, NULL, NULL);
    tail = new Node(0, NULL, NULL);
    head->next = tail;
    tail->prev = head;
}

/**
 * 插入
 * @param it
 * @param x
 * @return
 */
List::iterator List::insert(List::iterator it, const int &x) {
    Node *p = it
}

List::iterator List::begin() {
    return iterator(head->next);
}

List::const_iterator List::begin() const {
    return const_iterator(head->next);
}

List::iterator List::end() {
    return iterator(tail);
}

List::const_iterator List::end() const {
    return const_iterator(tail);
}

int List::size() const {
    return theSize;
}

bool List::empty() const {
    return size() == 0;
}

void List::clear() {
    while (!empty()) {
        pop_front();
    }
}

int & List::front() {
    return *begin();
}

const int & List::front() const {
    return *end();
}

int & List::back() {
    return *end();
}

const int & List::back() const {
    return *begin();
}

void List::push_front(const int &x) {
    insert(begin(), x);
}

void List::push_back(const int &x) {
    insert(end(), x);
}

void List::pop_front() {
    erase(begin());
}

void List::pop_back() {
    erase(end());
}







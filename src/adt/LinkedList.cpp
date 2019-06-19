//
// Created by MyPC on 2019/5/26.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    init();
}

LinkedList::~LinkedList() {
    clear();
    delete head;
    delete tail;
}

LinkedList::LinkedList(const LinkedList &rhs) {
    init();
    *this = rhs;
}

const LinkedList & LinkedList::operator=(const LinkedList &rhs) {
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
void LinkedList::init() {
    theSize = 0;
    head = new LinkedNode(0, NULL, NULL);
    tail = new LinkedNode(0, NULL, NULL);
    head->next = tail;
    tail->prev = head;
}

/**
 * 插入
 * @param it
 * @param x
 * @return
 */
LinkedList::iterator LinkedList::insert(LinkedList::iterator it, const int &x) {
    LinkedNode *p = it.current;
    theSize ++;
    return iterator(p->prev = p->prev->next = new LinkedNode(x, p->prev, p));
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator itr) {
    LinkedNode *p = itr.current;
    iterator retVal(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    theSize--;
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator start, LinkedList::iterator end) {
    for (iterator itr = start; itr != end;) {
        itr = erase(itr);
    }
    return end;
}



LinkedList::iterator LinkedList::begin() {
    return iterator(head->next);
}

LinkedList::const_iterator LinkedList::begin() const {
    return const_iterator(head->next);
}

LinkedList::iterator LinkedList::end() {
    return iterator(tail);
}

LinkedList::const_iterator LinkedList::end() const {
    return const_iterator(tail);
}

int LinkedList::size() const {
    return theSize;
}

bool LinkedList::empty() const {
    return size() == 0;
}

void LinkedList::clear() {
    while (!empty()) {
        pop_front();
    }
}

int & LinkedList::front() {
    return *begin();
}

const int & LinkedList::front() const {
    return *end();
}

int & LinkedList::back() {
    return *end();
}

const int & LinkedList::back() const {
    return *begin();
}

void LinkedList::push_front(const int &x) {
    insert(begin(), x);
}

void LinkedList::push_back(const int &x) {
    insert(end(), x);
}

void LinkedList::pop_front() {
    erase(begin());
}

void LinkedList::pop_back() {
    erase(end());
}







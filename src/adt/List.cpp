//
// Created by MyPC on 2019/6/19.
//

#include "List.h"
#include <iostream>
using namespace std;

List::List() {
    head = new Node(0, NULL);
    theSize = 0;
}

List::List(const List &rhs) {

}

List::~List() {
    clear();
    delete head;
}

void List::clear() {

}

/**
 * 插入节点
 * @param x
 */
void List::insert(int x) {
    Node *p = head;
    Node *q = new Node(x, NULL);
    for (int i = 0 ; i < theSize ; i ++) {
        p = p->next;
    }
     q->next = p->next;
    p->next = q;
    theSize++;
}

/**
 * 删除某个节点
 * @param x
 */
bool List::earse(int x) {
    Node *p = head;
    Node *q = p->next;
    bool flag;
    while (q != NULL) {
        if (q->data == x) {
            flag = true;
            break;
        }
        p = q;
        q = q->next;
    }
    //找到节点
    if (flag) {
        p->next = q->next;
        q->next = NULL;
        delete q;
    }
    return flag;
}

//倒序
void List::reverse() {
    Node * p = head;
    Node * q = head->next;
    Node * r;
    while (q != NULL) {
        r = q->next;
        q->next = p;
        p = q;
        q= r;
    }
    //这一步很关键，不写这个就会成环
    head->next = NULL;
    head = p;
}

void List::printList() {
    Node *p = head;
    while (p != NULL) {
        cout<< p->data << endl;
        p = p->next;
    }
}

//int main() {
//    List *list = new List();
//    list->insert(1);
//    list->insert(2);
//    list->insert(3);
//    list->reverse();
//    list->printList();
//}
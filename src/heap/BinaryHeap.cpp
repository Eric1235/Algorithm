//
// Created by MyPC on 2019/6/22.
//

#include "BinaryHeap.h"
#include <iostream>
using namespace std;

BinaryHeap::BinaryHeap() {
    size = 0;
    array = std::vector<int>(1, 0);
}

BinaryHeap::~BinaryHeap() {
    makeEmpty();
}

void BinaryHeap::buildHeap() {
    for (int i = size / 2; i > 0; i --) {
        shiftDown(i);
    }
}

bool BinaryHeap::isEmpyt() const {
    return size == 0;
}

void BinaryHeap::deleteMin() {
    if (isEmpyt()) {
        return;
    }
    array[1] = array[size --];
    shiftDown(1);
}

void BinaryHeap::deleteMin(int &min) {
    if (isEmpyt()) {
        return;
    }
    min = array[1];
    array[1] = array[size--];
    shiftDown(1);
}

void BinaryHeap::insert(const int &x) {
    if (size == array.size() - 1) {
        //数组扩容为之前的2倍
        array.resize(array.size() * 2);
    }
    int hole = ++size;
    //上滤
    for (; hole > 1 && x < array[hole / 2]; hole = hole /2) {
        array[hole] = array[hole/2];
    }
    array[hole] = x;
}

void BinaryHeap::shiftUp(int x) {
    int hole = size;
    for (;hole > 1 && x < array[hole / 2]; hole = hole / 2) {
        array[hole] = array[hole /2];
    }
    array[hole] = x;
}

void BinaryHeap::shiftDown(int hole) {
    int child;
    //临时遍历
    int tmp = array[hole];
    for (;hole * 2 < size ; hole = child) {
        child = hole * 2;
        if (child != size && array[child + 1] < array[child]){
            child ++;
        }
        if (tmp > array[child]) {
            array[hole] = array[child];
        } else {
            break;
        }
    }
    array[hole] = tmp;
}

void BinaryHeap::makeEmpty() {
    size = 0;
    array.clear();
}

const int& BinaryHeap::findMin() const {
    return array[1];
}

int main() {
    BinaryHeap *heap = new BinaryHeap();
    for (int i = 1; i <= 10; ++i) {
        heap->insert(i);
    }
    for (int j = 10; j >= 1; j--) {
        heap->insert(j);
    }
    heap->makeEmpty();
    int x;
    for (int k = 1; k < 20; k++) {
        heap->deleteMin(x);
        cout<< x << endl;
    }
}
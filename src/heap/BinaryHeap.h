//
// Created by MyPC on 2019/6/22.
//

/**
 * 最小堆是一个完全二叉树
 * 使用数组实现
 */
#ifndef ALGORITHM_BINARYHEAP_H
#define ALGORITHM_BINARYHEAP_H
#include<vector>

class BinaryHeap {
public:
    BinaryHeap();
    ~BinaryHeap();
    bool isEmpyt() const;
    const int & findMin() const;
    void insert(const int &x);
    void deleteMin();
    void deleteMin(int &x);
    void makeEmpty();

private:
    int size;
    std::vector<int> array;
    void buildHeap();
    void siftDown(int hole);
    void siftUp(int hole);
};

#endif //ALGORITHM_BINARYHEAP_H

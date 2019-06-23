//
// Created by MyPC on 2019/6/23.
//

/**
 * 为了支持合并，使用树结构
 * 向左生长的树
 * 时间复杂度为N(log2N)
 */
#ifndef ALGORITHM_LEFTISHEAP_H
#define ALGORITHM_LEFTISHEAP_H


#include <clocale>

class LeftisHeap {
public:
    LeftisHeap();
    ~LeftisHeap();

    bool isEmpty()const;
    void insert(int &x);
    void deleteMin();
    void deleteMin(int &x);
    void makeEmpty();

    void merge(LeftisHeap &rhs);

    const LeftisHeap &operator=(const LeftisHeap &rhs);

private:
    struct LeftisNode{
        int element;
        LeftisNode *left;
        LeftisNode *right;
        /**
         * 零路径长
         */
        int npl;
        LeftisNode(const int &x, LeftisNode *lt = NULL, LeftisNode *rt = NULL, int np = 0) : element(x), left(lt), right(rt), npl(np) {}
    };

    LeftisNode * root;

    LeftisNode *merge(LeftisNode *h1, LeftisNode *h2);
    LeftisNode *merge1(LeftisNode *h1, LeftisNode *h2);

    void swapChildren(LeftisNode *t);
    void reclainMemory(LeftisNode *t);
    int findMin();
};


#endif //ALGORITHM_LEFTISHEAP_H

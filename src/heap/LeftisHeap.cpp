//
// Created by MyPC on 2019/6/23.
//

#include "LeftisHeap.h"

void LeftisHeap::merge(LeftisHeap &rhs) {
    if (this == &rhs) {
        return;
    }
    root = merge(root, rhs.root);
    rhs.root = NULL;
}

LeftisHeap::LeftisNode* LeftisHeap::merge(LeftisHeap::LeftisNode *h1, LeftisHeap::LeftisNode *h2) {
    if (h1 == NULL) {
        return h2;
    }
    if (h2 == NULL) {
        return h1;
    }
    if (h1->element < h2->element) {
        return merge1(h1, h2);
    } else {
        return merge1(h2, h1);
    }
}

LeftisHeap::LeftisNode* LeftisHeap::merge1(LeftisHeap::LeftisNode *h1, LeftisHeap::LeftisNode *h2) {
    if (h1->left == NULL) {
        h1->left = h2;
    } else {
        //递归地将具有大根值得堆与小根值得堆的右子堆进行合并
        h1->right = merge(h1->right, h2);
        if (h1->left->npl < h1->right->npl) {
            //交换节点
            swapChildren(h1);
        }
        h1->npl = h1->right->npl + 1;
    }
    return h1;
}

void LeftisHeap::insert(int &x) {
    root = merge(new LeftisNode(x), root);
}

bool LeftisHeap::isEmpty() const {
    return root == NULL;
}

int LeftisHeap::findMin() {

}


void LeftisHeap::deleteMin() {
    if (isEmpty()) {
        return;
    }
    LeftisNode * oldRoot = root;
    root = merge(root->left, root->right);
    delete oldRoot;
}

void LeftisHeap::deleteMin(int &x) {
    x = findMin();
    deleteMin();
}

void LeftisHeap::swapChildren(LeftisHeap::LeftisNode *t) {
    LeftisNode * tmp = t->left;
    t->left = t->right;
    t->right = tmp;
}
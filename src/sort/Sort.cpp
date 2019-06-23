//
// Created by MyPC on 2019/6/23.
//

#include "Sort.h"
#include <iostream>
using namespace std;

Sort::Sort() {}

Sort::~Sort() {

}

void Sort::insertionSort(vector<int> &array) {
    int j;
    for (int i = 0; i < array.size(); ++i) {
        int x = array[i];
        for (j = i; j > 0 && array[j-1] > x; j--) {
            array[j] = array[j - 1];
        }
        array[j] = x;
    }
}


void Sort::shellSort(vector<int> &array) {
    for (int gap = array.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < array.size() ; i ++) {
            int tmp = array[i];
            int j = i;
            for (; j >= gap && tmp < array[j - gap]; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = tmp;
        }
    }
}

void Sort::headSort(vector<int> &array) {
    for (int i = array.size() / 2; i >= 0 ; i--) {
        //build heap
        siftDown(array, i, array.size());
    }
    for (int j = array.size() - 1; j > 0; j--) {
        //delete Max
        swap(array[0], array[j]);
        siftDown(array, 0, j);
    }
}

void Sort::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int Sort::leftChild(int i) {
    return  2 * i;
}

void Sort::siftDown(vector<int> &array, int i, int n) {
    int child;
    int tmp;
    for (tmp = array[i]; leftChild(i) < n; i = child) {
        child = leftChild(i);
        if (child != n - 1 && array[child] < array[child + 1]) {
            child ++;
        }
        if (tmp < array[child]) {
            array[i] = array[child];
        } else {
            break;
        }
    }
    array[i] = tmp;
}

void Sort::printArray(vector<int> &array) {
    for (int i = 0 ; i < array.size() ; i ++) {
        cout << array[i] << endl;
    }
}

int main() {
    Sort *sort = new Sort();
    vector<int> array = vector<int>(10,0);
    for (int i = 0 ; i < array.size() ; i ++) {
        array[i] = 10 - i;
    }
    sort->printArray(array);
    sort->headSort(array);
    sort->printArray(array);
    delete(sort);
}
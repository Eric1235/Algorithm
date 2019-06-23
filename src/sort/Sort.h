//
// Created by MyPC on 2019/6/23.
//

#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H
#include<vector>
using namespace std;

class Sort {
public:
    Sort();
    ~Sort();

    //N^2
    void insertionSort(vector<int> &array);

    //N^2
    void shellSort(vector<int> &array);

    void headSort(vector<int> &array);

    void printArray(vector<int> &array);

private:
    int leftChild(int i);
    void siftDown(vector<int> &array, int i, int n);
    void swap(int &a, int &b);
};


#endif //ALGORITHM_SORT_H

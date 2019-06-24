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

    void insertionSort(vector<int> &array, int left, int right);

    //N^2
    void shellSort(vector<int> &array);

    void headSort(vector<int> &array);

    void mergeSort(vector<int> &array);

    void quickSort(vector<int> &array);

    void printArray(vector<int> &array);

private:

    int leftChild(int i);
    void siftDown(vector<int> &array, int i, int n);
    void swap(int &a, int &b);

    void mergeSort(vector<int> &array, vector<int> &tmpArray, int left, int right);

    void merge(vector<int> &array, vector<int> &tmpArray, int leftPos, int rightPos, int rightEnd);

    void quickSort(vector<int> &array, int left, int right);

    const int median3(vector<int> &array, int left, int right);
};


#endif //ALGORITHM_SORT_H

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

void Sort::insertionSort(vector<int> &array, int left, int right) {
    int j;
    for (int i = left; i < right; ++i) {
        int x = array[i];
        for (j = i; j > 0 && array[j-1] > x; j--) {
            array[j] = array[j - 1];
        }
        array[j] = x;
    }
}

void Sort::mergeSort(vector<int> &array) {
    //tmpArray最终会和array一样
    //空间就为2N了
    vector<int> tmpArray(array.size());
    mergeSort(array, tmpArray, 0, array.size() - 1);
}

/**
 * 分治
 * @param array
 * @param tmpArray
 * @param left
 * @param right
 */
void Sort::mergeSort(vector<int> &array, vector<int> &tmpArray, int left, int right) {
//    cout<< "left:" << left << "right:" << right <<endl;
    //跳出分割
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(array, tmpArray, left, center);
        mergeSort(array, tmpArray, center + 1, right);
        merge(array, tmpArray, left, center + 1, right);
    }
}

/**
 * 执行合并排序
 * @param array 数组
 * @param tmpArray 辅助数组
 * @param leftPos 左边开始位置
 * @param rightPos 右边开始位置
 * @param rightEnd 右边结束位置
 */
void Sort::merge(vector<int> &array, vector<int> &tmpArray, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    //一共有多少个元素
    int numElements = rightEnd - leftPos + 1;
    //主循环，往前推进，
    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        //进行比较，摘取较小的值进入tmpArray
        if (array[leftPos] <= array[rightPos]) {
            tmpArray[tmpPos++] = array[leftPos++];
        } else {
            tmpArray[tmpPos++] = array[rightPos++];
        }
    }

    //把剩下的值拷贝完
    while (leftPos <= leftEnd) {
        tmpArray[tmpPos++] = array[leftPos ++];
    }

    //把剩下的值拷贝完
    while (rightPos <= rightEnd) {
        tmpArray[tmpPos++] = array[rightPos++];
    }

    //从尾到头赋值,对已经排好序的某一段进行回写
    for (int i = 0 ; i < numElements ; i ++, rightEnd --) {
        array[rightEnd] = tmpArray[rightEnd];
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

void Sort::quickSort(vector<int> &array) {
    quickSort(array, 0, array.size()-1);
}

void Sort::quickSort(vector<int> &array, int left, int right) {
    if (left + 3 <= right) {
        int pivot = median3(array, left, right);
        int i = left, j = right - 1;
        for (;;) {
            while (array[++i] < pivot) {

            }
            while (array[--j] > pivot) {

            }
            if (i < j) {
                swap(array[i], array[j]);
            } else {
                break;
            }
        }
        swap(array[i], array[right - 1]);
        quickSort(array, left, i - 1);
        quickSort(array, i + 1, right);
    } else {
        insertionSort(array, left, right);
    }
}

//挑选阈值，并且对left，center，right排序
const int Sort::median3(vector<int> &array, int left, int right) {
    int center = (left + right) / 2;
    if (array[center] < array[left]) {
        swap(array[left], array[center]);
    }
    if (array[right] < array[left]) {
        swap(array[left], array[right]);
    }
    if (array[right] < array[center]) {
        swap(array[right], array[center]);
    }
    swap(array[center], array[right - 1]);
    return array[right - 1];
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
    sort->quickSort(array);
    sort->printArray(array);
    delete(sort);
}
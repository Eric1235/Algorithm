//
// Created by MyPC on 2019/6/25.
//

#ifndef ALGORITHM_DISJSETS_H
#define ALGORITHM_DISJSETS_H
#include<vector>
using namespace std;

class DisjSets {
public:
    explicit DisjSets(int numElements);

    int find(int x) const ;
    int find(int x);
    void unionSets(int root1, int root2);

private:
    //基础数据结构为数组
    vector<int> arrays;
};


#endif //ALGORITHM_DISJSETS_H

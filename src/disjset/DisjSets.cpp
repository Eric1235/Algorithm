//
// Created by MyPC on 2019/6/25.
//

#include "DisjSets.h"

DisjSets::DisjSets(int numElements): arrays(numElements) {
    for (int i = 0 ; i < arrays.size() ; i ++) {
        arrays[i] = -1;
    }
}

void DisjSets::unionSets(int root1, int root2) {
    if (arrays[root2] < arrays[root1]) {
        arrays[root1] = root2;
    } else {
        if (arrays[root1] = arrays[2]) {
            arrays[root1]--;
        }
        arrays[root2] = root1;
    }
}

//路径压缩
int DisjSets::find(int x) const {
    if (arrays[x] < 0) {
        return x;
    } else {
        return arrays[x] == find(arrays[x]);
    }
}
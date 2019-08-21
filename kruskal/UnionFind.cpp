//
// Created by 16678 on 2019/5/23.
//
#include <iostream>
#include <cstdlib>
#include "UnionFind.h"
#include <vector>
#include <climits>
using std::cout;
using std::endl;
using std::vector;


bool UnionFind::is_connent(int p, int q) {
    return find(q) == find(p);
}

int UnionFind::find(int i) {
    if(i < 0 || i >= size){
        cout << "size范围错误" <<endl;
        exit(2);
    }
    while (i != parent[i]) {
        //路径压缩
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void UnionFind::union_(int p, int q) {
    if (p < 0 || q < 0 || p >= size || q >= size){
        cout << "error" << endl;
        exit(6);
    }
    parent[p] = q;
}

UnionFind::UnionFind(int size) {
    if (size <= 0){
        cout << "size不能小于等于0" <<endl;
        exit(1);
    }
    this->size = size;
    parent = new int[size];
    for (int i = 0; i < size; ++i)
        parent[i] = i;
}

UnionFind::~UnionFind() {
    delete parent;
}

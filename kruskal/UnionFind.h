//
// Created by 16678 on 2019/5/23.
//

#ifndef KRUSKAL_UNIONFIND_H
#define KRUSKAL_UNIONFIND_H


class UnionFind {
private:
    int* parent;
    int size;
    //找到父节点
    int find(int i);

public:
    UnionFind(int size);
    ~UnionFind();
    //判断两个元素是否是同一个集合
    bool is_connent(int p, int q);
    //变成一个集合
    void union_(int p, int q);
};


#endif //KRUSKAL_UNIONFIND_H

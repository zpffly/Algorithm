#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "UnionFind.h"
using std::cout;
using std::endl;
using std::vector;
using std::sort;

const int inf = INT_MAX;
const int INF = INT_MAX;

//存储边的结构体， 两边是节点，即 v1---v2
struct Node{
    int start;
    int end;
    int weigh;
    Node(int s, int e, int w){
        start = s;
        end = e;
        weigh = w;
    }

};

int cmp(const void *a, const void *b)
{
    return (*(Node *)a).weigh < (*(Node*)b).weigh;
}

void kruskal(vector<vector<int> >& graph){
    int vertex_num = graph.size();
    UnionFind u(vertex_num);
    //存储边集
    vector<Node*> edges;
    //生成边集
    for (int i = 0; i < vertex_num; ++i) {
        for (int j = 0; j < vertex_num; ++j) {
            if (graph[i][j] != inf)
                edges.emplace_back(new Node(i, j, graph[i][j]));
        }
    }
    //将边集排序
    sort(edges.begin(), edges.end(), cmp);
//    for (int i = 0; i < edges.size(); ++i)
//        cout << edges[i]->start << "-->" << edges[i]->end <<" "<< edges[i]->weigh << endl;
    //顶生成树的点数
    int count = 1;
    int index = 0;
    while (count < vertex_num && !edges.empty()){
        //如果边两个端点不是同一个集合则合并
        if (!u.is_connent(edges[index]->start, edges[index]->end)) {
            u.union_(edges[index]->start, edges[index]->end);
            cout << edges[index]->start << "->" << edges[index]->end << endl;
            ++count;
        }
        ++index;
    }

}

int main() {
    vector<vector<int> > graph = {{INF, 7,   4,   INF, INF, INF},   //INF代表两点之间不可达
                                  {7,   INF, 6,   2,   INF, 4},
                                  {4,   6,   INF, INF, 9,   8},
                                  {INF, 2,   INF, INF, INF, 7},
                                  {INF, INF, 9,   INF, INF, 1},
                                  {INF, 4,   8,   7,   1,   INF}
    };

    kruskal(graph);
    return 0;
}
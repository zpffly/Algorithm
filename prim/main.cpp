#include <iostream>
#include <vector>
#include <climits>
using std::vector;
using std::cout;
using std::endl;

const int inf = INT_MAX;
const int INF = inf;


void prim(vector<vector<int> >& graph, int v){
    int vertex_num = graph.size();
    bool visit[vertex_num];
    //记录到生成树的最小距离
    int dis[vertex_num];
    for (int i = 0; i < vertex_num; ++i)
        visit[i] = false;
    visit[v] = true;

    for (int i = 0; i < vertex_num; ++i){
        dis[i] = graph[v][i];
    }


    for (int i = 1; i < vertex_num; ++i){

        int mindis = inf;
        //找到距离树最近的点
        for (int j = 0; j < vertex_num; ++j){
            if (!visit[j] && dis[j] < mindis){
                mindis = dis[j];
                v = j;
            }
        }
        visit[v] = true;
        cout << v << " ";
        //更新每个没有访问的点到最小生成树的最小距离
        for(int k = 0; k < vertex_num; ++k){
            if (!visit[k] && dis[k] > graph[v][k]){
                dis[k] = graph[v][k];
            }
        }
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
    prim(graph, 0);
    return 0;
}
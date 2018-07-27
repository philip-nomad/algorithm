//
// Created by 채민균 on 2017. 5. 15..
//

#include <iostream>
#include <queue>
using namespace std;
int arr[1002][1002] = {0};
int visit[1002] = {0};
int vis[1002] = {0};
int n, m, v;
//vector < vector < int > > graph;
queue<int> q;

void dfs(int v) {
    if (visit[v] == 1) {
        return;
    } else {

        visit[v] = 1;
        printf("%d ", v);
//        for(int i = 0; i < graph[v].size(); i++)
//            dfs(graph[v][i]);
        for (int i = 1; i <= n; ++i) {
            if (arr[v][i] == 1) {
                dfs(i);
            }
        }
    }
}

void bfs(int v) {
    q.push(v);
    vis[v] = 1;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        printf("%d ", f);
//        for(int i = 0; i < graph[f].size(); i++)
//        {
//            if(vis[graph[f][i]] != 1)
//            {
//                q.push(graph[f][i]);
//                vis[graph[f][i]] = 1;
//            }
//
//        }
        for (int i = 1; i <= n; ++i) {
            if (arr[f][i] == 1) {
                if (vis[i] != 1) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &v);
//    graph.resize(n+1);
    while (m--) {
        int i, j;
        scanf("%d %d", &i, &j);
//        graph[i].push_back(j);
//        graph[j].push_back(i);
        arr[i][j] = 1;
        arr[j][i] = 1;
    }
    dfs(v);
    printf("\n");
    bfs(v);
}

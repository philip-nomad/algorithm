//
// Created by 채민균 on 2017. 7. 2..
//
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <string.h>

using namespace std;
struct info {
    int i, j, cost;
};

class mycomparison {
    bool reverse;
public:
    mycomparison(const bool &revparam = true) { reverse = revparam; }

    bool operator()(const info &lhs, const info &rhs) const {
        if (reverse) return (lhs.cost > rhs.cost);
        else return (lhs.cost < rhs.cost);
    }
};


bool boundary(int i, int j, int n) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
    int n, dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1}, arr[126][126], cnt = 1, visited[126][126];
    info dist[126][126];
    priority_queue<info, vector<info>, mycomparison> pq;
    while (true) {
        scanf("%d", &n);
        if (n == 0) return 0;
        memset(visited, 0, sizeof(int) * 126 * 126);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j].i = i;
                dist[i][j].j = j;
                dist[i][j].cost = 987654321;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &arr[i][j]);
            }
        }
        dist[0][0].cost = arr[0][0];
        pq.push(dist[0][0]);
        while (!pq.empty()) {
            info step = pq.top();
            pq.pop();
            int i = step.i, j = step.j, cost = step.cost;
            visited[i][j] = 1;
            if (i == n - 1 && j == n - 1) continue;
            for (int k = 0; k < 4; ++k) {
                int ny = i + dy[k], nx = j + dx[k];
                if (boundary(ny, nx, n)) {
                    if (arr[ny][nx] + cost < dist[ny][nx].cost) {
                        dist[ny][nx].cost = arr[ny][nx] + cost;
                        if (visited[ny][nx] == 0) pq.push(dist[ny][nx]);
                    }
                }
            }
        }

        printf("Problem %d: %d\n", cnt++, dist[n - 1][n - 1].cost);
    }
}
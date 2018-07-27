//
// Created by 채민균 on 2017. 5. 15..
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    int arr[103][103];
    int visit[103][103] = {0,};
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d", &arr[i][j]);
        }
    }
    queue<pair<int, int> > q;
    q.push(pair<int, int>(0, 0));
    visit[0][0] = 1;
    int ans = 0;
    while (!q.empty()) {
        int qSize = q.size();
        ++ans;
        while (qSize--) {
            int newX = q.front().first;
            int newY = q.front().second;
            if (newX == n - 1 && newY == m - 1) {
                goto out1;
            }
            q.pop();
            for (int i = 0; i < 4; ++i) {
                if (0 <= newX + dx[i] && newX + dx[i] < n) {
                    if (0 <= newY + dy[i] && newY + dy[i] < m) {
                        if (arr[newX + dx[i]][newY + dy[i]] == 1 && visit[newX + dx[i]][newY + dy[i]] == 0) {
                            q.push(pair<int, int>(newX + dx[i], newY + dy[i]));
                            visit[newX + dx[i]][newY + dy[i]] = 1;
                        }
                    }
                }
            }
        }
    }
    out1:;
    printf("%d", ans);
    return 0;
}

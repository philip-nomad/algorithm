//
// Created by 채민균 on 2017. 7. 15..
//

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
int h, w, n, arr[1001][1001] = {0,}, y, x, isEnd[1001][1001], ans = 0, dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0,
                                                                                                       -1};

bool boundary(int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w;
}

int main() {
    scanf("%d%d%d", &h, &w, &n);
    char c;
    scanf("%c", &c);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            isEnd[i][j] = 0;
            scanf("%c", &c);
            if (48 <= c && c < 58) {
                arr[i][j] = (int) c - 48;
                continue;
            } else if ((int) c == 88) {
                arr[i][j] = -1;
                continue;
            } else if ((int) c == 83) {
                y = i;
                x = j;
                continue;
            }
        }
        scanf("%c", &c);
    }
    isEnd[y][x] = 1;
    for (int find = 1; find <= n; ++find) {
        int num = 0;
        queue<pair<int, int>> q;
        q.push(pair<int, int>(y, x));
        memset(isEnd, 0, sizeof(int) * 1001 * 1001);
        while (!q.empty()) {
            int size = q.size();
            ++num;
            while (size--) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if (arr[i][j] == find) {
                    ans += num - 1;
                    y = i;
                    x = j;
                    break;
                }
                for (int k = 0; k < 4; ++k) {
                    int ny = i + dy[k], nx = j + dx[k];
                    if (boundary(ny, nx)) {
                        if (isEnd[ny][nx] == 0) {
                            if (arr[ny][nx] >= 0) {
                                q.push(pair<int, int>(ny, nx));
                                isEnd[ny][nx] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
//
// Created by 채민균 on 2017. 6. 26..
//
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int arr[501][501], n, m, dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0}, dp[501][501];

bool boundary(int i, int j) {
    return 0 <= i && i < m && 0 <= j && j < n;
}

int func(int i, int j) {
    if (i == m - 1 && j == n - 1) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int path = 0;
    for (int k = 0; k < 4; ++k) {
        int newY = i + dy[k];
        int newX = j + dx[k];
        if (boundary(newY, newX) && arr[newY][newX] < arr[i][j]) {
            path += func(newY, newX);
        }
    }
    dp[i][j] = path;
    return dp[i][j];
}

int main() {
    scanf("%d%d", &m, &n);
    memset(dp, -1, sizeof(int) * 501 * 501);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d\n", func(0, 0));
    return 0;
}

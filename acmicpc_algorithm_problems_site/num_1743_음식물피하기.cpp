//
// Created by 채민균 on 2017. 6. 26..
//
#include <iostream>
#include <algorithm>

using namespace std;
int arr[101][101], isEnd[101][101] = {0,}, n, m, x, dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0}, maxi;

bool canGo(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void func(int i, int j) {
    isEnd[i][j] = 1;
    ++maxi;
    for (int k = 0; k < 4; ++k) {
        int newY = i + dy[k];
        int newX = j + dx[k];
        if (isEnd[newY][newX] != 1 && canGo(newY, newX) && arr[newY][newX] == 1) {
            func(newY, newX);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &x);
    while (x--) {
        int a, b;
        scanf("%d%d", &a, &b);
        arr[a - 1][b - 1] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            maxi = 0;
            if (isEnd[i][j] == 0 && arr[i][j] == 1) func(i, j);
            if (ans < maxi) ans = maxi;
        }
    }
    printf("%d\n", ans);
    return 0;
}

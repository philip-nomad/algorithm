//
// Created by 채민균 on 2017. 7. 26..
//

#include <iostream>
#include <cstring>

using namespace std;
int n, arr[101][101], visited[101][101] = {0,}, fir = 0, sec = 0, dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

bool boundary(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

void func(int i, int j, bool opt) {
    visited[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
        int ny = i + dy[k], nx = j + dx[k];
        if (boundary(ny, nx) && visited[ny][nx] == 0) {
            if (opt) {
                if (arr[ny][nx] == arr[i][j]) func(ny, nx, opt);
            } else {
                if (arr[ny][nx] == arr[i][j] || arr[ny][nx] + arr[i][j] == 7) func(ny, nx, opt);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    char c;
    scanf("%c", &c);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%c", &c);
            if (c == 'R') {
                arr[i][j] = 5;
            } else if (c == 'G') {
                arr[i][j] = 2;
            } else if (c == 'B') {
                arr[i][j] = 3;
            }
        }
        scanf("%c", &c);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] == 0) {
                func(i, j, true);
                fir++;
            }
        }
    }
    memset(visited, 0, sizeof(int) * 101 * 101);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] == 0) {
                func(i, j, false);
                sec++;
            }
        }
    }
    printf("%d %d", fir, sec);
    return 0;
}
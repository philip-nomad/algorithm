//
// Created by 채민균 on 2017. 6. 29..
//
#include <iostream>
#include <string.h>

using namespace std;

int n, a, b, m, arr[101][101] = {0,};


int main() {
    scanf("%d%d%d%d", &n, &a, &b, &m);
    memset(arr, 1, sizeof(int) * 101 * 101);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) {
                    if (arr[i][j] > arr[k][j] + arr[k][i]) {
                        arr[i][j] = arr[k][j] + arr[k][i];
                    }
                }
            }
        }
    }
    if (arr[a][b] == 16843009) {
        printf("%d", -1);
    } else {
        printf("%d", arr[a][b]);
    }
    return 0;
}

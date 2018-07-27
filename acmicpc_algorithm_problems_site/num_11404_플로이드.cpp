//
// Created by 채민균 on 2017. 6. 18..
//

#include <iostream>

using namespace std;

int main() {
    int arr[101][101], n, m;
    scanf("%d%d", &n, &m);
    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n; ++i) {
            arr[l][i] = 99999999;
        }
    }
    for (int k = 0; k < m; ++k) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (arr[a][b] > c)
            arr[a][b] = c;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) {
                    if (arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] == 99999999) {
                printf("%d ", 0);
            } else {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
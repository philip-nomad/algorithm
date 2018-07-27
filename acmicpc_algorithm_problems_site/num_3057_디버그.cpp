//
// Created by 채민균 on 2017. 6. 20..
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int col, row, arr[301][301] = {0,};
    scanf("%d%d", &col, &row);
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            scanf("%1d", &arr[i][j]);
        }
    }
    int ans = min(col, row);
    while (ans > 0) {
        for (int i = 0; i <= col - ans; ++i) {
            for (int j = 0; j <= row - ans; ++j) {
                int temp = ans - 1;
                bool find = true;
                for (int l = i, q = i + temp; l <= i + ans / 2; ++l, --q) {
                    for (int k = j, w = j + temp; k < j + ans; ++k, --w) {
                        if (arr[l][k] != arr[q][w]) {
                            find = false;
                            break;
                        }
                    }
                    if (!find)break;
                }
                if (find) {
                    cout << ans;
                    return 0;
                }
            }
        }
        --ans;
    }
    cout << -1;
}
//
// Created by 채민균 on 2017. 6. 25..
//
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, x, arr[1001][1001];
    memset(arr, 1, sizeof(int) * 1001 * 1001);
    cin >> n >> m >> x;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) {
                    if (arr[i][j] > arr[i][k] + arr[k][j]) {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }
    }
    int maxi = 0;
    for (int i = 1; i <= n; ++i) {
        if (x != i) {
            if (maxi < arr[x][i] + arr[i][x]) {
                maxi =  arr[x][i] + arr[i][x];
            }
        }
    }
    cout << maxi;
    return 0;
}
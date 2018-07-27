//
// Created by 채민균 on 2017. 6. 25..
//
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, arr[101][101];
    memset(arr, 1, sizeof(int) * 101 * 101);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
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
    int mini = 99999999, sum, ans;
    for (int i = 1; i <= n; ++i) {
        sum = 0;
        for (int j = 1; j <= n; ++j) {
            sum += arr[i][j];
        }
        if (mini > sum) {
            mini = sum;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
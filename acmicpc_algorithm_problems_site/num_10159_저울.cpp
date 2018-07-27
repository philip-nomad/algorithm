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
        int a, b, c;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 2;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) {
                    if (arr[i][k] + arr[k][j] == 2) {
                        arr[i][j] = 1;
                    }
                    if (arr[i][k] + arr[k][j] == 4) {
                        arr[i][j] = 2;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                if (arr[i][j] == 16843009)++count;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
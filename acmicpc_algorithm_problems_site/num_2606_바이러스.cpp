//
// Created by 채민균 on 2017. 6. 25..
//
#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, arr[101][101] = {0,};
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
                    if (arr[i][k] != 0 && arr[k][j] != 0) {
                        arr[i][j] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int l = 2; l <= n; ++l) {
        if (arr[1][l] == 1) ++ans;
    }
    cout << ans;
    return 0;
}
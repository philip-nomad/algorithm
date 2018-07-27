//
// Created by 채민균 on 2017. 6. 25..
//
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int N, M, K, arr[401][401];
    memset(arr, 1, sizeof(int) * 401 * 401);
    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 2;
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
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
    cin >> K;
    while (K--) {
        int a, b;
        cin >> a >> b;
        if (arr[a][b] == 2) {
            cout << 1 << "\n";
        } else if (arr[a][b] == 1) {
            cout << -1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}
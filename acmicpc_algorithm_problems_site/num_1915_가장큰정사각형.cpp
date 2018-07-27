//
// Created by 채민균 on 2017. 5. 20..
//
#include <iostream>

using namespace std;

int main() {
    register int i,j,n, m, maxi = 0, arr[1001][1001], dp[1002][1002] = {0,};
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf("%1d", &arr[i][j]);
        }
    }
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            if (arr[i - 1][j - 1] == 1) {
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                if (maxi < dp[i][j]) {
                    maxi = dp[i][j];
                }
            }
        }
    }
    printf("%d", maxi * maxi);
    return 0;
}

//
// Created by 채민균 on 2017. 5. 13..
//
#include <iostream>

using namespace std;

int main() {
    int dp[1001][10] = {0,};
    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }

    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = j; k < 10; ++k) {
                dp[i][j] += dp[i - 1][k];
            }
            dp[i][j] %= 10007;
        }
    }
    printf("%d",
           (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5] + dp[n][6] + dp[n][7] + dp[n][8] + dp[n][9]) % 10007);
    return 0;
}

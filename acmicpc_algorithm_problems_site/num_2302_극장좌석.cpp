//
// Created by 채민균 on 2017. 7. 7..
//

#include <iostream>

using namespace std;

int main() {
    int n, m, dp[41] = {1, 1, 2}, a = 0, b = 0, ans = 1;
    for (int i = 3; i <= 40; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b);
        ans *= dp[b - a - 1];
        a = b;
    }
    ans *= dp[n - b];
    printf("%d", ans);
    return 0;
}
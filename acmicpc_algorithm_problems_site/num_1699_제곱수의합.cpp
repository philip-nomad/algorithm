//
// Created by 채민균 on 2017. 5. 19..
//

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int *dp = new int[n + 1];
    memset(dp, -1, sizeof(int) * (n + 1));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (dp[i] != -1) {
                if (dp[i] > dp[i - j * j] + 1) {
                    dp[i] = dp[i - j * j] + 1;
                }
            } else {
                dp[i] = dp[i - j * j] + 1;
            }
        }
    }
    printf("%d", dp[n]);
    delete[] dp;
    return 0;
}
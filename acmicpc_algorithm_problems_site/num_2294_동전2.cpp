//
// Created by 채민균 on 2017. 6. 27..
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <string.h>

using namespace std;

int main() {
    int n, k, coin[101], dp[10001];
    memset(dp, 1, sizeof(int) * 10001);
    dp[0] = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &coin[i]);
    sort(coin, coin + n, greater<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = coin[i]; j <= k; ++j) {
            if (dp[j - coin[i]] + 1 < dp[j]) dp[j] = dp[j - coin[i]] + 1;
        }
    }
    if (dp[k] == 16843009) printf("-1");
    else printf("%d", dp[k]);

    return 0;
}
//
// Created by 채민균 on 2017. 6. 27..
//

#include <iostream>

using namespace std;

int main() {
    int n, k, coin[101], dp[10001] = {1,};
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &coin[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = coin[i]; j <= k; ++j) {
            dp[j] += dp[j - coin[i]];
        }
    }
    printf("%d", dp[k]);
    return 0;
}
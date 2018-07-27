//
// Created by 채민균 on 2017. 7. 9..
//
#include <iostream>

using namespace std;

int main() {
    int n, arr[1000], dp[1000] = {1,}, maxi = 1;
    scanf("%d%d", &n, &arr[0]);
    for (int i = 1; i < n; ++i) {
        dp[i] = 1;
        scanf("%d", &arr[i]);
        for (int j = i - 1; j >= 0; --j) if (arr[j] < arr[i] && dp[i] <= dp[j]) dp[i] = dp[j] + 1;
        if (maxi < dp[i]) maxi = dp[i];
    }
    printf("%d", maxi);
    return 0;
}

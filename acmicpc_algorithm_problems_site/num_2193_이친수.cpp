#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    long long dp[100];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < t; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    printf("%lld", dp[t-1]);
}
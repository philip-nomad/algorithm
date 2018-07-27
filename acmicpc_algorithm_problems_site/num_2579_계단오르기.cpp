#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, arr[30010], dp[30010][2], pos = 0, result;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d", &arr[i]);
    }
    dp[0][0] = arr[0];
    dp[1][0] = arr[1];
    dp[1][1] = arr[0] + arr[1];
    for (int i = 2; i < t; ++i) {
        pos = i;
        dp[pos][1] = dp[pos - 1][0] + arr[pos];
        dp[pos][0] = max(dp[pos - 2][1], dp[pos - 2][0]) + arr[pos];
    }
    result = max(dp[t - 1][0], dp[t - 1][1]);
    printf("%d", result);
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int arr[1010][3] = {0,};
    for (int i = 0; i < n; ++i) {
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        arr[i][0] = r;
        arr[i][1] = g;
        arr[i][2] = b;
    }

    int dp[1010][3] = {0,};
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }
    int mini = min(dp[n - 1][0], dp[n - 1][1]);
    mini = min(mini, dp[n - 1][2]);
    printf("%d\n", mini);
}



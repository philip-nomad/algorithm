#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    int dp[41][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i < 41; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    while (t--) {
        int k;
        scanf("%d", &k);
        printf("%d %d\n", dp[k][0], dp[k][1]);
    }
}
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<vector<int> > v(2);
        for (int j = 0; j < n; ++j) {
            int num;
            scanf("%d", &num);
            v[0].push_back(num);
        }
        for (int j = 0; j < n; ++j) {
            int num;
            scanf("%d", &num);
            v[1].push_back(num);
        }
        int dp[2][100010];
        dp[0][0] = v[0][0];
        dp[1][0] = v[1][0];
        dp[0][1] = v[1][0] + v[0][1];
        dp[1][1] = v[0][0] + v[1][1];
        for (int j = 2; j < n; ++j) {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + v[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + v[1][j];
        }
        int result = max(dp[0][n - 1], dp[1][n - 1]);
        printf("%d\n", result);
    }
}

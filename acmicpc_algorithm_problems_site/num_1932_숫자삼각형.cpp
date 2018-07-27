#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int arr[510][510];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    int dp[510][510];
    int maxi = 0;
    dp[0][0] = arr[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i][0] = dp[i - 1][0] + arr[i][0];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
            }
            if (i == n - 1) {
                if(maxi < dp[i][j]) {
                    maxi = dp[i][j];
                }
            }
        }
    }
    printf("%d", maxi);
}
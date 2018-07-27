//
// Created by 채민균 on 2017. 5. 7..
//

#include <iostream>
#include <cmath>

using namespace std;
int n;
int arr[10001];
int dp[10001][3];

void func(int i) {
    dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
    dp[i][1] = arr[i] + dp[i - 1][0];
    dp[i][2] = arr[i] + dp[i - 1][1];
    if (i == n - 1) {
        return;
    }
    func(i + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    if (n == 1) {
        printf("%d",arr[0]);
        return 0;
    } else if (n == 2) {
        printf("%d", arr[0] + arr[1]);
        return 0;
    }
    dp[0][0] = 0;
    dp[0][1] = arr[0];
    dp[0][2] = arr[0];
    func(0);
    printf("%d",max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])));
}
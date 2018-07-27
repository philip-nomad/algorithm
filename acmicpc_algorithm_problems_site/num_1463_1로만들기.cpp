#include <iostream>
#include <cmath>

using namespace std;
int dp[1000001] = {0,};

int func(int a) {
    int mini = 999999999;
    if (dp[a] != 0) {
        return dp[a];
    }
    if (a == 1) {
        return 0;
    }
    if (a % 3 == 0) {
        mini = min(mini, func(a / 3) + 1);
    }
    if (a % 2 == 0) {
        mini = min(mini, func(a / 2) + 1);
    }
    mini = min(mini, func(a - 1) + 1);
    return dp[a] = mini;
}

int main() {
    int a;
    scanf("%d", &a);
    func(a);
    if (a == 1) {
        printf("%d", 0);
    } else {
        dp[a] = 0;
        printf("%d", func(a));
    }
}
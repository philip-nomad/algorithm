//
// Created by 채민균 on 2017. 5. 15..
//

#include <iostream>

using namespace std;
int check[1002] = {0,};
int arr[1002][1002];
int n, m;

void dfs(int index) {
    for (int i = 1; i <= n; ++i) {
        if (check[i] == 0 && arr[index][i]) {
            check[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        arr[b][a] = arr[a][b] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (check[i] == 0) {
            ans++;
            dfs(i);
        }
    }
    printf("%d", ans);
    return 0;
}
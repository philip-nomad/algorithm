//
// Created by 채민균 on 2017. 6. 29..
//
#include <iostream>

using namespace std;

int main() {
    int n, arr[21][21] = {0,}, sum = 0, done[21][21] = {0,};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
            if (j < i)sum += arr[i][j];
        }
    }
    int minus = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && i != k && k != j) {
                    if (arr[i][j] > arr[k][j] + arr[i][k]) {
                        printf("-1");
                        return 0;
                    } else if (arr[i][j] == arr[k][j] + arr[i][k]) {
                        if (done[i][j] == 0) {
                            minus += arr[i][j];
                            done[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
    printf("%d", sum - (minus / 2));
    return 0;
}
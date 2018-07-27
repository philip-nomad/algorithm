//
// Created by 채민균 on 2017. 6. 29..
//
#include <iostream>

using namespace std;

int main() {
    int n, arr[51][51] = {0,};
    scanf("%d", &n);
    char dummy;
    scanf("%c", &dummy);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            scanf("%c", &c);
            if (c == 'N') arr[i][j] = 10000;
            else arr[i][j] = 1;
        }
        scanf("%c", &dummy);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (arr[i][j] > arr[k][j] + arr[i][k]) arr[i][j] = arr[k][j] + arr[i][k];
                }
            }
        }
    }
    int maxi = 0, count;
    for (int i = 0; i < n; ++i) {
        count = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j && arr[i][j] <= 2)++count;
        }
        if (maxi < count) maxi = count;
    }
    printf("%d", maxi);
    return 0;
}
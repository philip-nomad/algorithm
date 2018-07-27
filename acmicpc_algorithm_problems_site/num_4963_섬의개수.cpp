//
// Created by 채민균 on 2017. 5. 15..
//

#include <iostream>
#include <algorithm>

using namespace std;
int arr[52][52] = {0,};

void func(int m, int n, int i, int j) {
    arr[i][j] = 0;
    if (i + 1 < m && arr[i + 1][j] == 1) {
        func(m, n, i + 1, j);
    }
    if (i - 1 >= 0 && arr[i - 1][j] == 1) {
        func(m, n, i - 1, j);
    }
    if (j + 1 < n && arr[i][j + 1] == 1) {
        func(m, n, i, j + 1);
    }
    if (j - 1 >= 0 && arr[i][j - 1] == 1) {
        func(m, n, i, j - 1);
    }
    if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 1) {
        func(m, n, i - 1, j - 1);
    }
    if (i - 1 >= 0 && j + 1 < n && arr[i - 1][j + 1] == 1) {
        func(m, n, i - 1, j + 1);
    }
    if (i + 1 < m && j - 1 >= 0 && arr[i + 1][j - 1] == 1) {
        func(m, n, i + 1, j - 1);
    }
    if (i + 1 < m && j + 1 < n && arr[i + 1][j + 1] == 1) {
        func(m, n, i + 1, j + 1);
    }
}

int main() {
    while (true) {
        int w, h;
        scanf("%d%d", &w, &h);
        if (w == 0 && h == 0) {
            break;
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                scanf("%d", &arr[i][j]);
            }
        }

        int count = 0;
        for (int q = 0; q < h; ++q) {
            for (int k = 0; k < w; ++k) {
                if (arr[q][k] == 1) {
                    ++count;
                    func(h, w, q, k);
                }
            }
        }
        printf("%d\n", count);

    }
}
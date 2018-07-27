#include <iostream>
#include <algorithm>
#include <map>
#include <set>

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
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int m, n, k;
        scanf("%d%d%d", &m, &n, &k);
        while (k--) {
            int i, j;
            scanf("%d%d", &i, &j);
            arr[i][j] = 1;
        }
        int count = 0;
        for (int q = 0; q < m; ++q) {
            for (int k = 0; k < n; ++k) {
                if (arr[q][k] == 1) {
                    ++count;
                    func(m, n, q, k);
                }
            }
        }
        printf("%d\n", count);
    }
}
//
// Created by 채민균 on 2017. 7. 4..
//
#include <iostream>

using namespace std;
int n, m, parent[201], a, b;

int f(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = f(parent[x]);
}

void u(int x, int y) {
    int xPar = f(x), yPar = f(y);
    if (xPar != yPar) parent[yPar] = xPar;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) parent[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int num;
            scanf("%d", &num);
            if (num == 1) u(i, j);
        }
    }
    scanf("%d", &a);
    while (--m) {
        scanf("%d", &b);
        if (f(a) != f(b)) {
            printf("NO");
            return 0;
        }
        a = b;
    }
    printf("YES");
}

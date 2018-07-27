//
// Created by 채민균 on 2017. 7. 4..
//
#include <iostream>

using namespace std;
int n, m, parent[1000001], a, b, c;

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
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0) u(b, c);
        else {
            if (f(b) == f(c)) printf("YES\n");
            else printf("NO\n");
        }
    }
}

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        int r, n;
        scanf("%d %d", &r, &n);

        int nr = n - r;

        long long q = 1;
        for (int i = max(nr, r) + 1; i <= n; ++i) {
            q *= i;
        }
        long long p = 1;
        for (int j = 1; j <= min(nr, r); ++j) {
            p *= j;
        }
        printf("%lld\n", q / p);
    }
}
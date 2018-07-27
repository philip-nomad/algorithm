//
// Created by 채민균 on 2017. 5. 22..
//

#include <iostream>

using namespace std;

int main() {
    bool *PrimeArray;
    int n = 246915;
    PrimeArray = new bool[n + 1];
    for (int i = 2; i <= n; i++) PrimeArray[i] = true;
    for (int i = 2; (i * i) <= n; i++) {
        if (PrimeArray[i]) {
            for (int j = i * i; j <= n; j += i) PrimeArray[j] = false;
        }
    }
    int arr[246915] = {0,};
    register int count = 0;
    for (int k = 2; k < n + 1; ++k) {
        if (PrimeArray[k]) {
            ++count;
        }
        arr[k] = count;
    }
    register int t;
    while (true) {
        scanf("%d", &t);
        if (t == 0) {
            return 0;
        }
        printf("%d\n", arr[2 * t] - arr[t]);
    }
}
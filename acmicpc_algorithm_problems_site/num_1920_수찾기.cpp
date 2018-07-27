//
// Created by 채민균 on 2017. 6. 27..
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[100001], n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    scanf("%d", &m);
    while (m--) {
        int num;
        scanf("%d", &num);
        printf("%d\n", binary_search(arr, arr + n, num));
    }
    return 0;
}

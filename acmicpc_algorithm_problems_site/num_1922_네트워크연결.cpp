//
// Created by 채민균 on 2017. 6. 27..
//
#include<iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct vertex {
    int num, root;
};
struct edge {
    int v, w, cost;
};

int n, m;
edge map[100001];
vertex arr[1001];

bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}

void unionFunc(int mini, int maxi) {
    int temp = arr[maxi].root;
    for (int i = 1; i <= n; ++i) {
        if (arr[i].root == temp) arr[i].root = mini;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int v, w, cost;
        scanf("%d%d%d", &v, &w, &cost);
        map[i] = {v, w, cost};
        arr[v] = {v, v};
        arr[w] = {w, w};
    }
    sort(map, map + m, cmp);
    int count = n, ans = 0;
    for (int i = 0; i < m; ++i) {
        if (count == 0) {
            break;
        }
        int v = map[i].v, w = map[i].w;
        if (arr[v].root != arr[w].root) {
            ans += map[i].cost;
            --count;
            unionFunc(min(arr[v].root, arr[w].root), max(arr[v].root, arr[w].root));
        }
    }
    printf("%d", ans);
    return 0;
}

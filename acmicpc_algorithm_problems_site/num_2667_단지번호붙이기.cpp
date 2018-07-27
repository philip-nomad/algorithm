//
// Created by 채민균 on 2017. 6. 26..
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[26][26], isEnd[26][26] = {0,}, n, dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0}, maxi;
vector<int> v;

bool canGo(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

void func(int i, int j) {
    isEnd[i][j] = 1;
    ++maxi;
    for (int k = 0; k < 4; ++k) {
        int newY = i + dy[k];
        int newX = j + dx[k];
        if (isEnd[newY][newX] != 1 && canGo(newY, newX) && arr[newY][newX] == 1) {
            func(newY, newX);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%1d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxi = 0;
            if (isEnd[i][j] == 0 && arr[i][j] == 1) func(i, j);
            if (maxi != 0) v.push_back(maxi);
        }
    }
    int size = v.size();
    printf("%d\n", size);
    sort(v.begin(), v.end());
    for (int i = 0; i < size; ++i) {
        printf("%d\n", v[i]);
    }
    return 0;
}

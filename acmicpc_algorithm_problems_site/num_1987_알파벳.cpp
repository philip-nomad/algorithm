//
// Created by 채민균 on 2017. 6. 30..
//
#include <iostream>

using namespace std;
int r, c, check[26] = {0,}, arr[21][21] = {0,}, dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1}, ans = 0;

bool boundary(int i, int j) {
    return 0 <= i && i < r && 0 <= j && j < c;
}

void func(int i, int j, int count) {
    check[arr[i][j]] = 1;
    if (ans < count) ans = count;
    for (int k = 0; k < 4; ++k) {
        int newY = i + dy[k], newX = j + dx[k];
        if (boundary(newY, newX)) {
            int alpha = arr[newY][newX];
            if (check[alpha] == 0) {
                func(newY, newX, count + 1);
            }
        }
    }
    check[arr[i][j]] = 0;
}

int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char cha;
            cin >> cha;
            arr[i][j] = (int) cha - 65;
        }
    }
    func(0, 0, 1);
    printf("%d", ans);
    return 0;
}

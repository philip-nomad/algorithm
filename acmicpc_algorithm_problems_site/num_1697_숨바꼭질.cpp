//
// Created by 채민균 on 2017. 6. 21..
//

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;
int a, b, arr[100005] = {0,};
queue<int> q;

void func(int count) {
    int size = q.size();
    while (size--) {
        int num = q.front();
        q.pop();
        if (num < 0 || num > 100005) continue;
        if (num == b) {
            cout << count;
            return;
        }
        if (num * 2 < 100005 && arr[num * 2] == 0) {
            arr[num * 2] = count + 1;
            q.push(num * 2);
        }
        if (num + 1 < 100005 && arr[num + 1] == 0) {
            arr[num + 1] = count + 1;
            q.push(num + 1);
        }
        if (num - 1 >= 0 && arr[num - 1] == 0) {
            arr[num - 1] = count + 1;
            q.push(num - 1);
        }
    }
    func(count + 1);
}

int main() {
    scanf("%d%d", &a, &b);
    if (a >= b) {
        cout << a - b;
        return 0;
    }
    if (a * 2 < 100005) {
        arr[a * 2] = 1;
        q.push(a * 2);
    }
    if (a + 1 < 100005) {
        arr[a + 1] = 1;
        q.push(a + 1);
    }
    if (a - 1 >= 0) {
        arr[a - 1] = 1;
        q.push(a - 1);
    }
    func(1);
    return 0;
}
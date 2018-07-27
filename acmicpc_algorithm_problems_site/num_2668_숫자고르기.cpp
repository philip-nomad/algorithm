////
//// Created by 채민균 on 2017. 8. 6..
////
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <cstring>

using namespace std;

stack<int> stk;
vector<int> temp, ret, self;
int status[101], arr[101][101], n, cnt;

/**
 * 본인의 정점에서 갈 수 있는 곳으로 깊이우선탐색을 합니다.
 */
void dfs(int index) {
    status[index] = 1;
    for (int i = 1; i <= n; ++i) if (arr[index][i] == 1 && status[i] == 0) dfs(i);
    stk.push(index);
}

/**
 * 본인의 정점으로 올 수 있는 곳으로 깊이우선탐색을 합니다.
 */
void rDfs(int index) {
    ++cnt;
    temp.push_back(index);
    status[index] = 0;
    for (int i = 1; i <= n; ++i)
        if (arr[i][index] == 1 && status[i] == 1) rDfs(i);
}


void reverseDfs() {
    while (!stk.empty()) {
        int num = stk.top();
        stk.pop();
        if (status[num] == 1) {
            temp.clear();
            cnt = 0;
            rDfs(num);
            if (cnt == 1) continue;
            for (int qwe : temp) {
                ret.push_back(qwe);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    memset(arr, 0, sizeof(int) * 101 * 101);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        arr[i][num] = 1;
        if (i == num) self.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (status[i] == 0) dfs(i);
    }
    reverseDfs();
    sort(ret.begin(), ret.end());
    int self_size = self.size();
    for (int i = 0; i < self_size; ++i) {
        if (binary_search(ret.begin(), ret.end(), self[i])) {
            self.erase(self.begin() + i);
            --i;
            --self_size;
        }
    }
    self_size = self.size();
    for (int i = 0; i < self_size; ++i) {
        ret.push_back(self[i]);
    }
    sort(ret.begin(), ret.end());
    int size = ret.size();
    cout << size << "\n";
    for (int qwe : ret) {
        cout << qwe << "\n";
    }
    return 0;
}
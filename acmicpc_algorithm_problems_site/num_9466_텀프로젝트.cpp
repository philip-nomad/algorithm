//
// Created by 채민균 on 2017. 7. 30..
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

stack<int> stk;
int status[100001], arr[100001], n, t, nummy, ans;
vector<vector<int> > v;

/**
 * 본인의 정점에서 갈 수 있는 곳으로 깊이우선탐색을 합니다.
 */
void dfs(int i) {
    status[i] = 1;
    if (status[arr[i]] == 0) dfs(arr[i]);
    stk.push(i);
}

/**
 * 본인의 정점으로 올 수 있는 곳으로 깊이우선탐색을 합니다.
 */
void rDfs(int index, int from) {
    status[index] = 0;
    if (arr[index] == index) return;
    int size = v[index].size();
    bool flag = true;
    for (int i = 0; i < size; ++i) {
        if (index != from) {
            flag = false;
        }
        if (status[v[index][i]] == 1) {
            flag = false;
            rDfs(v[index][i], index);
        }
    }
    if (flag) {
//        printf("숫자 : %d \n", index + 1);
        ++ans;
    }
}


void reverseDfs() {
    while (!stk.empty()) {
        int num = stk.top();
        stk.pop();
        if (status[num] == 1) {
            rDfs(num, num);
        }
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nummy);
            arr[i] = nummy - 1;
            v[arr[i]].push_back(i);
        }
        memset(status, 0, sizeof(int) * 100001);
        for (int i = 0; i < n; ++i) {
            if (status[i] == 0) dfs(i);
        }
        ans = 0;
        reverseDfs();
        printf("%d\n", ans);
        memset(arr, 0, sizeof(int) * 100001);
        v.clear();
    }
    return 0;
}
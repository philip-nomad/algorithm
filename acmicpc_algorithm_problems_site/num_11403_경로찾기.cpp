//
// Created by 채민균 on 2017. 5. 15..
//

#include <iostream>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;
int n, arr[102][102], visited[102][102] = {0,};
queue<int> que;
stack<int> stk;

//0.정답출력
void printAnswer() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j]) printf("%d ", 1);
            else printf("%d ", 0);
        }
        printf("\n");
    }
};

//1.dfs 로 푸는방법
void dfs() {
    for (int i = 0; i < n; ++i) {
        memset(visited, 0, sizeof(int) * 102 * 102);
        stk.push(i);
        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            for (int j = 0; j < n; ++j) {
                if (arr[top][j] == 1 && visited[top][j] == 0) {
                    stk.push(j);
                    visited[top][j] = 1;
                    arr[i][j] = 1;
                }
            }
        }
    }
}

//2.bfs 로 푸는방법
void bfs() {
    for (int i = 0; i < n; ++i) {
        memset(visited, 0, sizeof(int) * 102 * 102);
        que.push(i);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int front = que.front();
                que.pop();
                for (int j = 0; j < n; ++j) {
                    if (arr[front][j] == 1 && visited[front][j] == 0) {
                        que.push(j);
                        visited[front][j] = 1;
                        arr[i][j] = 1;
                    }
                }
            }
        }
    }
}

//3.floyd-warshall 로 푸는방법
void floydWarshall() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][k] == 1 && arr[k][j] == 1) {
                    arr[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    //초기입력
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    bfs();
//    dfs();
//    floydWarshall();
    printAnswer();
    return 0;
}
//
// Created by 채민균 on 2017. 7. 23..
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
struct node {
    int i, j;
};
int n, arr[101][101], visited[101][101] = {0,}, dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1}, num = 1, cnt = 0;
vector<node> v[20010];

bool boundary(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

void func(int i, int j) {
    visited[i][j] = 1;
    arr[i][j] = num;
    node n = {i, j};
    v[num].push_back(n);
    for (int k = 0; k < 4; ++k) {
        int ny = i + dy[k], nx = j + dx[k];
        if (boundary(ny, nx) && visited[ny][nx] == 0 && arr[ny][nx] == 1) func(ny, nx);
    }
}

int main() {
    //초기입력
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &arr[i][j]);
    //섬에 번호매기기
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (visited[i][j] == 0 && arr[i][j] == 1) func(i, j), num++;
    //섬 수가 0,1개 이면 0을 출력하고 종료
    if (num <= 2) {
        printf("%d", 0);
        return 0;
    }
    memset(visited, 0, sizeof(int) * 101 * 101);
    //섬의 넓이를 한 칸씩 확장해간다.
    while (true) {
        cnt++;
        for (int i = 1; i < num; ++i) {
            int size = (int) v[i].size();
            for (int j = 0; j < size; ++j) {
                node n = v[i][j];
                int oy = n.i, ox = n.j;
                visited[oy][ox] = 1;
                for (int k = 0; k < 4; ++k) {
                    int ny = oy + dy[k], nx = ox + dx[k];
                    if (boundary(ny, nx)) {
                        if (arr[ny][nx] == i) {
                            continue;
                        }
                        if (arr[ny][nx] == 0 && visited[ny][nx] == 0) {
                            arr[ny][nx] = i;
                            node nn = {ny, nx};
                            v[i].push_back(nn);
                            visited[ny][nx] = 1;
                        } else {
                            printf("%d", arr[ny][nx] > arr[oy][ox] ? (cnt - 1) * 2 : cnt * 2 - 1);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
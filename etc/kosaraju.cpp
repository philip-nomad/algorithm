//
// Created by 채민균 on 2017. 5. 30..
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <time.h>

using namespace std;

stack<int> stk;
int status[3001], arr[3001][3001], n, mini, limit;

/**
 * 본인의 정점에서 갈 수 있는 곳으로 깊이우선탐색을 합니다.
 */
void dfs(int index) {
    status[index] = 1;
    for (int i = 1000; i < limit; ++i)
        if (arr[index][i] == 1 && status[i] == 0) dfs(i);
    stk.push(index);
}

/**
 * 본인의 정점으로 올 수 있는 곳으로 깊이우선탐색을 합니다.
 */
void rDfs(int index) {
    status[index] = 0;
    if (mini > index) mini = index;
    for (int i = 1000; i < limit; ++i)
        if (arr[i][index] == 1 && status[i] == 1) rDfs(i);
}


void reverseDfs(int num1) {
    while (!stk.empty()) {
        if (status[num1] == 0) break;
        int num = stk.top();
        stk.pop();
        if (status[num] == 1) {
            mini = 3001;//최소값을 나올 수 없는 값으로 세팅해줍니다.
            rDfs(num);
        }
    }
}

int main() {
    ifstream mList("/Users/chaemingyun/Desktop/inpdir/memberlist_100.txt");//memberlist 파일을 읽습니다
    char c[6] = {'\0'};
    mList.getline(c, 6);
    string s = "";
    for (int i = 0; i < 100; ++i) {
        if (c[i] != '\0') s += c[i];
        else break;
    }
    n = atoi(s.c_str());
    limit = 1000 + n;
    for (int i = 1000; i < limit; ++i) {
        memset(arr[i], 1, sizeof(int) * n);
    }
    mList.close();
//    clock_t start, fin;
//    start = clock();
    ifstream qList("/Users/chaemingyun/Desktop/inpdir/query_100.txt");//질의파일을 읽습니다.
    char query[20];
    while (!qList.eof()) {
        string s1 = "", s2 = "";
        int num1, num2;
        qList.getline(query, 20);
        if (query[0] == 'I') {
            for (int i = 2; i < 6; ++i) {
                s1 += query[i];
                s2 += query[i + 5];
            }
            num1 = atoi(s1.c_str());
            num2 = atoi(s2.c_str());
            arr[num1][num2] = 1;//num1번 정점에서 num2번 정점으로 갈 수 있음을 표현합니다.
        } else if (query[0] == 'O') {
            for (int i = 2; i < 6; ++i) {
                s1 += query[i];
            }
            num1 = atoi(s1.c_str());
            for (int i = 1000; i < limit; ++i) {
                status[i] = 0;
            }
            dfs(num1);
            reverseDfs(num1);//역으로 dfs를 돌려서 strongly connected component 를 구합니다.
            cout << mini << "\n";
        } else if (query[0] == 'Q') {
            break;
        }
    }
    qList.close();
//    fin = clock();
//    cout << "수행시간 : " << ((double) (fin - start) / CLOCKS_PER_SEC) << endl;
    return 0;
}
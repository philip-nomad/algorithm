#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    queue<int> q;
    vector<int> stk;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        q.push(num);
    }
    bool isEnd = false;
    for (int i = 1; i <= n; ++i) {
        while (true) {
            if (!q.empty() && q.front() == i) {
                q.pop();
                break;
            } else if (!stk.empty() && stk.back() == i) {
                stk.pop_back();
                break;
            } else {
                if (!q.empty()) {
                    int num = q.front();
                    q.pop();
                    stk.push_back(num);
                } else {
                    printf("Sad");
                    isEnd = true;
                    break;
                }
            }
        }
        if (isEnd) break;
    }
    if (!isEnd) {
        printf("Nice");
    }
    return 0;
}

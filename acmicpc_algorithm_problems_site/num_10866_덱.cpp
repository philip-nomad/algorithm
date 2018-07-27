//
// Created by 채민균 on 2017. 6. 22..
//

#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int func(string s) {
    int size = s.size();
    string str;
    bool flag = false;
    for (int i = 0; i < size; ++i) {
        if (s[i] == ' ') flag = true;
        if (flag && s[i] != '\n') {
            str += s[i];
        }
    }
    return atoi(str.c_str());
}

int main() {
    deque<int> dq;
    int n;
    scanf("%d", &n);
    string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
//        push_front
        if (s[0] == 'p' && s[5] == 'f') {
            int num = func(s);
            dq.push_front(num);
        }
//        push_back
        else if (s[0] == 'p' && s[5] == 'b') {
            int num = func(s);
            dq.push_back(num);
        }
//        pop_front
        else if (s[0] == 'p' && s[5] == 'r') {
            if (!dq.empty()) {
                printf("%d\n", dq.front());
                dq.pop_front();
            } else {
                printf("-1\n");
            }
        }
//        pop_back
        else if (s[0] == 'p' && s[5] == 'a') {
            if (!dq.empty()) {
                printf("%d\n", dq.back());
                dq.pop_back();
            } else {
                printf("-1\n");
            }
        }
//        size
        else if (s[0] == 's') {
            printf("%d\n", (int) dq.size());
        }
//        empty
        else if (s[0] == 'e') {
            dq.empty() ? printf("1\n") : printf("0\n");
        }
//        front
        else if (s[0] == 'f') {
            if (!dq.empty()) {
                printf("%d\n", dq.front());
            } else {
                printf("-1\n");
            }
        }
//                back
        else if (s[0] == 'b') {
            if (!dq.empty()) {
                printf("%d\n", dq.back());
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}
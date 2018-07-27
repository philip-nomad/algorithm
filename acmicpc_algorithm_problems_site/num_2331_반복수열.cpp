//
// Created by 채민균 on 2017. 6. 30..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    //236196
    int dp[236197] = {0,};
    string s, a = "", pStr = "";
    getline(cin, s);
    int size = s.size();
    bool flag = true;
    for (int i = 0; i < size; ++i) {
        if (s[i] == ' ') {
            flag = false;
            continue;
        }
        if (48 <= s[i] && s[i] < 58) {
            if (flag) {
                a += s[i];
            } else {
                pStr += s[i];
            }
        }
    }
    int firstValue = atoi(a.c_str());
    int maxi = firstValue;
    dp[firstValue] = 1;
    int p = atoi(pStr.c_str());
    while (true) {
        size = a.size();
        int temp = 0;
        for (int i = 0; i < size; ++i) {
            int num = (int) a[i] - 48;
            temp += pow(num, p);
        }
        if (dp[temp] == 2) break;
        dp[temp]++;
        if (maxi < temp) {
            maxi = temp;
        }
        a = to_string(temp);
    }
    int count = 0;
    for (int j = 1; j <= maxi; ++j) {
        if (dp[j] == 1) ++count;
    }
    printf("%d", count);
    return 0;
}
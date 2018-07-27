//
// Created by 채민균 on 2017. 6. 22..
//

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    string str, cmp;
    cin >> str >> cmp;
    str = "0" + str;
    cmp = "0" + cmp;
    int table[4002][4002] = {0,};
    int sLen = str.size(), cLen = cmp.size(), maxi, LCS = 0;
    for (int i = 1; i < cLen; ++i) {
        maxi = 0;
        for (int j = 1; j < sLen; ++j) {
            if (str[j] == cmp[i]) {
                maxi = table[i - 1][j - 1] + 1;
                table[i][j] = maxi;
            } else {
                table[i][j] = table[i][j - 1] > table[i - 1][j] ? table[i][j - 1] : table[i - 1][j];
            }
        }
        if (LCS < maxi) LCS = maxi;
    }
    cout << LCS << "\n";
    int temp = LCS;
    int for_j = sLen - 1;
    string ans = "";
    for (int i = cLen - 1; i > 0; --i) {
        for (int j = for_j; j > 0; --j) {
            if (table[i][j] == temp && table[i - 1][j] == temp - 1 && table[i][j - 1] == temp - 1 &&
                table[i - 1][j - 1] == temp - 1) {
                ans = cmp[i] + ans;
                temp--;
                for_j = j;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
//
// Created by 채민균 on 2017. 6. 22..
//

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int size = s.size(), start = 0;
    string str = "", ans = "";
    int modulo = size % 3;
    if (modulo == 1) {
        ans += s[0] == '1' ? '1' : '0';
        start = 1;
    } else if (modulo == 2) {
        str += s[0];
        str += s[1];
        if (strcmp(str.c_str(), "01") == 0) {
            ans += '1';
        } else if (strcmp(str.c_str(), "11") == 0) {
            ans += '3';
        } else if (strcmp(str.c_str(), "00") == 0) {
            ans += '0';
        } else {
            ans += '2';
        }
        start = 2;
    }
    str = "";
    for (int i = start; i < size; i += 3) {
        str += s[i];
        str += s[i + 1];
        str += s[i + 2];
        if (strcmp(str.c_str(), "000") == 0)ans += '0';
        else if (strcmp(str.c_str(), "001") == 0)ans += '1';
        else if (strcmp(str.c_str(), "010") == 0)ans += '2';
        else if (strcmp(str.c_str(), "011") == 0)ans += '3';
        else if (strcmp(str.c_str(), "100") == 0)ans += '4';
        else if (strcmp(str.c_str(), "101") == 0)ans += '5';
        else if (strcmp(str.c_str(), "110") == 0)ans += '6';
        else if (strcmp(str.c_str(), "111") == 0)ans += '7';
        str = "";
    }
    cout << ans;
    return 0;
}

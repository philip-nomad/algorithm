//
// Created by 채민균 on 2017. 8. 6..
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    register int n;
    cin >> n;
    set<string> s;
    string str, what;
    getline(cin, str);
    while (n--) {
        getline(cin, str);
        what.assign(str.begin(), str.end() - 6);
        if (str[str.size() - 5] == 'e') s.insert(what);
        else s.erase(what);
    }
    set<string>::reverse_iterator iter = s.rbegin();
    for (; iter != s.rend(); ++iter) cout << *iter << "\n";
}
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    set<pair<int, string>> s;
    vector<string> v[n+1];
    string str;
    for (int i = 1; i <= n; ++i) {
        getline(cin, str);
        v[i] = str;
        s.insert(pair<int, string>(i,str));
    }
    s.find()
    return 0;
}

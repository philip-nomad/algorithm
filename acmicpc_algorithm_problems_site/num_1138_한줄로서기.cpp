//
// Created by 채민균 on 2017. 5. 27..
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v;
    list<int> l;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    list<int>::iterator iter;
    for (int i = n - 1; i >= 0; --i) {
        iter = l.begin();
        for (int j = 0; j < v[i]; ++j) {
            ++iter;
        }
        l.insert(iter, i + 1);
    }
    iter = l.begin();
    for (; iter != l.end(); ++iter) {
        printf("%d ", *iter);
    }
    return 0;
}
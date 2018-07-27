#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct {
    int value, index, rank;
} node;

bool cmpValue(node a, node b) {
    if (a.value!=b.value) return a.value < b.value;
    return a.index<b.index;
}

bool cmpIndex(node a, node b) {
    return a.index < b.index;
}

int main() {
    int n, a;
    node nodelist[60];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nodelist[i].value = a;
        nodelist[i].index = i;
    }
    sort(nodelist, nodelist + n, cmpValue);
    for (int i = 0; i < n; i++) {
        nodelist[i].rank = i;
    }
    sort(nodelist, nodelist + n, cmpIndex);
    for (int i = 0; i < n; i++) {
        cout << nodelist[i].rank;
        if (i != n - 1) cout << " ";
    }
}
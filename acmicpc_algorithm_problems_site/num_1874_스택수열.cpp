//
// Created by 채민균 on 2017. 7. 4..
//
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, arr[100001] = {0,}, index = 0;
    scanf("%d", &n);
    vector<char> v;
    while (n--) {
        int num;
        scanf("%d", &num);
        for (int i = num; i < index; ++i) {
            if(arr[i] == 0) {
                printf("NO");
                return 0;
            }
        }
        for (int i = index; i < num; ++i) {
            if (arr[i] == 0) v.push_back('+');
        }
        v.push_back('-');
        arr[num - 1] = 1;
        index = num - 1;
    }
    int size = v.size();
    for (int j = 0; j < size; ++j) {
        printf("%c\n", v[j]);
    }
    return 0;
}

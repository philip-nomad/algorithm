//
// Created by 채민균 on 2017. 7. 9..
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, a,b,c, maxi[2][3], mini[2][3], q,w;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    mini[0][0] = maxi[0][0] = a, mini[0][1] = maxi[0][1] = b, mini[0][2] = maxi[0][2] = c;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &a,&b,&c);
        if(i%2 == 0) q = 0, w = 1;
        else q = 1, w = 0;
        maxi[q][0] = max(maxi[w][0], maxi[w][1]) + a, mini[q][0] = min(mini[w][0], mini[w][1]) + a;
        maxi[q][1] = max(maxi[w][0], max(maxi[w][1], maxi[w][2])) + b, mini[q][1] = min(mini[w][0], min(mini[w][1], mini[w][2])) + b;
        maxi[q][2] = max(maxi[w][2], maxi[w][1]) + c, mini[q][2] = min(mini[w][2], mini[w][1]) + c;
    }
    int ans = (n-1)%2;
    printf("%d %d", max(maxi[ans][0], max(maxi[ans][1], maxi[ans][2])), min(mini[ans][0], min(mini[ans][1], mini[ans][2])));
    return 0;
}

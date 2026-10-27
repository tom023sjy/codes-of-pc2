#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, pair<int, int>> exgcd(int a, int b) {
    if (b == 0) return {a, {1, 0}};
    auto res = exgcd(b, a % b);
    int gcd = res.first;
    __int128 x = res.second.first, y = res.second.second;
    return {gcd, {y, x - a / b * y}};
}
// x mod a[i] = b[i] 
int excrt(int n, int a[], int b[]) { 
    __int128 x = a[1], y = b[1];
    for (int i = 2; i <= n; i ++) {
        auto res = exgcd(x, a[i]);
        int gcd = res.first;
        if ((b[i] - y) % gcd)
            return -1;
        __int128 x1 = res.second.first, x2 = res.second.second;
        x1 = x1 * (b[i] - y) / gcd;
        x1 %= (a[i] / gcd);
        x1 = (x1 + a[i] / gcd) % (a[i] / gcd);
        y = x * x1 + y;
        x = x * a[i] / gcd;
    }
    return (y % x + x) % x;
}
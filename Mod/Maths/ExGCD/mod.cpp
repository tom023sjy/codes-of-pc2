#include <bits/stdc++.h>
using namespace std;
#define int long long
tuple<int, int, int> exgcd(int a, int b) {
    if (b == 0) 
        return make_tuple(a, 1, 0);
    int gcd, x1, y1;
    tie(gcd, x1, y1) = exgcd(b, a % b);
    int x = y1, y = x1 - a / b * y1;
    return make_tuple(gcd, x, y);
}
signed main() {
	int a, b;
    cin >> a >> b;
    int x;
    tie(ignore, x, ignore) = exgcd(a, b);
    x = (x % b + b) % b;
    cout << x;
    return 0;
}
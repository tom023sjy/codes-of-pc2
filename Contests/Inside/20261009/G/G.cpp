#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    double P = 1;
    for (int i = 1; i <= n; i ++) {
        int l, r;
        cin >> l >> r;
        int ll = max(l, a), rr = min(r, b);
        P *= 1.0 * max(rr - ll, 0ll) / (b - a);
    }
    cout << 1 - P;
    return 0;
}
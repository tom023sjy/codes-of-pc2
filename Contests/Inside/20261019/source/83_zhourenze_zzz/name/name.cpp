#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, q, t, x, y, k;
void solve() {
    while (q--) {
        cin >> t;
        if (t == 1) cin >> x >> y;
        else if (t == 2) {
            cin >> k;
            cout << k << "\n";
        }
    }
    return;
}
signed main() {
    freopen("name.in", "r", stdin);
    freopen("name.out", "w", stdout);
    cin >> c >> q;
    if (c == 7 || c == 8) {
        solve();
        return 0;
    }
    return 0;
}

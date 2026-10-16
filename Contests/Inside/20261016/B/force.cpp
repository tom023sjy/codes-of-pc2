#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int l, int r, int k, int p) {
    int s = 0;
    for (int i = k; i < l; i ++)
        s ^= i;
    for (int i = l; i <= r; i ++) {
        #ifdef tb
        cout << s << ", ";
        #endif
        s ^= i;
        if (s == p)
            return i;
    }
    return -1;
}
signed main() {
    int T;
    cin >> T;
    while (T --) {
        int l, r, k, x;
        cin >> l >> r >> k >> x;
        cout << solve(l, r, k, x) << endl;
    }
    return 0;
}
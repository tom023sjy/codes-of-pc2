#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x) {
    if (x % 4 == 0)
        return x;
    if (x % 4 == 1)
        return 1;
    if (x % 4 == 2)
        return x + 1;
    return 0;
}
int solve(int l, int r, int k, int p) {
    int res = p ^ f(k - 1);
    if (res == 0) {
        for (int i = l; i <= r; i ++)
            if (i % 4 == 3)
                return i;
        return -1;
    }
    if (res == 1) {
        for (int i = l; i <= r; i ++)
            if (i % 4 == 1)
                return i;
        return -1;
    }
    if (res % 4 == 0 && l <= res && res <= r)
        return res;
    if (res % 4 == 3 && l <= res - 1 && res - 1 <= r)
        return res - 1;
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
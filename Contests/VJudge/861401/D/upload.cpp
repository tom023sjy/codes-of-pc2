#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5, mod = 998244353;
int fct[N + 5], ifct[N + 5];
int a[N + 5], box[N + 5], gbox[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
    int n;
    cin >> n;
    fct[0] = 1;
    for (int i = 1; i <= n; i ++)
        fct[i] = fct[i - 1] * i % mod;
    ifct[n] = fp(fct[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i --)
        ifct[i] = ifct[i + 1] * (i + 1) % mod;
    int ans = 1;
    for (int i = 1; i <= n; i ++) {
        int m;
        cin >> m;
        for (int i = 1; i <= m; i ++) {
            cin >> a[i];
            box[a[i]] ++, gbox[a[i]] ++;
        }
        for (int i = 1; i <= m; i ++)
            if (a[i] < (n + 1) / 2)
                ans *= ifct[box[a[i]]], ans %= mod,
                box[a[i]] = 0;
    }
    for (int i = n / 2 + 1; i < n; i ++)
        ans *= fct[gbox[i]], ans %= mod;
    cout << ans;
    return 0;
}
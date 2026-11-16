#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, mod = 1e9 + 7;
int a[N + 5], v[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
	int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i], s += a[i];
    for (int i = 1; i <= n; i ++) cin >> v[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += fp(2, s - a[i], mod) * (fp(v[i] + 1, a[i], mod) - 1) % mod, ans %= mod; 
    }
    cout << ans;
    return 0;
}
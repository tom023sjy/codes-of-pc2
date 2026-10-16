#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100, mod = 998244353;
int a[N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            for (int k = 0; k <= m; k ++)
                ans += min((a[i] ^ k), (a[j] ^ k)) % mod, ans %= mod;
    cout << ans;
    return 0;
}

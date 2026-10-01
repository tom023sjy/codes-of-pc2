#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
const int N = 200;
int dp[N + 5][N * N + 5];
signed main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= i * (i + 1) / 2; j ++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
                dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= mod - 1;
        }
    int ans = 1;
    for (int i = 1; i <= n * (n + 1) / 2; i ++) {
        ans *= fp(i, dp[n][i], mod), ans %= mod;
        // cerr << dp[n][i] << " ";
    }
    cout << ans;
    return 0;
}

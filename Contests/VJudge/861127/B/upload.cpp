#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5, mod = 998244353;
int a[N + 5];
int s[N + 5], sc[N + 5];
int dp[N + 5], sdp[N + 5];
inline int popcnt(int x) {
    return __builtin_popcountll(x);
}
inline int get(int l, int r) {
    return sc[r] - sc[l - 1] - popcnt(s[r] - s[l - 1]);
}
void solve() {
    memset(s, 0, sizeof s);
    memset(sc, 0, sizeof sc);
    memset(dp, 0, sizeof dp);
    memset(sdp, 0, sizeof sdp);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i],
        sc[i] = sc[i - 1] + popcnt(a[i]);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i ++) {
        while (l < i && get(l, i) > 1) l ++;
        while (r < i && get(r, i) > 0) r ++;
        dp[i] = sdp[r - 1] - sdp[l - 1] + 1;
        dp[i] %= mod, dp[i] += mod, dp[i] %= mod;
        sdp[i] = sdp[i - 1] + dp[i], sdp[i] %= mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += dp[i], ans %= mod;
    cout << ans << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 5000, mod = 998244353;
int a[N + 5], n, dp[N + 5];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = N + 1; j > a[i]; j --)
            ans += dp[j], ans %= mod;
        for (int j = N + 1; j >= N + 1 - a[i]; j --)
            dp[N + 1] += dp[j], dp[N + 1] %= mod;
        for (int j = N; j >= a[i]; j --)
            dp[j] += dp[j - a[i]], dp[j] %= mod;
    }
    cout << ans;
    return 0;
}
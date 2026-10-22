#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], dp[N + 5];
signed main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += a[i], a[i] = x - a[i];
    for (int i = 1; i <= n; i ++) {
        dp[i] = a[i];
        int add = 0;
        for (int j = i - 1; j < i; j ++)
            add = max(add, dp[j]);
        dp[i] += add;
    }
    cout << ans + (*max_element(dp, dp + n + 1));
    return 0;
}
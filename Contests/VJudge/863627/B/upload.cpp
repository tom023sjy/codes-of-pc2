#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int dp[N + 5], a[N + 5], s[N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j < i; j ++) 
            dp[i] = min(dp[i], dp[j] + s[i - 1] - s[j] + abs(a[j - 1] - a[i]));
    cout << dp[n];
    return 0;
}